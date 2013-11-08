//
//  BlurCommand.h
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__BlurCommand__
#define __imagedit__BlurCommand__

#include <iostream>
#include <string>
#include "Interface_ImageCommand.h"

class BlurCommand : public Interface_ImageCommand {
private:
    std::string myFilterType;
    int myFilterR;
public:
    void OverrideMe();
    BlurCommand(std::string filterType, int filterR);
};


#endif /* defined(__imagedit__BlurCommand__) */
