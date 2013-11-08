//
//  Image.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/8/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "Image.h"

Image::Image(int w, int h, int m) {
    width = w;
    height = h;
    max = m;
    image = new float**[height];
    for(int i = 0; i < height; i++) {
        image[i] = new float*[width];
        for(int j = 0; j < width; j++) {
            image[i][j] = new float[3];
            image[i][j][0] = 0;
            image[i][j][1] = 0;
            image[i][j][2] = 0;
        }
    }
    imageDisplayArray = NULL;
}
