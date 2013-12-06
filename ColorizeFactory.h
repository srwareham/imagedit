//
//  ColorizeFactory.h
//  imagedit
//
//  Created by Sean Wareham on 12/5/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__ColorizeFactory__
#define __imagedit__ColorizeFactory__

#include <iostream>
#include "Factory.h"

class ColorizeFactory : public Factory {
public:
    ColorizeFactory();
    ImageCommand* buildImageCommand(std::map<std::string, std::string>* flagMap);
    
};

#endif /* defined(__imagedit__ColorizeFactory__) */
