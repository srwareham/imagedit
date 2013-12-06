//
//  ConvolveFactory.cpp
//  imagedit
//
//  Created by Sean Wareham on 12/4/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "ConvolveFactory.h"
#include "ConvolveCommand.h"


ConvolveFactory::ConvolveFactory(){};


ImageCommand* ConvolveFactory::buildImageCommand(std::map<std::string, std::string>* flagMap){
    std::string filterType = "Box";
    int filterR = 2;
    
    std::map<std::string, std::string>::iterator iter;
    for (iter = flagMap->begin(); iter != flagMap->end(); ++iter) {
        if (iter->first == "-filter"){
            filterType = iter->second;
        }
        
        //TODO: perhaps add an error handling mechanism
        if (iter->first == "-r") {
            filterR = atoi(iter->second.c_str());
        }
    }
    
    return new ConvolveCommand(filterType, filterR);
}

