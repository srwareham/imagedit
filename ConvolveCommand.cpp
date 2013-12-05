//
//  ConvolveCommand.cpp
//  imagedit
//
//  Created by Sean Wareham on 12/4/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "ConvolveCommand.h"
#include <vector>



ConvolveCommand::ConvolveCommand(std::string filterType, int filterR) : myFilterType(filterType), myFilterR(filterR) {
    //    printf("hey you made a: %s with R: %d", filterType.c_str(), filterR);
};

Image* ConvolveCommand::convolveNonSeperable(Image* image, Filter* f){
    int width = image->getWidth();
    int height = image->getHeight();
    int max = image->getMax();
    
    float*** originalImage = image->getImage();
    Image* filteredImage = new Image(width,height,max);
    float*** newImage = filteredImage->getImage();
    
        std::vector<std::vector<double>>* filterArray = f->getFilterArray();
        const int filterWidth = 2 * f->getFilterR() +1 ;
        const int filterHeight = filterWidth;
        
        int bright = f->getBrightnessOffset();
        int scalar = f->getScalar();
        
        double filter[filterWidth][filterHeight];
        
        std::vector< std::vector<double> >::iterator row;
        std::vector<double>::iterator col;
        for (row = filterArray->begin(); row != filterArray->end(); ++row) {
            for (col = row->begin(); col != row->end(); ++col) {
                //                printf("i: %d j: %d  %f\n", (int) (row - filterArray->begin()) , (int) (col - row->begin()), *col);
                //filter[i][j] = vector.at(i).at(j)
                filter[(int) (row - filterArray->begin())][(int) (col - row->begin())] = *col;
            }
        }
        
        for(int y = 0; y < height; y++) {
            for(int x = 0; x<width; x++) {
                double red = 0.0, green = 0.0, blue = 0.0;
                
                
                for(int filterX = 0; filterX < filterWidth; filterX++){
                    for(int filterY = 0; filterY < filterHeight; filterY++){
                        int imageX = (x - filterWidth / 2 + filterX + width) % width;
                        int imageY = (y - filterHeight / 2 + filterY + height) % height;
                        red += originalImage[imageY][imageX][0] * filter[filterX][filterY];
                        green += originalImage[imageY][imageX][1] * filter[filterX][filterY];
                        blue += originalImage[imageY][imageX][2] * filter[filterX][filterY];
                    }
                    //truncate values smaller than zero and larger than 255
                    newImage[y][x][0] = std::min(std::max((scalar * red + bright), 0.0), 255.0);
                    newImage[y][x][1] = std::min(std::max((scalar * green + bright), 0.0), 255.0);
                    newImage[y][x][2] = std::min(std::max((scalar * blue + bright), 0.0), 255.0);
                    
                }
                
            }
        }
    
    return filteredImage;
}

//TODO: confirm with professor Peck that this is the correct heuristic after she has the time to look it over.
Image* ConvolveCommand::convolveSeperable(Image* image, Filter* f){
    int width = image->getWidth();
    int height = image->getHeight();
    int max = image->getMax();
    Image* blurry = new Image(width, height, max);
    
    float*** originalImage = image->getImage();
    float*** newImage = blurry->getImage();
    
    
    std::vector<double>* weights = f->getSeperableVector();
    
    //horiz blurring
    for(int i = height-1; i >= 0; i--) {
        for(int j = 0; j<width; j++) {
            float avgR =0.0, avgG = 0.0,avgB = 0.0;
            
            //iterate though each filter weight.  Find appropriate pixel values to weight. if it not in bounds, get wraparound value
            int numWeights = (f->getFilterR() *2) +1;
            
            for (int pix =0; pix< numWeights; pix++) {
                
                //TODO: confirm bounds in regards to filter_r
                int distFromR = pix - f->getFilterR();
                //index of pixel we are examining, is the current + the distance from the point of comparison (takes into account neg and pos values)
                int horizPixIndex = j + distFromR;
                
                //if the pixel to the left does not exist, use the overflow amount over from the right edge
                if (horizPixIndex < 0) {
                    horizPixIndex = horizPixIndex + width;
                } else if (horizPixIndex >= width) {
                    horizPixIndex = horizPixIndex - width; //TODO: make sure this is right wrap-around heuristic
                }
                
                //with now acceptable bounds, grab pixels to the left and right of current (as well as the current)
                //and take the weighted average of their values
                //filter value at given range   //
                avgR += weights->at(pix) * originalImage[i][horizPixIndex][0];
                avgG += weights->at(pix) * originalImage[i][horizPixIndex][1];
                avgB += weights->at(pix) * originalImage[i][horizPixIndex][2];
                
            }
            
            //            printf("   R: %f, G: %f, B: %f\n",r, g, b);
            //            printf("avgR: %f, avgG: %f, avgB: %f\n",avgR, avgG, avgB);
            
            newImage[i][j][0] =(avgR);
            newImage[i][j][1] =(avgG);
            newImage[i][j][2]=(avgB);
        }
    }
    //vert blurring
    for(int i = height-1; i >= 0; i--) {
        for(int j = 0; j<width; j++) {
            float avgR =0.0, avgG = 0.0,avgB = 0.0;
            int numWeights = (f->getFilterR() *2) +1;
            for (int pix =0; pix< numWeights; pix++) {
                int distFromR = pix - f->getFilterR();
                int vertPixIndex = i + distFromR;
                if (vertPixIndex < 0) {
                    vertPixIndex = vertPixIndex + height;
                } else if (vertPixIndex >= height) {
                    vertPixIndex = vertPixIndex - height;
                }
                avgR += weights->at(pix) * newImage[vertPixIndex][j][0];
                avgG += weights->at(pix) * newImage[vertPixIndex][j][1];
                avgB += weights->at(pix) * newImage[vertPixIndex][j][2];
                
            }
            newImage[i][j][0] =(avgR);
            newImage[i][j][1] =(avgG);
            newImage[i][j][2]=(avgB);
        }
    }
    
    return blurry;
}

Image* ConvolveCommand::execute(Image* image){
    Filter* f = new Filter(myFilterType, myFilterR);
    //this allows us to see what the filter believes the r is.  Is useful for presets where the filter r is changed.
    myFilterR = f->getFilterR();
    if (f->isSeperable()){
        return convolveSeperable(image, f);
    }else{
        return convolveNonSeperable(image, f);
    }
}
//virtual std::string getStartMessage() = 0;
std::string ConvolveCommand::getEndMessage(){
    char buffer [100];
    int n;
    n = snprintf(buffer, 100, "Convolved Image with R= %d", myFilterR);
    return std::string(buffer);
}

std::string ConvolveCommand::getStartMessage(){
    char buffer [100];
    int n;
    n = snprintf(buffer, 100, "Convolving Image with filter: \"%s\"", myFilterType.c_str());
    return std::string(buffer);
}