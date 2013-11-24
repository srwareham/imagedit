//
//  ApplyFilterCommand.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/23/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "ApplyFilterCommand.h"


//std::string myFilterType;
//int myFilterR;
Image* ApplyFilterCommand::executeDiscreteFilter(Image* image){
    int width = image->getWidth();
    int height = image->getHeight();
    //defines whether pixels are triples or another set.  3 is used in this implementation, 4 could be used if needed to reimplement with alpha. Will probably go back and hide this. TODO:
    int max = image->getMax();
    float*** originalImageArray = image->getImage();
    
    Image* filteredImage = new Image(width * myFilter->getWidthScalingFactor(), height * myFilter->getHeightScalingFactor(), max);
    
    float*** filteredArray = filteredImage->getImage();
    
    const int filterHeight = (myFilter->getFilterR() * 2) + 1;
    const int filterWidth = filterHeight;
//    double filterArray[filterWidth][filterHeight] = myFilter->getDiscreteArray();
    double** filterArray= myFilter->getDiscreteArray();
    
    //apply convolution
    double scalar = myFilter->getScalar();;// used to allow non-normalized filters divide by
    double brightnessOffset = myFilter->getBrightnessOffset();
    
    //for every pixel
    for (int y =0; y < height; y++){
        for (int x = 0; x < width; x++){
            double red = 0.0, green = 0.0, blue = 0.0;
            //for every filter value
            for (int filterY = 0; filterY< filterHeight; filterY++){
                for (int filterX =0; filterX < filterWidth; filterX++){
                    int xCoord = (x- filterWidth / 2 + filterX + width) % width;
                    int yCoord = (y - filterHeight / 2 + filterY + height) % height;
                
                    red += originalImageArray[yCoord][xCoord][0] * filterArray[filterX][filterY];
                    blue += originalImageArray[yCoord][xCoord][1] * filterArray[filterX][filterY];
                    green += originalImageArray[yCoord][xCoord][2] * filterArray[filterX][filterY];
                }
                
                //only allow values between 0 and 255
                filteredArray[y][x][0] = std::min(std::max((scalar * red + brightnessOffset), 0.0), 255.0);
                filteredArray[y][x][1] = std::min(std::max((scalar * green + brightnessOffset), 0.0), 255.0);
                filteredArray[y][x][2] = std::min(std::max((scalar * blue + brightnessOffset), 0.0), 255.0);
            }
        }
    }
    
    
    
    
    
    
    
    
    return image;
}
Image* ApplyFilterCommand::executeSeperableFilter(Image* image){
    return image;
}

//determine which heuristic to use to apply a filter. Can either be seperable.
//Or is simply Applying a 2d-array-form filter.
Image* ApplyFilterCommand::execute(Image* image){
    if (myFilter->isSeperable()){
        return executeSeperableFilter(image);
    }else{
        return executeDiscreteFilter(image);
    }
}


ApplyFilterCommand::ApplyFilterCommand(Filter* filter) : myFilter(filter){};

std::string ApplyFilterCommand::printMessage(){
    return "Applying Filter";
}