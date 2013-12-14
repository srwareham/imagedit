//
//  FlipFactory.h
//  imagedit
//
//  Created by Sean Wareham on 12/14/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__FlipFactory__
#define __imagedit__FlipFactory__

#include <iostream>
#include "Factory.h"

class FlipFactory : public Factory {
public:
    FlipFactory();
    ImageCommand* buildImageCommand(std::map<std::string, std::string>* flagMap);
    
};

#endif /* defined(__imagedit__FlipFactory__) */
