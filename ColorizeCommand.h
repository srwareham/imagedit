//
//  ColorizeCommand.h
//  imagedit
//
//  Created by Sean Wareham on 12/5/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__ColorizeCommand__
#define __imagedit__ColorizeCommand__

#include <iostream>
#include "ImageCommand.h"

class ColorizeCommand : public ImageCommand {
private:
    std::string myColorEffect;
    double myRedBias, myGreenBias, myBlueBias;
    
    void applyColor(float*** newImage, float*** originalImage, int height, int width, double redBias, double greenBias, double blueBias);
    void applySepia(float*** newImage, float*** originalImage, int height, int width);
    void applyGrayscale(float*** newImage, float*** originalImage, int height, int width);
    void applyRemovered(float*** newImage, float*** originalImage, int height, int width);
    void applyCartoonize(float*** newImage, float*** originalImage, int height, int width);
    bool predefined = true;
public:
    ColorizeCommand(std::string colorEffect);
    ColorizeCommand(double redBias, double greenBias, double blueBias);
    Image* execute(Image* image);
    std::string getStartMessage();
    std::string getEndMessage();
};

#endif /* defined(__imagedit__ColorizeCommand__) */
