//
//  ColorizeCommand.cpp
//  imagedit
//
//  Created by Sean Wareham on 12/5/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "ColorizeCommand.h"

ColorizeCommand::ColorizeCommand(std::string colorEffect): myColorEffect(colorEffect){
//    predefined = 
};

ColorizeCommand::ColorizeCommand(double redBias, double greenBias, double blueBias) : myRedBias(redBias), myGreenBias(greenBias), myBlueBias(blueBias) {
    predefined = false;
};


void ColorizeCommand::applyColor(float*** newImage, float*** originalImage, int height, int width, double redBias, double greenBias, double blueBias){
    for(int i = height-1; i >= 0; i--) {
        for(int j = 0; j<width; j++) {
            float oldR = originalImage[i][j][0];
            float oldG = originalImage[i][j][1];
            float oldB = originalImage[i][j][2];

            float newR = oldR * redBias;
            float newG = oldG * greenBias;
            float newB = oldB * blueBias;
            if (newR > 255){
                newR = 255.0;
            }
            if (newG > 255){
                newG = 255.0;
            }
            if (newB > 255){
                newB = 255.0;
            }
            newImage[i][j][0] = newR;
            newImage[i][j][1] = newG;
            newImage[i][j][2] = newB;
        }
    }
}


//this may have more repeated code and may look uglier than putting the function call in one
//unified loop, but I believe this will greatly improve performance by decreasing function
//call overhead to one call instead of one for every pixel.  It is of course possible the compiler would have done this
//on its own.

//This heuristic was sourced from Tabitha Peck on 7/23/13
void ColorizeCommand::applyGrayscale(float*** newImage, float*** originalImage, int height, int width){
    for(int i = height-1; i >= 0; i--) {
        for(int j = 0; j<width; j++) {
            float y = (0.310* originalImage[i][j][0]) + (0.591* originalImage[i][j][1]) + (0.111* originalImage[i][j][2]);
            newImage[i][j][0] = y; //r
            newImage[i][j][1] = y; //g
            newImage[i][j][2] = y; //b
        }
    }
}

void ColorizeCommand::applyNegative(float*** newImage, float*** originalImage, int height, int width){
    for(int i = height-1; i >= 0; i--) {
        for(int j = 0; j<width; j++) {
            float oldR = originalImage[i][j][0];
            float oldG = originalImage[i][j][1];
            float oldB = originalImage[i][j][2];
            
            float newR = 255 - oldR;
            float newG = 255 - oldG;
            float newB = 255 - oldB;
            if (newR > 255){
                newR = 255.0;
            }
            if (newG > 255){
                newG = 255.0;
            }
            if (newB > 255){
                newB = 255.0;
            }
            newImage[i][j][0] = newR;
            newImage[i][j][1] = newG;
            newImage[i][j][2] = newB;
        }
    }
}

void ColorizeCommand::applyCartoonize(float ***newImage, float ***originalImage, int height, int width){
    for(int i = height-1; i >= 0; i--) {
        for(int j = 0; j<width; j++) {
            float oldR = originalImage[i][j][0];
            float oldG = originalImage[i][j][1];
            float oldB = originalImage[i][j][2];
            float base = 0.3 * oldR + 0.59 * oldG + 0.11 * oldB;
            float newR = 30 * base;
            float newG = base;
            float newB = base;
            
            if (newR > 255){
                newR = 255.0;
            }
            if (newG > 255){
                newG = 255.0;
            }
            if (newB > 255){
                newB = 255.0;
            }
            newImage[i][j][0] = newR;
            newImage[i][j][1] = newG;
            newImage[i][j][2] = newB;
        }
    }
}

Image* ColorizeCommand::execute(Image* image){
    Image* colorized = new Image(image->getWidth(), image->getHeight());
    float*** newImage = colorized->getImage();
    float*** originalImage = image->getImage();
    int height = image->getHeight();
    int width = image->getWidth();
    
    //if this is an existing color scheme
    if (predefined){
        if (myColorEffect == "-removered"){
            applyColor(newImage, originalImage, height, width, 0.0, 1.0, 1.0);
        }else if( myColorEffect == "-negative"){
            applyNegative(newImage, originalImage, height, width);
        }else if(myColorEffect == "-grayscale"){
            applyGrayscale(newImage, originalImage, height, width);
        }else if(myColorEffect == "-cartoonize"){
            applyCartoonize(newImage, originalImage, height, width);
        }else {
        //TODO: perhaps add error handling
        }
    }else{
        applyColor(newImage,originalImage,height, width, myRedBias, myGreenBias, myBlueBias);
    }
    
    return colorized;
}

std::string ColorizeCommand::getStartMessage(){
    char buffer [100];
    int n;
    //we use +1 here only because we dont want to print the "-" which is the first character.
    //yey pointer manipulation!
    if (predefined){
        n = snprintf(buffer, 100, "Colorizing Image with style: %s", myColorEffect.c_str()+1);
    }else{
        n = snprintf(buffer, 100, "Colorizing with Biases R=%.2f%% G=%.2f%% B=%.2f%%", myRedBias* 100, myGreenBias * 100, myBlueBias * 100);
    }
    return std::string(buffer);
};

std::string ColorizeCommand::getEndMessage(){
    char buffer [100];
    int n;
    
    if (predefined){
        n = snprintf(buffer, 100, "Colorized Image with style: %s", myColorEffect.c_str()+1);
    }else{
        n = snprintf(buffer, 100, "Colorized with Biases R=%.2f%% G=%.2f%% B=%.2f%%", myRedBias* 100, myGreenBias * 100, myBlueBias * 100);
    }
    
    return std::string(buffer);
};