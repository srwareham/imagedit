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
    int origWidth = image->getWidth();
    int origHeight = image->getHeight();
    int max = image->getMax();
    
    //note there is no error handling for permissable bounds. things will go wrong with bad input
    float*** originalImage = image->getImage();
    //top left down to bottom right is the order
    int newHeight = bottom-top;
    int newWidth = right-left;
    
    //do nothing default
    if ((top == 0 && bottom ==0) || (left ==0 && right ==0)){
        top = left = 0;
        bottom = origHeight;
        right = origWidth;
    }
    
    
    Image* croppedImage = new Image(newWidth,newHeight,max);
    //TODO: for some reason newImage is not being inatialized.  its width and height are 0? happens right about here
    float*** newImage = croppedImage->getImage();
    
    int newI =0, newJ = 0;
    for (int i= top; i< bottom; i++){
        for (int j = left; j< right; j++){
//            newImage[newI][newJ][0] = originalImage[i][j][0];
//            printf("%f\n", originalImage[i][j][0]);
            newImage[newJ][newI][0] =1;
//            newImage[newI][newJ][1] = originalImage[i][j][1];
//            newImage[newI][newJ][2] = originalImage[i][j][2];
            newJ++;
        }
        newI++;
    }
    
    
    
    
    return croppedImage;
}

std::string CropCommand::getStartMessage(){
    
    return "cropping";
}

std::string CropCommand::getEndMessage(){
    return "cropped";
}