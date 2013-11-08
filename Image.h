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

class Image {
private:
    char magic_number[2];
    int width;
    int height;
    int max;
    float*** image;
    float* imageDisplayArray;
public:
    Image(int w, int h, int max);
    Image(const char* file_name);
    ~Image(void);
    void writeImage(const char* file_name);
    int getWidth();
    int getHeight();
    float*** getImage();
    float* getImageDisplayArray();

};



#endif /* defined(__imagedit__Image__) */
