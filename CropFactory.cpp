//
//  CropFactory.cpp
//  imagedit
//
//  Created by Sean Wareham on 12/6/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "CropFactory.h"
#include "CropCommand.h"

CropFactory::CropFactory(){};


ImageCommand* CropFactory::buildImageCommand(std::map<std::string, std::string>* flagMap){
    int top = 0, bottom =0 , left = 0, right =0;
    
    std::map<std::string, std::string>::iterator iter;
    for (iter = flagMap ->begin(); iter != flagMap ->end(); ++iter) {
        //        printf("test\n");
        if (iter ->first == "-top"){
            top = atoi(iter ->second.c_str());
        }
        if (iter ->first == "-bottom"){
            bottom = atoi(iter ->second.c_str());
        }
        if (iter ->first == "-right"){
            right = atoi(iter ->second.c_str());
        }
        if (iter ->first == "-left"){
            left = atoi(iter ->second.c_str());
        }
        
    }
    
    return new CropCommand(top, bottom, left, right);
}