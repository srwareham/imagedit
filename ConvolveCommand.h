//
//  ConvolveCommand.h
//  imagedit
//
//  Created by Sean Wareham on 12/4/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__ConvolveCommand__
#define __imagedit__ConvolveCommand__

#include <iostream>
#include <string>
#include "ImageCommand.h"
#include "Filter.h"

class ConvolveCommand : public ImageCommand {
private:
    std::string myFilterType;
    int myFilterR;
    Image* convolveSeperable(Image* image, Filter* f);
    Image* convolveNonSeperable(Image* image, Filter* f);
public:
    Image* execute(Image* image);
    ConvolveCommand(std::string filterType, int filterR);
    std::string getStartMessage();
    std::string getEndMessage();
};

#endif /* defined(__imagedit__ConvolveCommand__) */
