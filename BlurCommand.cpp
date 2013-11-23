//
//  BlurCommand.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "BlurCommand.h"
#include <vector>
#include <math.h>

const float PI = 3.141592;
enum filter_type {BOX, TENT, GAUSSIAN};

class Filter {
public:
    std::string myFilterType;
    int myFilter_r;
    std::vector<float>* myWeights;
    Filter(std::string filterType, int filter_r): myFilterType(filterType), myFilter_r(filter_r) {

        int len = (filter_r *2) + 1;
        //make room for len elements in the array
        myWeights = new std::vector<float>;
        myWeights->reserve(len);

        int x =0;
        //value that will be modified for each array value. Default for 1 length array is 1.0
        float val = 1.0;

        if (len ==1) {
            myWeights->insert(myWeights->begin(), val);
            return;
        }
        //populate weights array

        for (int i=0; i<len; i++) {
            //center based index, x
            x = i-filter_r;
            //TODO: perhaps add case insensitivity
            if (filterType == std::string("BOX")) {
                val =1.0/len;
            }
            else if (filterType == std::string("TENT")) {
                //sigma = 1
                val =(1.0-fabs(x/(float)filter_r))/(float) filter_r;
            }
            else if (filterType == std::string("GAUSSIAN") || filterType == std::string("GAUSS")) {
                val =(1.0/sqrt(2.0*PI))*exp(-(x*x/2.0));
            }
            else {
                printf("BAD ENUM TYPE: %s\n", filterType.c_str());
            }
            //        printf("VAL[%d]: %f\n", x, val);
            //set the weight to the desired value
            myWeights->insert(myWeights->begin() + i, val);


        }

        //    myWeights = &weights;
        //    printf("Type: %d ARRAY0: %f\n",fType, weights[0]);
        //{BOX, TENT, GAUSSIAN}



    };
};



BlurCommand::BlurCommand(std::string filterType, int filterR) : myFilterType(filterType), myFilterR(filterR) {
//    printf("hey you made a: %s with R: %d", filterType.c_str(), filterR);
};

Image* BlurCommand::execute(Image* image) {
    int width = image->getWidth();
    int height = image->getHeight();
    int max = image->getMax();
    Image* blurry = new Image(width, height, max);

    Filter* f = new Filter(myFilterType, myFilterR);

    float*** originalImage = image->getImage();
    float*** newImage = blurry->getImage();

    //horiz blurring
    for(int i = height-1; i >= 0; i--) {
        for(int j = 0; j<width; j++) {
            float avgR =0.0, avgG = 0.0,avgB = 0.0;

            //iterate though each filter weight.  Find appropriate pixel values to weight. if it not in bounds, get wraparound value
            int numWeights = (f->myFilter_r *2) +1;

            for (int pix =0; pix< numWeights; pix++) {

                //TODO: confirm bounds in regards to filter_r
                int distFromR = pix - f->myFilter_r;
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
                avgR += f->myWeights->at(pix) * originalImage[i][horizPixIndex][0];
                avgG += f->myWeights->at(pix) * originalImage[i][horizPixIndex][1];
                avgB += f->myWeights->at(pix) * originalImage[i][horizPixIndex][2];

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
            int numWeights = (f->myFilter_r *2) +1;
            for (int pix =0; pix< numWeights; pix++) {
                int distFromR = pix - f->myFilter_r;
                int vertPixIndex = i + distFromR;
                if (vertPixIndex < 0) {
                    vertPixIndex = vertPixIndex + height;
                } else if (vertPixIndex >= height) {
                    vertPixIndex = vertPixIndex - height;
                }
                avgR += f->myWeights->at(pix) * newImage[vertPixIndex][j][0];
                avgG += f->myWeights->at(pix) * newImage[vertPixIndex][j][1];
                avgB += f->myWeights->at(pix) * newImage[vertPixIndex][j][2];

            }
            newImage[i][j][0] =(avgR);
            newImage[i][j][1] =(avgG);
            newImage[i][j][2]=(avgB);
        }
    }

    return blurry;
}

void BlurCommand::printMe() {
    printf("BlurFilter: %s\n" ,myFilterType.c_str());
    printf("BlurFilterR: %d\n" ,myFilterR);
}

std::string BlurCommand::printMessage() {
    char buffer [100];
    int n;
    n = snprintf(buffer, 100, "Blurring Image with filter: %s and R: %d\n", myFilterType.c_str(), myFilterR);
    return std::string(buffer);
}