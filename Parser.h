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
public:
    Parser();
    commandMap* parse (int argc, const char * argv[]);
};

#endif /* defined(__imagedit__Parser__) */
