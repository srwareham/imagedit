//
//  Interface_ImageComand.h
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__Interface_ImageComand__
#define __imagedit__Interface_ImageComand__

#include <iostream>
#include <map>
#include <string>
#include "Image.h"

class ImageCommand {
protected:
    
public:
    virtual void execute(Image* image) = 0;
    virtual ~ImageCommand();
};

#endif /* defined(__imagedit__Interface_ImageComand__) */
