//
//  main.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include <iostream>
#include "Parser.h"
#include "Interface_ImageComand.h"
#include "RemoveRedCommand.h"
#include <map>

int main(int argc, const char * argv[])
{

    
    std::map<char *, Interface_ImageCommand*> commands;
    commands["RemoveRedCommand"] = new RemoveRedCommand();
    
    
    Parser* p = new Parser();
    p->parse(argc, argv);
    return 0;
}

