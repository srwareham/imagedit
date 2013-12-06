//
//  ColorizeFactory.cpp
//  imagedit
//
//  Created by Sean Wareham on 12/5/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "ColorizeFactory.h"
#include "ColorizeCommand.h"
#include <set>

ColorizeFactory::ColorizeFactory(){};

ImageCommand* ColorizeFactory::buildImageCommand(std::map<std::string, std::string>* flagMap){
    //default effect
   std::string desiredEffect = "-grayscale";
    
    std::set<std::string> s;
    s.insert("-sepia");
    s.insert("-grayscale");
    s.insert("-removered");

    //this purposedly only supports 1 argument
    std::map<std::string, std::string>::iterator iter;
    for (iter = flagMap->begin(); iter != flagMap->end(); ++iter) {
        //if the desiredEffect is one of the defined effects
        if (s.find(iter->first) != s.end()){
            desiredEffect = iter->first;
        }
        //if multiple colorEffects were input, only the first will be applied
    }
    return new ColorizeCommand(desiredEffect);
}