//
//  ApplyFilterCommand.h
//  imagedit
//
//  Created by Sean Wareham on 11/23/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__ApplyFilterCommand__
#define __imagedit__ApplyFilterCommand__

#include <iostream>
#include <string>
#include "ImageCommand.h"
#include "Filter.h"

class ApplyFilterCommand : public ImageCommand {
private:
    Filter* myFilter;
    Image* executeDiscreteFilter(Image* image);
    Image* executeSeperableFilter(Image* image);
public:
    Image* execute(Image* image);
    ApplyFilterCommand(Filter* filter);
    std::string printMessage();
    void printMe();
};
#endif /* defined(__imagedit__ApplyFilterCommand__) */
