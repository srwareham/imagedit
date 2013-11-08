//
//  Parser.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "Parser.h"

Parser::Parser() {
};

commandMap* Parser::buildCommandMap(int argc, const char * argv[]){
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
    myInputPath = allArgs.at(1);
    myOutputPath = allArgs.at(2);
    //std::map<std::string, std::map<std::string, std::string>*>
    commandMap* allCommands = new commandMap();
    
    std::vector<int> commandIndicies;
    //prev is the index of the first command, and then every ensuing command
    int prev = 3;
    for (int index = prev; index < argc; index++) {
        std::string arg = allArgs.at(index);
        printf("val: %s\n", arg.c_str());
        if (arg == ","){
            std::map<std::string, std::string>* flags = new std::map<std::string, std::string>();
            std::string commandName = allArgs.at(prev);
            int i = prev + 1;
                while (i < index){
                    std::string flagName = allArgs.at(i);
                    std::string flagVal = allArgs.at(i);
                    flags->insert(std::make_pair(flagName, flagVal));
                    index +=2;
                }
            prev = index +1;
            allCommands->insert(std::make_pair(commandName, flags));
        }
    }

    hasBeenParsed = true;
    return allCommands;
}

//NOTE: for both of these functions, buildCommandMap MUST be run first!
std::string Parser::getInputPath(){
    if (hasBeenParsed){
        return myInputPath;
    }
    //TODO: probably want better error handling
    return "UNPARSED";
}
std::string Parser::getOutputPath(){
    if (hasBeenParsed){
        return myOutputPath;
    }
    return "UNPARSED";
}