//
//  Manager.h
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__Manager__
#define __imagedit__Manager__

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Interface_ImageCommand.h"


class Manager {
private:
    //A prebuilt instance of every possible command. A little silly to actually instantiate every possible
    //but this way avoid the need for a factory for each.  Makes it much easier to add a new command.
    //Never going to have enough commands that this could even remotely be a real issue.
    std::map<std::string, Interface_ImageCommand*>* myPossibleCommands;
    std::vector<Interface_ImageCommand*>* myActiveCommands;
    void buildMyPossibleCommands();
    void addPossibleCommand(std::string referenceName, Interface_ImageCommand* commandInstance);
public:
    Manager(void);
    bool isPossibleCommand(std::string referenceName);
    Interface_ImageCommand* activateReferencedCommand(std::string referenceName);
};

#endif /* defined(__imagedit__Manager__) */


