//
//  Manager.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include <ctime>
#include "Manager.h"
#include "Parser.h"
#include "Image.h"
#include "FactoryManager.h"
#include "CommandManager.h"



Manager::Manager(int argc, const char * argv[]) {
    //gather the factories necessary for constructing commands
    FactoryManager* fm = new FactoryManager();
    
    //Parse and construct commands
    CommandManager* cm = new CommandManager(fm->getFactories());
    Parser* p = new Parser();
    myCommandsToExecute = cm->getCommandsToExecute(p->buildCommandMap(argc, argv));
    
    
    //Define input and outputPaths
    //these MUST be called after p->buildCommandMap
    myImageIn = p->getInputPath();
    myImageOut = p->getOutputPath();
};

//Begin executing the commands
void Manager::run(){
    //load the desired image
    Image* originalImage = new Image(myImageIn.c_str());//("/Users/srwareham/Desktop/idk.ppm");
    Image* currentImage = originalImage;
    
    //apply all necessary transformations in the sequence they were specified
    for (int i=0; i< myCommandsToExecute->size(); i++){
        ImageCommand* command = myCommandsToExecute->at(i);
        printf("%s\n",command->getStartMessage().c_str());
        clock_t start = clock();
        currentImage = command->execute(currentImage);
        clock_t end = clock();
        printf("%s\n",command->getEndMessage().c_str());
        printf("In %f seconds\n", (double) ((end - start)/CLK_TCK/1000.0));
    }
    clock_t start = clock();
    currentImage->writeImage(myImageOut.c_str());
    clock_t end = clock();

    printf("Wrote \"%s\" in %f seconds\n", myImageOut.c_str(), (double) ((end - start)/CLK_TCK/1000.0) );
}


int main(int argc, const char * argv[]){
    Manager* m = new Manager(argc, argv);
    m->run();
    return EXIT_SUCCESS;
}