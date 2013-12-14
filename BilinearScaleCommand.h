//
//  BilinearScaleCommand.h
//  imagedit
//
//  Created by Sean Wareham on 12/4/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__BilinearScaleCommand__
#define __imagedit__BilinearScaleCommand__

#include <iostream>
#include "ImageCommand.h"

class Point {
    public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {};
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
};

class BilinearScaleCommand : public ImageCommand {
private:
    int myNewH, myNewW;
    double scaleByPercent = -1;//must be positive to be valid
//    inline float interpolate(float val1, float val2, float coord1, float coord2, float dist);
    float interpolate(float v1, float v2, float distanceRatio);
    Point* getTopLeftCoord(int x, int y);
    Point* getTopRightCoord(int x, int y);
    Point* getBottomLeftCoord(int x, int y);
    Point* getBottomRightCoord(int x, int y);
public:
    Image* execute(Image* image);
    BilinearScaleCommand(int newH, int newW);
    BilinearScaleCommand(double percent);
    std::string getStartMessage();
    std::string getEndMessage();
};

#endif /* defined(__imagedit__BilinearScaleCommand__) */
