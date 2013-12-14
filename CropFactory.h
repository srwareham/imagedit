//
//  CropFactory.h
//  imagedit
//
//  Created by Sean Wareham on 12/6/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__CropFactory__
#define __imagedit__CropFactory__

#include <iostream>
#include "Factory.h"

class CropFactory : public Factory {
    public:
    CropFactory();
    ImageCommand* buildImageCommand(std::map<std::string, std::string>* flagMap);
    
};

#endif /* defined(__imagedit__CropFactory__) */