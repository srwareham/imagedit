//
//  CropCommand.cpp
//  imagedit
//
//  Created by Sean Wareham on 12/6/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "CropCommand.h"


CropCommand::CropCommand(int top, int bottom, int left, int right) :  top(top), bottom(bottom),left(left), right(right) {};

Image* CropCommand::execute(Image* image){
    
    int origWidth = image ->getWidth();
    int origHeight = image ->getHeight();
    float*** originalImage = image ->getImage();
    
    //error handling
    checkAndFixBounds(origWidth, origHeight);

    //do nothing as default
    if ((top == 0 && bottom ==0) || (left ==0 && right ==0)){
        top = left = 0;
        bottom = origHeight;
        right = origWidth;
    }
    int newHeight = bottom -top;
    int newWidth = right -left;
    
    Image* croppedImage = new Image(newWidth,newHeight);
    float*** newImage = croppedImage ->getImage();

    for (int i= top; i< bottom; i++){
        for (int j = left; j< right; j++){
            newImage[i- top][j - left][0] = originalImage[i][j][0];
            newImage[i- top][j - left][1] = originalImage[i][j][1];
            newImage[i- top][j - left][2] = originalImage[i][j][2];

        }
    }
    return croppedImage;
}

void CropCommand::checkAndFixBounds(int origWidth, int origHeight){
    if (top < 0){
        top = 0;
    }
    if (top > origHeight){
        top = origHeight;
    }
    if (bottom < 0){
        bottom = 0;
    }
    if (bottom > origHeight){
        bottom = origHeight;
    }
    if (right < 0){
        right = 0;
    }
    if (right > origWidth){
        right = origWidth;
    }
    if (left < 0){
        left = 0;
    }
    if (left > origWidth){
        left = origWidth;
    }
}

std::string CropCommand::getStartMessage(){
    
    return "cropping";
}

std::string CropCommand::getEndMessage(){
    return "cropped";
}