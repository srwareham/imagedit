//
//  main.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include <iostream>
#include "Parser.h"
#include "Manager.h"
#include "BlurCommand.h"

int main(int argc, const char * argv[])
{

    
//    std::map<char *, Interface_ImageCommand*> commands;
//    commands["RemoveRedCommand"] = new RemoveRedCommand();
    Manager* m = new Manager();
    
    Parser* p = new Parser();
    
    m->setMyCommandMap(p, argc, argv);
    
//    BlurCommand* b = new BlurCommand("box", 10);
//    b->setFlag("f", "val");
    
    return 0;
}

