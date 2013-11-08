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

class BlurFactory : Factory {
public:
    BlurFactory();
    BlurCommand* createBlurCommand(std::map<std::string, std::string> flagMap);
    void OverrideMe();
    
};

#endif /* defined(__imagedit__BlurFactory__) */
