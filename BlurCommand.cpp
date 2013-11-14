//
//  BlurCommand.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "BlurCommand.h"

BlurCommand::BlurCommand(std::string filterType, int filterR) : myFilterType(filterType), myFilterR(filterR){
    printf("hey you made a: %s with R: %d", filterType.c_str(), filterR);
};

void BlurCommand::execute(Image* image){
    printf("HEY IM OVVERIDED\n");
}

void BlurCommand::printMe() {
    printf("BlurFilter: %s\n" ,myFilterType.c_str());
    printf("BlurFilterR: %d\n" ,myFilterR);
}