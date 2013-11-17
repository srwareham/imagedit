//
//  Pixel.h
//  imagedit
//
//  Created by Sean Wareham on 11/8/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__Pixel__
#define __imagedit__Pixel__

#include <iostream>

class Pixel {
private:
    float* r;
    float* g;
    float* b;
    int i, j;//position based on
public:
    Pixel(float* r, float* g, float* b);
    
    void setCartCords(int x, int y);
    void setX();
    void setY();
    int getX();
    int getY();
    
    void setI();
    void setJ();
    int getI();
    int getJ();
    
    float* R();//this is also used to set..should i use a setter? probably slower
    float* G();
    float* B();
    
};


#endif /* defined(__imagedit__Pixel__) */
