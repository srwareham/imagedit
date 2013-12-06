//
//  BilinearScaleFactory.h
//  imagedit
//
//  Created by Sean Wareham on 12/5/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__BilinearScaleFactory__
#define __imagedit__BilinearScaleFactory__

#include <iostream>
#include "Factory.h"

class BilinearScaleFactory : public Factory {
public:
    BilinearScaleFactory();
    ImageCommand* buildImageCommand(std::map<std::string, std::string>* flagMap);
    
};

#endif /* defined(__imagedit__BilinearScaleFactory__) */
