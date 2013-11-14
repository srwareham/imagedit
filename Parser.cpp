//
//  Parser.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//TODO: make it so commands do not need a terminating comma.

#include "Parser.h"

Parser::Parser() {
};

std::map<std::string, std::string>* Parser::buildFlagMap(std::vector<std::string> flagPairs){
        printf("flagpairs SIZE: %d\n", (int) flagPairs.size());
    std::map<std::string, std::string>* flags = new std::map<std::string, std::string>();
    if (flagPairs.size() <= 1){
        printf("MADE MAP OF SIZE: %d\n", (int)flags->size());
        return flags;
    }
    int i = 1;
    while (i < (int) flagPairs.size()-1){
        printf("I = %d\n", i);
        std::string flagName = flagPairs.at(i);
        std::string flagVal = flagPairs.at(i+1);
        printf("FlagName: %s flagVal: %s\n", flagName.c_str(), flagVal.c_str());
        flags->insert(std::make_pair(flagName, flagVal));
        i +=2;
    }
    printf("MADE MAP OF SIZE: %d\n", (int)flags->size());
    return flags;
}

std::vector<std::string> Parser::subString(int start, int end, std::vector<std::string> inputVector){
    std::vector<std::string> ans(inputVector.begin() + start, inputVector.begin() + end);
    return ans;
}


commandMap* Parser::buildCommandMap(int argc, const char * argv[]){
    //Every command at least needs  an inputFile, an outputFile, and a commandName
    if (argc <3){
        printf("INSUFFICIENT ARGS!\n");
        //TODO: perhaps do something more sophisticated than dump
        exit(EXIT_FAILURE);
    }
    
    
    std::vector<std::string> allArgs(argv, argv + argc);
//    printf("in: %s\n", allArgs.at(1).c_str());
//    printf("out: %s\n", allArgs.at(2).c_str());
    
    //i =0 is just the name of this program. We dont need this.
    myInputPath = allArgs.at(1);
    myOutputPath = allArgs.at(2);
    //std::map<std::string, std::map<std::string, std::string>*>
    commandMap* allCommands = new commandMap();
    
    std::vector<int> commaIndexArray;
    
    for (int i =3; i< allArgs.size(); i++){
        if (allArgs.at(i) == ","){
            printf("COMMA AT: %d\n", i);
            commaIndexArray.push_back(i);
            
        }
    }
    
    
    for (int i=0; i< commaIndexArray.size();i++){
        int startIndex;
        int endIndex;
        
        if (i ==0){
            startIndex = 3;
        } else {
            startIndex = commaIndexArray.at(i-1) +1;
        }
        if (i == commaIndexArray.size()){
            endIndex = (int) allArgs.size();
        } else {
            endIndex = commaIndexArray.at(i);
        }
        std::string commandName = allArgs.at(startIndex);
        std::vector<std::string> commandArgs = subString(startIndex, endIndex, allArgs);
        allCommands->insert(std::make_pair(commandName, buildFlagMap(commandArgs)));
    }

    printf("allcommands size: %d\n", (int) allCommands->size());

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