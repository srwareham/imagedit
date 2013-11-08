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

struct Pixel {
    float* r, g, b;
    int i, j;
};
typedef struct pixel* pix;

#endif /* defined(__imagedit__Pixel__) */
