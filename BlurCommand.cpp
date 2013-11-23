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

Image* BlurCommand::execute(Image* image){
//    printf("IMAGE HEIGHT: %d\n",image->getHeight());
    Image* blurred = new Image(image->getWidth(), image->getHeight(), image->getMax());
    float*** newImage = blurred->getImage();
    float*** originalImage = image->getImage();
    int height = image->getHeight();
    int width = image->getWidth();
    for(int i = height-1; i >= 0; i--) {
        for(int j = 0; j<width; j++) {
            newImage[i][j][0] = 0; //r
            newImage[i][j][1] = originalImage[i][j][1]; //g
            newImage[i][j][2] = originalImage[i][j][2]; //b
        }
    }
    
    return blurred;
}

void BlurCommand::printMe() {
    printf("BlurFilter: %s\n" ,myFilterType.c_str());
    printf("BlurFilterR: %d\n" ,myFilterR);
}

std::string BlurCommand::printMessage(){
    char buffer [100];
    int n;
    n = snprintf(buffer, 100, "Blurring Image with filter: %s and R: %d\n", myFilterType.c_str(), myFilterR);
    return std::string(buffer);
}