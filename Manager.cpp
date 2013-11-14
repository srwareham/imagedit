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



Manager::Manager() {
    myCommandFactories = new std::map<std::string, Factory*>;
    myCommandsToExecute = new std::vector<ImageCommand*>;
    instantiateFactories();
};

void Manager::setMyCommandMap(int argc, const char **argv){
    Parser* p = new Parser();
    myCommandMap = p->buildCommandMap(argc, argv);
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
        //TODO: not sure this is the correct way to access a map
        Factory* factory = myCommandFactories->at(referenceName);
        myCommandsToExecute->push_back(factory->buildImageCommand(flags));
        
    }
}
//TODO: rename myCommandMap perhaps.  Somehow describe that it is the inputs for creating commands
void Manager::buildCommands(){
    commandMap::iterator iter;
    for(iter = myCommandMap->begin(); iter != myCommandMap->end(); iter++){
        std::string comName = iter->first;
        std::map<std::string,std::string>* flags = iter->second;
        queueCommand(comName, flags);//for some reason this does not work
    }
    
        
    
}

void Manager::run(){
    buildCommands();
    //ImageIO = parser->getInputPath()
    //for command in commands, command->run(currentImage)
//    printf("Commands Built: %d\n", (int) myCommandsToExecute->size());
    for (int i=0; i< myCommandsToExecute->size(); i++){
        ImageCommand* command = myCommandsToExecute->at(i);
        BlurCommand* b = (BlurCommand*) command;
        b->printMe();
    }
    
    //ImageIO->write(parser->getOutputPath()
}


int main(int argc, const char * argv[]){
    Manager* m = new Manager();
    m->setMyCommandMap(argc, argv);
    m->run();
    return EXIT_SUCCESS;
}