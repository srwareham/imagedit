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

bool CommandManager::is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

bool CommandManager::isPossibleCommand(std::string referenceName){
    return (myCommandFactories->find(referenceName) != myCommandFactories->end());
}

std::string CommandManager::cleanName(std::string referenceName){
    std::string ans;
    
    bool foundint = false;
    int index = 0;
    while (!foundint && index < referenceName.size()){
        std::string letter = referenceName.substr(index, index+1);
        if (is_number(letter)){
            foundint = true;
            break;
        }
        index++;
    }
    
    ans = referenceName.substr(0,index);
    return ans;
}

void CommandManager::queueCommand(std::string referenceName, std::map<std::string,std::string>* flags, std::vector<ImageCommand*>* commandsToExecute){
    std::string cName = cleanName(referenceName);
    if (!isPossibleCommand(cleanName(cName))){
        //TODO:perhaps add some error handling here
        return;
    }else{
        Factory* factory = myCommandFactories->at(cName);
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

