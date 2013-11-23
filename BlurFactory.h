//
//  BlurFactory.h
//  imagedit
//
//  Created by Sean Wareham on 11/8/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__BlurFactory__
#define __imagedit__BlurFactory__

#include <iostream>
#include "BlurCommand.h"
#include <string>
#include <map>
#include <string>
#include "Factory.h"

class BlurFactory : public Factory {
public:
    BlurFactory();
    ImageCommand* buildImageCommand(std::map<std::string, std::string>* flagMap);
    
};

#endif /* defined(__imagedit__BlurFactory__) */
