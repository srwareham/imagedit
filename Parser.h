//
//  Parser.h
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__Parser__
#define __imagedit__Parser__

#include <iostream>
#include <vector>
#include <string>
#include "References.h"

class Parser {
private:
    std::string myInputPath;
    std::string myOutputPath;
public:
    Parser();
    commandMap* buildCommandMap (int argc, const char * argv[]);
    std::string getInputPath();
    std::string getOutputPath();
};

#endif /* defined(__imagedit__Parser__) */
