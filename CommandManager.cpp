//
//  CommandManager.cpp
//  imagedit
//
//  Created by Sean Wareham on 12/5/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "CommandManager.h"

CommandManager::CommandManager(std::map<std::string, Factory*>* commandFactories){
    myCommandFactories = commandFactories;
}

bool CommandManager::isPossibleCommand(std::string referenceName){
    
    return (myCommandFactories->find(referenceName) != myCommandFactories->end());
}

void CommandManager::queueCommand(std::string referenceName, std::map<std::string,std::string>* flags, std::vector<ImageCommand*>* commandsToExecute){
    if (!isPossibleCommand(referenceName)){
        //TODO:perhaps add some error handling here
        return;
    }else{
        Factory* factory = myCommandFactories->at(referenceName);
        commandsToExecute->push_back(factory->buildImageCommand(flags));
        
    }
}


std::vector<ImageCommand*>* CommandManager::getCommandsToExecute(commandMap* commandMap){
    std::vector<ImageCommand*>* commandsToExecute = new std::vector<ImageCommand*>();
    commandMap::iterator iter;
    for(iter = commandMap->begin(); iter != commandMap->end(); iter++){
        std::string comName = iter->first;
        std::map<std::string,std::string>* flags = iter->second;
        queueCommand(comName, flags, commandsToExecute);
    }
    
    return commandsToExecute;
}

