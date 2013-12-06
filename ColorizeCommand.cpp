//
//  ColorizeCommand.cpp
//  imagedit
//
//  Created by Sean Wareham on 12/5/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "ColorizeCommand.h"

ColorizeCommand::ColorizeCommand(std::string colorEffect): myColorEffect(colorEffect){};



//this may have more repeated code and may look uglier than putting the function call in one
//unified loop, but I believe this will greatly improve performance by decreasing function
//call overhead to one call instead of one for every pixel.  It is of course possible the compiler would have done this
//on its own.

//This heuristic was sourced from Tabitha Peck on 7/23/13
void ColorizeCommand::applyGrayscale(float*** newImage, float*** originalImage, int height, int width){
    for(int i = height-1; i >= 0; i--) {
        for(int j = 0; j<width; j++) {
            float y = (0.2126* originalImage[i][j][0]) + (0.7251* originalImage[i][j][1]) + (0.0722* originalImage[i][j][2]);
            newImage[i][j][0] = y; //r
            newImage[i][j][1] = y; //g
            newImage[i][j][2] = y; //b
        }
    }
}

void ColorizeCommand::applyRemovered(float*** newImage, float*** originalImage, int height, int width){
    for(int i = height-1; i >= 0; i--) {
        for(int j = 0; j<width; j++) {
            newImage[i][j][0] = 0; //r
            newImage[i][j][1] = originalImage[i][j][1]; //g
            newImage[i][j][2] = originalImage[i][j][2]; //b
        }
    }
}

void ColorizeCommand::applySepia(float*** newImage, float*** originalImage, int height, int width){
    for(int i = height-1; i >= 0; i--) {
        for(int j = 0; j<width; j++) {
            float y = (0.310* originalImage[i][j][0]) + (0.591* originalImage[i][j][1]) + (0.111* originalImage[i][j][2]);
            newImage[i][j][0] = y; //r
            newImage[i][j][1] = y; //g
            newImage[i][j][2] = y; //b
        }
    }
}



Image* ColorizeCommand::execute(Image* image){
    Image* colorized = new Image(image->getWidth(), image->getHeight(), image->getMax());
    float*** newImage = colorized->getImage();
    float*** originalImage = image->getImage();
    int height = image->getHeight();
    int width = image->getWidth();
    
    if (myColorEffect == "-removered"){
        applyRemovered(newImage, originalImage, height, width);
    }else if( myColorEffect == "-sepia"){
        applySepia(newImage, originalImage, height, width);
    }else if(myColorEffect == "-grayscale"){
        applyGrayscale(newImage, originalImage, height, width);
    }else {
        //TODO: perhaps add error handling
    }
    
    return colorized;
}

std::string ColorizeCommand::getStartMessage(){
    char buffer [100];
    int n;
    //we use +1 here only because we dont want to print the "-" which is the first character.
    //yey pointer manipulation!
    n = snprintf(buffer, 100, "Colorizing Image with style: %s", myColorEffect.c_str()+1);
    return std::string(buffer);
};

std::string ColorizeCommand::getEndMessage(){
    char buffer [100];
    int n;
    n = snprintf(buffer, 100, "Colorized Image with style: %s", myColorEffect.c_str()+1);
    return std::string(buffer);
};