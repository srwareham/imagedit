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

class Factory {
protected:
public:
    virtual void OverrideMe() = 0;
    virtual ~Factory();
};

#endif /* defined(__imagedit__Factory__) */
