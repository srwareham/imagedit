//
//  ApplyDiscreteFilterCommand.h
//  imagedit
//
//  Created by Sean Wareham on 11/23/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__ApplyDiscreteFilterCommand__
#define __imagedit__ApplyDiscreteFilterCommand__

#include <iostream>
#include <string>
#include "ImageCommand.h"

class ApplyDiscreteFilterCommand : public ImageCommand {
private:
    std::string myFilterType;
    int myFilterR;
public:
    Image* execute(Image* image);
    ApplyDiscreteFilterCommand(void);
    std::string printMessage();
};

#endif /* defined(__imagedit__ApplyDiscreteFilterCommand__) */
