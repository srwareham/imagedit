//
//  Parser.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.

#include "Parser.h"

Parser::Parser() {
};

std::map<std::string, std::string>* Parser::buildFlagMap(std::vector<std::string> flagPairs){
    std::map<std::string, std::string>* flags = new std::map<std::string, std::string>();
    if (flagPairs.size() <= 1){
        return flags;
    }
    int i = 1;
    while (i < (int) flagPairs.size()-1){
        std::string flagName = flagPairs.at(i);
        std::string flagVal = flagPairs.at(i+1);
        flags->insert(std::make_pair(flagName, flagVal));
        i +=2;
    }
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

    //i =0 is just the name of this program. We dont need this.
    myInputPath = allArgs.at(1);
    myOutputPath = allArgs.at(2);
    //std::map<std::string, std::map<std::string, std::string>*>
    commandMap* allCommands = new commandMap();
    
    std::vector<int> commaIndexArray;
    
    for (int i =3; i< allArgs.size(); i++){
        if (allArgs.at(i) == ","){
            commaIndexArray.push_back(i);
            
        }
    }
    
    
    for (int i=0; i<= commaIndexArray.size();i++){
        int startIndex;
        int endIndex;
        //if we are at the beginning, we know the first commandName is after "imageditPath in out"
        if (i ==0){
            startIndex = 3;
            //otherwise it is right after a comma
        } else {
            startIndex = commaIndexArray.at(i-1) +1;
        }
        //if this is the last comma, the
        if (i == commaIndexArray.size()){
            endIndex = (int) allArgs.size();
        } else {
            endIndex = commaIndexArray.at(i);
        }
  
        std::string commandName = allArgs.at(startIndex) + std::to_string(i);
        std::vector<std::string> commandArgs = subString(startIndex, endIndex, allArgs);
        allCommands->insert(std::make_pair(commandName, buildFlagMap(commandArgs)));
    }

    hasBeenParsed = true;
    
    //super janky patch so single argument commands will usually work.  Was not part of original design consideration...but it works (without batch mode)!
    if (allArgs.size() == 5){
        commandMap* patchMap = new commandMap();
        std::map<std::string,std::string>* nested = new std::map<std::string,std::string>();
        nested->insert(std::make_pair(allArgs.at(4), ""));//the sole parameter
        patchMap->insert(std::make_pair(allArgs.at(3), nested));// the commands name
        allCommands = patchMap;
    }
    
    
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