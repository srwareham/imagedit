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
    bool notRGB = false;
    std::string desiredEffect = "-grayscale";
    
    std::set<std::string> s;
    s.insert("-negative");
    s.insert("-grayscale");
    s.insert("-removered");

    //if we are using a preset
//    if (flagMap->size() ==1){
//        //default grayscale
//        
//        
//        //this purposedly only supports 1 argument
//        std::map<std::string, std::string>::iterator iter;
//        for (iter = flagMap->begin(); iter != flagMap->end(); ++iter) {
//            //if the desiredEffect is one of the defined effects
//            if (s.find(iter->first) != s.end()){
//                desiredEffect = iter->first;
//            }
//            //if multiple colorEffects were input, only the first will be applied
//        }
//        return new ColorizeCommand(desiredEffect);
//        
//        
//    }else{
        //default do nothing
        double redBias = 1.0 , blueBias = 1.0, greenBias = 1.0;
        
        std::map<std::string, std::string>::iterator iter;
        for (iter = flagMap->begin(); iter != flagMap->end(); ++iter) {
                    printf("%s\n",iter->first.c_str());
            if (iter->first == "-r"){
                redBias = atof(iter->second.c_str())/100.0;
            }
            if (iter->first == "-g") {
                greenBias = atof(iter->second.c_str())/100.0;
            }
            if (iter->first == "-b") {
                blueBias = atof(iter->second.c_str())/100.0;
            }
            
            if (s.find(iter->first) != s.end()){
                desiredEffect = iter->first;
                notRGB = true;
            }
            
            
            
        }
        if (notRGB){
            printf("tryin this\n");
            return new ColorizeCommand(desiredEffect);
        }
        
        
        return new ColorizeCommand(redBias, greenBias, blueBias);
        
//    }

}