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
    //input and output file paths
    const char * in;
    const char * out;
    
    in = argv[1];
    out = argv[2];
    
    int index = 3;
    while (index < argc){
        const char * arg = argv[index];
        
        index+=2;
    }

    
    std::vector<int>* myWeights = new std::vector<int>();
    
    printf("Parsing: |__");
    for (int i = 0; i < argc; i++){
        printf("%s__ ",argv[i]);
    }
    printf("|\n)");
    
    
    
    return myWeights;
}