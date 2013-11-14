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
#include <map>
#include "References.h"

class Parser {
private:
    bool hasBeenParsed = false;
    std::string myInputPath;
    std::string myOutputPath;
public:
    Parser();
    std::vector<std::string> subString(int start, int end, std::vector<std::string> inputVector);
    std::map<std::string, std::string>* buildFlagMap(std::vector<std::string> flagPairs);
    commandMap* buildCommandMap (int argc, const char * argv[]);
    std::string getInputPath();
    std::string getOutputPath();
};

#endif /* defined(__imagedit__Parser__) */
