//
//  Factory.h
//  imagedit
//
//  Created by Sean Wareham on 11/8/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__Factory__
#define __imagedit__Factory__

#include <iostream>
#include <string>
#include <map>
#include "ImageCommand.h"


class Factory {
protected:
public:
    virtual ImageCommand* buildImageCommand(std::map<std::string, std::string> flagMap) = 0;
    virtual ~Factory();
};

#endif /* defined(__imagedit__Factory__) */
