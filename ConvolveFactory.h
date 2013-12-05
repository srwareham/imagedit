//
//  ConvolveFactory.h
//  imagedit
//
//  Created by Sean Wareham on 12/4/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__ConvolveFactory__
#define __imagedit__ConvolveFactory__

#include <iostream>
#include "ConvolveCommand.h"
#include <string>
#include <map>
#include <string>
#include "Factory.h"

class ConvolveFactory : public Factory {
public:
    ConvolveFactory();
    ImageCommand* buildImageCommand(std::map<std::string, std::string>* flagMap);
    
};

#endif /* defined(__imagedit__ConvolveFactory__) */
