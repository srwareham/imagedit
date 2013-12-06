//
//  Manager.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

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
    imageIn = p->getInputPath();
    imageOut = p->getOutputPath();
};

//Begin executing the commands
void Manager::run(){
    //load the desired image
    Image* originalImage = new Image(imageIn.c_str());//("/Users/srwareham/Desktop/idk.ppm");
    Image* currentImage = originalImage;
    
    //apply all necessary transformation in the sequence they were specified
    for (int i=0; i< myCommandsToExecute->size(); i++){
        ImageCommand* command = myCommandsToExecute->at(i);
        printf("%s\n",command->getStartMessage().c_str());
        currentImage = command->execute(currentImage);
        printf("%s\n",command->getEndMessage().c_str());
    }
    currentImage->writeImage(imageOut.c_str());
}


int main(int argc, const char * argv[]){
    Manager* m = new Manager(argc, argv);
    m->run();
    return EXIT_SUCCESS;
}