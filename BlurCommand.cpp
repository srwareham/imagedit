//
//  BlurCommand.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "BlurCommand.h"

BlurCommand::BlurCommand(std::string filterType, int filterR) : myFilterType(filterType), myFilterR(filterR){
//    printf("hey you made a: %s with R: %d", filterType.c_str(), filterR);
};

void BlurCommand::execute(Image* image){
//    printf("IMAGE HEIGHT: %d\n",image->getHeight());
    float*** imagef = image->getImage();
    int height = image->getHeight();
    int width = image->getWidth();
//    printf("HEY IM OVVERIDED\n");
//    printMe();
    for(int i = height-1; i >= 0; i--) {
        for(int j = 0; j<width; j++) {
            imagef[i][j][0] = 0; //r
            imagef[i][j][1] = imagef[i][j][1]; //g
            imagef[i][j][1] = imagef[i][j][2]; //b
        }
    }
    
//    return red;
}

void BlurCommand::printMe() {
    printf("BlurFilter: %s\n" ,myFilterType.c_str());
    printf("BlurFilterR: %d\n" ,myFilterR);
}