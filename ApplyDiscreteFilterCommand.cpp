//
//  ApplyDiscreteFilterCommand.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/23/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "ApplyDiscreteFilterCommand.h"

ApplyDiscreteFilterCommand::ApplyDiscreteFilterCommand(){};





Image* ApplyDiscreteFilterCommand::execute(Image* image){
    int width = image->getWidth();
        int height = image->getHeight();
    int max = image->getMax();
    
    float*** originalImage = image->getImage();
    Image* filteredImage = new Image(width,height,max);
    float*** newImage = filteredImage->getImage();
    
//    const int filterWidth = 3;
//    const int filterHeight = 3;
    
//    double filter[filterWidth][filterHeight] =
//    {
//        0.0, 0.2,  0.0,
//        0.2, 0.2,  0.2,
//        0.0, 0.2,  0.0
//    };
//    
//    double factor = 1.0;
//    double bias = 0.0;
    
    const int filterWidth = 9;
    const int filterHeight = 9;
    
    double filter[filterWidth][filterHeight] =
    {
        1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1,
    };
    double factor = 1.0 / 9.0;
    double bias = 0.0;
    
    
    
    for(int y = 0; y < height; y++) {
        for(int x = 0; x<width; x++) {
            double red = 0.0, green = 0.0, blue = 0.0;
            
            
            for(int filterX = 0; filterX < filterWidth; filterX++){
                for(int filterY = 0; filterY < filterHeight; filterY++){
                    int imageX = (x - filterWidth / 2 + filterX + width) % width;
                    int imageY = (y - filterHeight / 2 + filterY + height) % height;
                    red += originalImage[imageY][imageX][0] * filter[filterX][filterY];
                    green += originalImage[imageY][imageX][1] * filter[filterX][filterY];
                    blue += originalImage[imageY][imageX][2] * filter[filterX][filterY];
                }      
                //truncate values smaller than zero and larger than 255
                newImage[y][x][0] = std::min(std::max((factor * red + bias), 0.0), 255.0);
                newImage[y][x][1] = std::min(std::max((factor * green + bias), 0.0), 255.0);
                newImage[y][x][2] = std::min(std::max((factor * blue + bias), 0.0), 255.0);
                
            }
            
        }
    }
    
    
    
    
    
    
    
    
    
    return filteredImage;
}


std::string ApplyDiscreteFilterCommand::printMessage(){
    return std::string("Applying Discrete Filter\n");
}
