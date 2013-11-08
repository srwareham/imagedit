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
    
    
    std::map<std::string, std::string>::iterator iter;
    for (iter = flagMap->begin(); iter != flagMap->end(); ++iter) {
        if (iter->first == "-filter"){
            filterType = iter->second;
        }
        
        //TODO: perhaps add an error handling mechanism
        if (iter->first == "-n") {
            filterR = atoi(iter->second.c_str());
        }
    }
    
    return new BlurCommand(filterType, filterR);
}

