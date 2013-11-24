//
//  Filter.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/23/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "Filter.h"



//int myFilterR;
//std::string myFilterName;

Filter::Filter(std::string filterName, int filterR): myFilterName(filterName), myFilterR(filterR){};

//TODO: hopefully be able to clean this up so that only the actual array and the offsets are needed. C++ primitaves are...primative.
//it may seem odd to define some variables in a getter.  but we dont want it in the constructor in the cases of when this is a seperable filter.  Could just move an if check in the constructor.
double** Filter::getDiscreteArray(){
    
    
    if ( myFilterName == "sharpen"){
        myFilterR = 4;
        const int filterHeight = 5;
        const int filterWidth = 5;
        
        double** answer = new double*[filterHeight];
        const double filter[filterHeight][filterWidth] =
        {
            -1, -1, -1, -1, -1,
            -1,  2,  2,  2, -1,
            -1,  2,  8,  2, -1,
            -1,  2,  2,  2, -1,
            -1, -1, -1, -1, -1,
        };
        for (int i =0; i < filterHeight; i++){
            for (int j = 0; j < filterWidth; j++){
                answer[i][j] = filter[i][j];
            }
        }
        
        myScalar =1.0/8.0;
        myBrightnessOffset = 0.0;
        return answer;
    } else if ( myFilterName == "emboss"){
        myFilterR = 1;
        const int filterHeight = 3;
        const int filterWidth = 3;
        
        double** answer = new double*[filterHeight];
        const double filter[filterWidth][filterHeight] =
        {
            -1, -1,  0,
            -1,  0,  1,
            0,  1,  1
        };
        for (int i =0; i < filterHeight; i++){
            for (int j = 0; j < filterWidth; j++){
                answer[i][j] = filter[i][j];
            }
        }
        
        myScalar =1.0;
        myBrightnessOffset = 128.0;
        return answer;
        //default behavior: do nothing
    } else {
        myFilterR = 1;
        const int filterHeight = 3;
        const int filterWidth = 3;
        
        double** answer = new double*[filterHeight];
        const double filter[filterWidth][filterHeight] =
        {
            0, 0, 0,
            0, 1, 0,
            0, 0, 0
        };
        for (int i =0; i < filterHeight; i++){
            for (int j = 0; j < filterWidth; j++){
                answer[i][j] = filter[i][j];
            }
        }
        
        myScalar =1.0;
        myBrightnessOffset = 0;
        return answer;
    }
    
    
    
    
    
    return NULL;
}

int Filter::getFilterR(){
    return myFilterR;
}
double Filter::getHeightScalingFactor(){
    return myHeightScalingFactor;
}

double Filter::getWidthScalingFactor(){
    return myWidthScalingFactor;
}

std::vector<double>* Filter::getSeperableVector(){
    if (seperable){
        if (myWeights != NULL){
//            buildMyWeights();
            printf("NEED TO BUILD WEIGHTS");
        }
        return myWeights;
    } else {
            return NULL;
    }
}

Filter::~Filter(){
    //TODO: add delete!
}

bool Filter::isSeperable(){
    return seperable;
}

double Filter::getBrightnessOffset(){
    return myBrightnessOffset;
}

double Filter::getScalar(){
    return myScalar;
}
