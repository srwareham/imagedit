//
//  BilinearScaleFactory.cpp
//  imagedit
//
//  Created by Sean Wareham on 12/5/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "BilinearScaleFactory.h"
#include "BilinearScaleCommand.h"


BilinearScaleFactory::BilinearScaleFactory(){};


ImageCommand* BilinearScaleFactory::buildImageCommand(std::map<std::string, std::string>* flagMap){
    double scalingPercentage = 100.0;
    int width;
    int height;
    
    //need both or default to a percentage of 100 (ie do nothing)
    bool haveH = false;
    bool haveW = false;
    
    std::map<std::string, std::string>::iterator iter;
    for (iter = flagMap->begin(); iter != flagMap->end(); ++iter) {
        //        printf("test\n");
        if (iter->first == "-p"){
            scalingPercentage = atof(iter->second.c_str());
        }
        
        //TODO: perhaps add an error handling mechanism
        if (iter->first == "-w") {
            width = atoi(iter->second.c_str());
            haveW = true;
        }
        if (iter->first == "-h"){
            height = atoi(iter->second.c_str());
            haveH = true;
        }
    }
    
    if (haveH && haveW){
        return new BilinearScaleCommand(height, width);
    }else{
        //is either the properly formatted value (no error handling) or the default of 100
        return new BilinearScaleCommand(scalingPercentage);
    }
}