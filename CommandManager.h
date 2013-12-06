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
    
    bool isPossibleCommand(std::string referenceName);
    void queueCommand(std::string referenceName, std::map<std::string,std::string>* flags, std::vector<ImageCommand*>* commandsToExecute);
public:
    CommandManager(std::map<std::string, Factory*>* commandFactories);
    std::vector<ImageCommand*>* getCommandsToExecute(commandMap* commandMap);
};


#endif /* defined(__imagedit__CommandManager__) */
