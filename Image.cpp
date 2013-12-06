//
//  Image.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/8/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "Image.h"

Image::Image(int w, int h, int m =3) {
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

Image::Image(int w, int h){
    Image::Image(w,h,3);
}

Image::Image(const char* filePath){
    FILE* file;
    char buff[16];
    float r, g, b;
    
    file = fopen(filePath, "r"); // open file for reading
    
    if(!file) {
        fprintf(stderr, "Unable to open file %s", filePath);
        exit(1);
    }
    
    fscanf(file, "%s%*[^\n]%*c", magic_number); //read magic number and white space
    
    if(magic_number[0] != 'P' || magic_number[1] != '3') {
        printf("Incorrect file type");
        exit(1);
    }
    
    //check for comments
    fscanf(file, "%s", buff);
    while (strncmp(buff, "#", 1) == 0) {
        fscanf(file, "%s%*[^\n]%*c", buff);
    }
    
    if (fscanf(file, "%d %d %d", &width, &height, &max) != 3) {
        fprintf(stderr, "Invalid image size (error loading '%s')\n", filePath);
        exit(1);
    }
    
    image = new float **[height];
    for(int i = 0; i < height; i++) {
        image[i] = new float *[width];
        for(int j = 0; j<width; j++) {
            image[i][j] = new float[3];
            if(fscanf(file, "%f %f %f", &r, &g, &b) != 3) {
                fprintf(stderr, "Invalid pixel reading\n");
                exit(1);
            }
            image[i][j][0] = r/255;
            image[i][j][1] = g/255;
            image[i][j][2] = b/255;
        }
    }
    
    fclose(file);
}
//TODO: destroy pixels too
Image::~Image(void) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            delete [] image[i][j];
        }
        delete [] image[i];
    }
    delete [] image;
    
    delete [] imageDisplayArray;
}

void Image::writeImage(const char* filePath) {
    FILE* file;
    file = fopen(filePath, "w");
    if(!file) {
        fprintf(stderr, "Unable to open file %s", filePath);
        exit(1);
    }
    //write ppm header
//    printf("%f",image[0][0][2]*255);
    magic_number[0] = 'P';
    magic_number[1] = '3';
    fprintf(file,"%c%c\n",magic_number[0],magic_number[1]);
    fprintf(file,"#picture made by imagedit\n");
    fprintf(file,"%d %d\n",width, height);
    fprintf(file,"%d\n",255);
    //write pixel values
    for(int i = 0; i < height; i++) {
        for(int j = 0; j<width; j++) {
            float* pixel = image[i][j];
            fprintf(file, "%g\n%g\n%g\n",pixel[0] *255, pixel[1]* 255, pixel[2]*255);
        }
    }
    fclose(file);
    
}
//returns 2d array of pixels
Pixel** Image::getPixels() {
    if (pixels == NULL){
        initializePixels();
    } else {
        return pixels;
    }
    return NULL;
}

float*** Image::getImage() {
    return image;
}

int Image::getWidth() {
    return width;
}


int Image::getHeight() {
    return height;
}

int Image::getMax() {
    return max;
}

void Image::initializePixels(){
    pixels = new Pixel*[height];//TODO: not sure if this is correct
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            pixels[i][j] = Pixel(&image[i][j][0], &image[i][j][1], &image[i][j][2]);
        }
    }
}

//Pixel* Image::getPixel(int x, int y){
//    if (pixels == NULL){
//        initializePixels();
//    }
//    
////    return pixels[x][y];
//}

