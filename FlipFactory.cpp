//
//  FlipFactory.cpp
//  imagedit
//
//  Created by Sean Wareham on 12/14/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "FlipFactory.h"
#include "FlipCommand.h"
#include <set>

FlipFactory::FlipFactory() {};


ImageCommand* FlipFactory::buildImageCommand(std::map<std::string, std::string>* flagMap){
    std::string axis = "x";
    std::set<std::string> s;
    s.insert("x");
    s.insert("y");
    
    std::map<std::string, std::string>::iterator iter;
    for (iter = flagMap ->begin(); iter != flagMap ->end(); ++iter) {
        //        printf("test\n");
        if (iter ->first == "-axis"){
            if (s.find(iter->second) != s.end()){
                axis = iter->second;
            }
        }
    }
    
    return new FlipCommand(axis);
}