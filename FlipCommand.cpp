//
//  FlipCommand.cpp
//  imagedit
//
//  Created by Sean Wareham on 12/14/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "FlipCommand.h"

FlipCommand::FlipCommand(std::string axis) :  myAxis(axis) {};

Image* FlipCommand::execute(Image* image){
    
    int origWidth = image ->getWidth();
    int origHeight = image ->getHeight();
    float*** originalImage = image ->getImage();
    
    Image* flippedImage = new Image(origWidth,origHeight);
    float*** newImage = flippedImage ->getImage();
    
    if (myAxis == "y"){
        for (int i= 0; i< origHeight; i++){
            for (int j = 0; j< origWidth; j++){
                newImage[i][j][0] = originalImage[i][origWidth- j-1][0];
                newImage[i][j][1] = originalImage[i][origWidth -j-1][1];
                newImage[i][j][2] = originalImage[i][origWidth -j-1][2];
                
            }
        }
    } else if( myAxis == "x"){
        for (int i= 0; i< origHeight; i++){
            for (int j = 0; j< origWidth; j++){
                newImage[i][j][0] = originalImage[origHeight -i-1][j][0];
                newImage[i][j][1] = originalImage[origHeight -i-1][j][1];
                newImage[i][j][2] = originalImage[origHeight -i-1][j][2];
                
            }
        }
    }
    
    
    return flippedImage;
}

std::string FlipCommand::getStartMessage(){
    char buffer [100];
    int n;
    n = snprintf(buffer, 100, "Flipping Image About Axis: %s", myAxis.c_str());
    return std::string(buffer);
};

std::string FlipCommand::getEndMessage(){
    char buffer [100];
    int n;
    n = snprintf(buffer, 100, "Flipped Image About Axis: %s", myAxis.c_str());
    return std::string(buffer);
};