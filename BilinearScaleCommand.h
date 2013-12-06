//
//  BilinearScaleCommand.h
//  imagedit
//
//  Created by Sean Wareham on 12/4/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__BilinearScaleCommand__
#define __imagedit__BilinearScaleCommand__

#include <iostream>
#include "ImageCommand.h"

class BilinearScaleCommand : public ImageCommand {
private:
    int myNewH, myNewW;
    double scaleByPercent = -1;//must be positive to be valid
    double newPixelValue(double p00, double p01, double p10, double p11);
public:
    Image* execute(Image* image);
    BilinearScaleCommand(int newH, int newW);
    BilinearScaleCommand(double percent);
    std::string getStartMessage();
    std::string getEndMessage();
};

#endif /* defined(__imagedit__BilinearScaleCommand__) */
