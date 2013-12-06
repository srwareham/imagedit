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
#include "Factory.h"
#include "References.h"
#include "Parser.h"


class Manager {
    //(command referenceName, map<CommandFlag,flagVal>)
//    typedef std::map<std::string, std::map<std::string, std::string>> commandMap;
private:
    std::vector<ImageCommand*>* myCommandsToExecute;
    commandMap* myCommandMap;
    std::string imageIn;
    std::string imageOut;
public:
    Manager(int argc, const char * argv[]);
    void run();
    
};

#endif /* defined(__imagedit__Manager__) */


