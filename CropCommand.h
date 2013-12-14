//
//  CropCommand.h
//  imagedit
//
//  Created by Sean Wareham on 12/6/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__CropCommand__
#define __imagedit__CropCommand__

#include <iostream>
#include "ImageCommand.h"

class CropCommand : public ImageCommand {
private:
    int top, bottom, left, right;
    void checkAndFixBounds(int origWidth, int origHeight);
public:
    Image* execute(Image* image);
    CropCommand(int top, int bottom, int left, int right);
    std::string getStartMessage();
    std::string getEndMessage();
};

#endif /* defined(__imagedit__CropCommand__) */