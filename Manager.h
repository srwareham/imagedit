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
#include <string>
#include <vector>
#include "Parser.h"
#include "ImageCommand.h"


class Manager {
private:
    std::vector<ImageCommand*>* myCommandsToExecute;
    std::string imageIn;
    std::string imageOut;
public:
    Manager(int argc, const char * argv[]);
    void run();
    
};

#endif /* defined(__imagedit__Manager__) */


