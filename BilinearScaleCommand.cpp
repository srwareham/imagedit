//
//  BilinearScaleCommand.cpp
//  imagedit
//
//  Created by Sean Wareham on 12/4/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//  Heuristic sourced from forums.codeguru.com/showthread.php?167306-Bilinear-Interpolation-Scaling-a-bitmap&p=463201#post463201
//

#include "BilinearScaleCommand.h"



Image* BilinearScaleCommand::execute(Image *image){
    int origWidth = image->getWidth();
    int origHeight = image->getHeight();
    
    float*** originalImage = image->getImage();
    
    //if using percentage
    if (scaleByPercent > 0){
        //floors by default
        myNewW = (int) (origWidth * (scaleByPercent/100.0));
        myNewH = (int) (origHeight * (scaleByPercent/100.0));
    }
  
    Image* scaledImage = new Image(myNewW, myNewH);
    float*** newImage = scaledImage->getImage();
    
    double xratio = (double)(origWidth-1) / double(myNewW-1);
    double yratio = (double)(origHeight-1) / double(myNewH-1);
    
    
    for (int i=0; i<myNewH; i++){
        double y = (double)i * yratio;
        int i1 = (int)y;
        double deltaY = y - (double)i1;
        if (i1 == origHeight-1){
            i1 = origHeight-2;
            deltaY = 1.0;
        }
        for (int j=0; j<myNewW; j++){
            double x = (double)j * xratio;
            int j1 = (int)x;
            double deltaX = x - (double)j1;
            if (j1 == origWidth-1){
                j1 = origWidth-2;
                deltaX = 1.0;
            }

            for (int color = 0; color < 3; color++){
                double interp = (1-deltaY)*(1-deltaX)*(double)originalImage[i1][j1][color] +
                deltaY*(1-deltaX)*(double)originalImage[i1+1][j1][color] +
                (1-deltaY)*deltaX*(double)originalImage[i1][j1+1][color] +
                deltaY*deltaX*(double)originalImage[i1+1][j1+1][color];
                newImage[ i ][ j ][color] = (float) interp;
            }

        }
    }

    return scaledImage;
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
    char buffer [100];
    int n;
    //if we used a percentage
    if (scaleByPercent >0){
        n = snprintf(buffer, 100, "Scaled Image by: %f%%\n", scaleByPercent);
        //if we used hard coded width and height
    }else {
        n = snprintf(buffer, 100, "Scaled Image to Width: %d Height: %d\n", myNewW, myNewH);
    }
    return std::string(buffer);
}
