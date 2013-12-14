//
//  FlipCommand.h
//  imagedit
//
//  Created by Sean Wareham on 12/14/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__FlipCommand__
#define __imagedit__FlipCommand__

#include <iostream>
#include "ImageCommand.h"

class FlipCommand : public ImageCommand {
private:
    std::string myAxis;
public:
    Image* execute(Image* image);
    FlipCommand(std::string axis);
    std::string getStartMessage();
    std::string getEndMessage();
};

#endif /* defined(__imagedit__FlipCommand__) */
