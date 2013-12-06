//
//  CommandManager.h
//  imagedit
//
//  Created by Sean Wareham on 12/5/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__CommandManager__
#define __imagedit__CommandManager__

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Factory.h"
#include "References.h"

class CommandManager {
private:
    std::map<std::string, Factory*>* myCommandFactories;
    bool is_number(const std::string& s);// sourced from: stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
    bool isPossibleCommand(std::string referenceName);
    std::string cleanName(std::string referenceName);
    void queueCommand(std::string referenceName, std::map<std::string,std::string>* flags, std::vector<ImageCommand*>* commandsToExecute);
public:
    CommandManager(std::map<std::string, Factory*>* commandFactories);
    //commandMap is defined in References.h
    std::vector<ImageCommand*>* getCommandsToExecute(commandMap* commandMap);
};


#endif /* defined(__imagedit__CommandManager__) */
