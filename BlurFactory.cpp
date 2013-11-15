//
//  BlurFactory.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/8/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "BlurFactory.h"


BlurFactory::BlurFactory(){};


ImageCommand* BlurFactory::buildImageCommand(std::map<std::string, std::string>* flagMap){
    std::string filterType = "Box";
    int filterR = 10;
    printf("insidebuildimagecommand\n");
    
    
    std::map<std::string, std::string>::iterator iter;
    for (iter = flagMap->begin(); iter != flagMap->end(); ++iter) {
        printf("test\n");
        if (iter->first == "-filter"){
            filterType = iter->second;
        }
        
        //TODO: perhaps add an error handling mechanism
        if (iter->first == "-r") {
            filterR = atoi(iter->second.c_str());
            printf("FilterR: %s\n", iter->second.c_str());
        }
    }
    
    return new BlurCommand(filterType, filterR);
}

