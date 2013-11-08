//
//  main.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include <iostream>
#include "Parser.h"

int main(int argc, const char * argv[])
{

//    printf();
    // insert code here...
    std::cout << "Hello, World!\n";
    Parser* p = new Parser();
    p->parse(argc, argv);
    return 0;
}

