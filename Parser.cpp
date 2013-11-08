//
//  Parser.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "Parser.h"

Parser::Parser() {};

std::vector<int>* Parser::parse(int argc, const char * argv[]){
    
    std::vector<std::string> allArgs(argv, argv + argc);
    
    std::string in;
    std::string out;
    //i =0 is just the name of this program. We dont need this.
    for (int i =1; i< argc; i++){
        std::string something = allArgs.at(i);
        printf("val: %s\n", something.c_str());
        
    }

    
    
    
    
    
    
    
    
    std::vector<int>* myWeights = new std::vector<int>();
    return myWeights;
}