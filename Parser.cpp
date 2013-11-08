//
//  Parser.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "Parser.h"

Parser::Parser(Manager* manager) {
    myManager = manager;
};

std::vector<int>* Parser::parse(int argc, const char * argv[]){
    //Every command at least needs  an inputFile, an outputFile, and a commandName
    if (argc <3){
        printf("INSUFFICIENT ARGS!\n");
        //TODO: perhaps do something more sophisticated than dump
        exit(EXIT_FAILURE);
    }
    
    
    std::vector<std::string> allArgs(argv, argv + argc);
    printf("in: %s\n", allArgs.at(1).c_str());
    printf("out: %s\n", allArgs.at(2).c_str());
    
    //i =0 is just the name of this program. We dont need this.
    std::string in = allArgs.at(1);
    std::string out = allArgs.at(2);
    
    std::vector<int> commandIndicies;
    int index = 3;
    while(index < argc) {
        std::string arg = allArgs.at(index);
        printf("val: %s\n", arg.c_str());
        
//        if (myManager->isPossibleCommand(arg)) {
//            commandIndicies.push_back(index);
//            index +=2;
//        }
        
        index ++;
        
    }

    
    
    
    
    
    
    
    
    std::vector<int>* myWeights = new std::vector<int>();
    return myWeights;
}