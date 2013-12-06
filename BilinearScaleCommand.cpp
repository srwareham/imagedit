//
//  BilinearScaleCommand.cpp
//  imagedit
//
//  Created by Sean Wareham on 12/4/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
// NOTE: at present this is not truely bilinear interpolation.  It is a more simplified algorithm which involves taking the
// average pixel value across the 4 nearest pixels and using that value.  True interpolation would result in the new pixel
// not necessarily being equadistant from its 4 closest neighbors.
//

#include "BilinearScaleCommand.h"

inline float BilinearScaleCommand::interpolate( float val1, float val2, float coord1, float coord2, float dist){
    
    float seperation = coord2 - coord1;
    
    float slope = (val2 - val1) / seperation;
    
    return dist * slope;
}


Image* BilinearScaleCommand::execute(Image* image){
    int origWidth = image->getWidth();
    int origHeight = image->getHeight();
    int max = image->getMax();
    
    //if using percentage
    if (scaleByPercent > 0){
        myNewH = (int) (origWidth * (scaleByPercent/100.0));
        myNewW = (int) (origHeight * (scaleByPercent/100.0));
    }
    
    
    //these are to index in the original image.  Need heuristic for discrepency between actual value and new value
    int dX = 2;
    int dY = 2;
    
    myNewH = origHeight / dY;
    myNewW = origWidth /dX;
    
    
    
    
    Image* scaled = new Image(myNewW, myNewH, max);
    
    float*** originalImage = image->getImage();
    float*** newImage = scaled->getImage();
    
    
    
    for (int i = 0; i < myNewH; i++){
        for (int j=0; j< myNewW; j++){
            float newRed, newGreen, newBlue;
            
            //(0,0) pixel
            float r1 = originalImage[i * dY][j *dX][0];
            float g1 = originalImage[i * dY][j * dX][1];
            float b1 = originalImage[i * dY][j* dX][2];
            
            //(1,0) pixel
            float r2 = originalImage[i* dY][j*dX +1][0];
            float g2 = originalImage[i * dY][j*dX+1][1];
            float b2 = originalImage[i * dY][j*dX+1][2];
            
            //(0,1) pixel
            float r3 = originalImage[i * dY+1][j *dX][0];
            float g3 = originalImage[i * dY +1][j * dX][1];
            float b3 = originalImage[i * dY +1][j* dX][2];
            
            //(1,1) pixel
            float r4 = originalImage[i * dY+1][j *dX+1][0];
            float g4 = originalImage[i * dY +1][j * dX+1][1];
            float b4 = originalImage[i * dY +1][j* dX+1][2];
            
            newRed = (r1 + r2 + r3 + r4)/4.0;
            newGreen = (g1 + g2 + g3 + g4)/4.0;
            newBlue = (b1 + b2 + b3 + b4)/4.0;
            
            newImage[i][j][0] = newRed;
            newImage[i][j][1] = newGreen;
            newImage[i][j][2] = newBlue;
        }
    }
    
    return scaled;
}
//TODO: would liked to have had consistent ordering of width and height throughout codebase
BilinearScaleCommand::BilinearScaleCommand(int newH, int newW) : myNewH(newH), myNewW(newW){};

BilinearScaleCommand::BilinearScaleCommand(double percent){
    if (percent >0){
        scaleByPercent = percent;
    }else {
        //TODO:ERROR
        scaleByPercent = 100.0;
    }
}

std::string BilinearScaleCommand::getStartMessage(){
    char buffer [100];
    int n;
    //if we used a percentage
    if (scaleByPercent >0){
        n = snprintf(buffer, 100, "Scaling Image by: %f%%\n", scaleByPercent);
        //if we used hard coded width and height
    }else {
        n = snprintf(buffer, 100, "Scaling Image to Width: %d Height: %d\n", myNewW, myNewH);
    }
    return std::string(buffer);
}

std::string BilinearScaleCommand::getEndMessage(){
    return "scaled\n";
}
