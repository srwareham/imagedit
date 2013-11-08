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
    //Every command at least needs  an inputFile, an outputFile, and a commandName
    if (argc <3){
        printf("INSUFFICIENT ARGS!\n");
        //TODO: perhaps do something more sophisticated than dump
        exit(EXIT_FAILURE);
    }
    
    
    std::vector<std::string> allArgs(argv, argv + argc);
    //i =0 is just the name of this program. We dont need this.
    std::string in = allArgs.at(1);
    std::string out = allArgs.at(2);
    for (int i =3; i< argc; i++){
        std::string something = allArgs.at(i);
        printf("val: %s\n", something.c_str());
        
    }

    
    
    
    
    
    
    
    
    std::vector<int>* myWeights = new std::vector<int>();
    return myWeights;
}