//
//  Filter.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/23/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "Filter.h"
#include <math.h>


void Filter::buildFilterValues(){
    myFilterValues = new std::vector<std::vector<double>>;
    std::vector<std::vector<double>> temp;
    if (myFilterName == "sharpen"){
        temp =
        {
            {-1, -1, -1},
            {-1,  9, -1},
            {-1, -1, -1}
        };
        
        myScalar = 1.0;
        myBrightnessOffset = 0.0;
        myFilterR = 1;
        
        
    }else if( myFilterName == "emboss"){
        temp =
        {
            {-1, -1,  0},
            {-1,  0,  1},
            {0,  1,  1}
        };
        myFilterR = 1;
        myScalar =1.0;
        myBrightnessOffset = 128.0;
        
      //default do nothing
    }else if ( myFilterName == "showhedges"){
        temp =
        {
            {0,  0,  0,  0,  0},
            {0,  0,  0,  0,  0},
            {-1, -1,  2,  0,  0},
            {0,  0,  0,  0,  0},
            {0,  0,  0,  0,  0},
        };
        myFilterR = 2;
        myScalar = 1.0;
        myBrightnessOffset = 0.0;
    
    }else{
        temp =
        {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
        };
        myFilterR =1;
        myScalar =1.0;
        myBrightnessOffset = 0.0;
    }

    //set my filter values to be whatever is desired
    *myFilterValues = temp;
}
bool Filter::isSeperable(){
    return (myFilterName == "gauss") || myFilterName == "tent" || myFilterName == "gaussian" || myFilterName == "box";

}


void Filter::buildSeperableValues(){
    const float PI = 3.141592;
    int len = (myFilterR *2) + 1;
    //make room for len elements in the array
    myWeights = new std::vector<double>;
    myWeights->reserve(len);
    
    int x =0;
    //value that will be modified for each array value. Default for 1 length array is 1.0
    double val = 1.0;
    
    if (len ==1) {
        myWeights->insert(myWeights->begin(), val);
        return;
    }
    //populate weights array
    
    for (int i=0; i<len; i++) {
        //center based index, x
        x = i-myFilterR;
        //TODO: perhaps add case insensitivity
        if (myFilterName == "box") {
            val =1.0/len;
        }
        else if (myFilterName == "tent") {
            //sigma = 1
            val =(1.0-fabs(x/(double) myFilterR))/(double) myFilterR;
        }
        else if (myFilterName == "gaussian" || myFilterName == "gauss") {
            val =(1.0/sqrt(2.0*PI))*exp(-(x*x/2.0));
        }
        else {
            printf("BAD ENUM TYPE: %s\n", myFilterName.c_str());
        }
        //        printf("VAL[%d]: %f\n", x, val);
        //set the weight to the desired value
        myWeights->insert(myWeights->begin() + i, val);
        
        
    }
}


Filter::Filter(std::string filterName, int filterR = -1): myFilterName(filterName), myFilterR(filterR){
    if (isSeperable()){
        buildSeperableValues();
    }else{
        buildFilterValues();
    }
    
};

std::vector<std::vector<double>>* Filter::getFilterArray(){
    return myFilterValues;
}



//TODO: hopefully be able to clean this up so that only the actual array and the offsets are needed. C++ primitaves are...primative.
//it may seem odd to define some variables in a getter.  but we dont want it in the constructor in the cases of when this is a seperable filter.  Could just move an if check in the constructor.

/*
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
 */

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
    if (isSeperable()){
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

double Filter::getBrightnessOffset(){
    return myBrightnessOffset;
}

double Filter::getScalar(){
    return myScalar;
}
