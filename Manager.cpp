//
//  Manager.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "Manager.h"
#include "Parser.h"
#include "BlurFactory.h"
#include "BlurCommand.h"
#include "Image.h"



Manager::Manager() {
    myCommandFactories = new std::map<std::string, Factory*>;
    myCommandsToExecute = new std::vector<ImageCommand*>;
    instantiateFactories();
};

void Manager::setMyCommandMap(int argc, const char **argv){
    Parser* p = new Parser();
    myCommandMap = p->buildCommandMap(argc, argv);
    imageIn = p->getInputPath();
    imageOut = p->getOutputPath();
}

void Manager::defineFactory(std::string referenceName, Factory* factoryInstance){
    myCommandFactories->insert(std::make_pair(referenceName, factoryInstance));
}

//This is where new Commands are defined.  Simply create a class, a factory for it, and then instantiate a factory here
//referenceName is exactly what will be typed in the commandline. case sensitive.
void Manager::instantiateFactories(){
    defineFactory("Blur", new BlurFactory());
}

bool Manager::isPossibleCommand(std::string referenceName){
    
    return (myCommandFactories->find(referenceName) != myCommandFactories->end());
}

void Manager::queueCommand(std::string referenceName, std::map<std::string,std::string>* flags){
    if (!isPossibleCommand(referenceName)){
        //TODO:perhaps add some error handling here
        return;
    }else{
        Factory* factory = myCommandFactories->at(referenceName);
//        printf("EXECUING BUILD IMAGE COMMAND(FLAGS)\n");
        myCommandsToExecute->push_back(factory->buildImageCommand(flags));
        
    }
}
//TODO: rename myCommandMap perhaps.  Somehow describe that it is the inputs for creating commands
void Manager::buildCommands(){
    commandMap::iterator iter;
    for(iter = myCommandMap->begin(); iter != myCommandMap->end(); iter++){
        std::string comName = iter->first;
        std::map<std::string,std::string>* flags = iter->second;
//        printf("QUEING COMMAND: %s\n", comName.c_str());
        queueCommand(comName, flags);//for some reason this does not work
    }
}

void Manager::run(){

//    Image* image = new Image(imageIn.c_str());
//    Image* image = NULL;
    Image* originalImage = new Image("/Users/srwareham/Desktop/idk.ppm");
    Image* currentImage = originalImage;//TODO: create a copy function
    buildCommands();
    //ImageIO = parser->getInputPath()
    //for command in commands, command->run(currentImage)
//    printf("Commands Built: %d\n", (int) myCommandsToExecute->size());
    for (int i=0; i< myCommandsToExecute->size(); i++){
        ImageCommand* command = myCommandsToExecute->at(i);
        printf("%s\n",command->printMessage().c_str());
        currentImage = command->execute(currentImage);
//        BlurCommand* b = (BlurCommand*) command;
//        b->printMe();
    }
//    currentImage = originalImage;
    currentImage->writeImage("/Users/srwareham/Desktop/outputPPM.ppm");
    
//    image->write(imageOut.c_str());
}


int main(int argc, const char * argv[]){
    Manager* m = new Manager();
    m->setMyCommandMap(argc, argv);
    m->run();
    return EXIT_SUCCESS;
}