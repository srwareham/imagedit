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
#include "Interface_ImageCommand.h"


class Manager {
private:
    std::map<std::string, Interface_ImageCommand*>* myCommands;
    
public:
    Manager(void);
    void addCommand(std::string referenceName, Interface_ImageCommand* commandInstance);
    bool isACommand(std::string referenceName);
    Interface_ImageCommand* getReferencedCommand(std::string referenceName);
};

#endif /* defined(__imagedit__Manager__) */


