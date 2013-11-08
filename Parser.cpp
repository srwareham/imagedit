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
    std::vector<int>* myWeights = new std::vector<int>();
    printf("Parsing: |__");
    for (int i = 0; i < argc; i++){
        printf("%s__ ",argv[i]);
    }
    printf("|\n)");
    return myWeights;
}