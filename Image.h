//
//  Image.h
//  imagedit
//
//  Created by Tabitha Peck on 7/23/13.
//  Modified by Sean Wareham on 11/8/13.
//
//

#ifndef __imagedit__Image__
#define __imagedit__Image__

#include <iostream>
#include <vector>
#include "Pixel.h"


class Image {
private:
    char magic_number[2];
    int width;
    int height;
    int max;
    float*** image;
    float* imageDisplayArray;
    float** pixels;
    void initializePixels();
public:
    Image(int w, int h, int max);
    Image(const char* filePath);
    ~Image(void);
    void writeImage(const char* filePath);
    int getWidth();
    int getHeight();
    int getMax();
    float*** getImage();
    float* getImageDisplayArray();
    std::vector<Pixel> getPixelArray();
    Pixel* getPixel(int x, int y);

};



#endif /* defined(__imagedit__Image__) */
