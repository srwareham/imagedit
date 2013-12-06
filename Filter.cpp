//
//  Filter.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/23/13.
//
// Some filters sourced from Lode Vandevenne at lodev.org/cgtutor/filtering.html
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
        
      //show horizontal edges
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
        //show vertical edges
    }else if (myFilterName == "showvedges"){
        temp =
        {
            {0,  0,  -1,  0,  0},
            {0,  0,  -1,  0,  0},
            {0,  0,   2,  0,  0},
            {0,  0,   0,  0,  0},
            {0,  0,   0,  0,  0},
        };
        myFilterR = 2;
        myScalar = 1.0;
        myBrightnessOffset = 0.0;
    }else if( myFilterName == "justedges"){
        temp =
        {
            {0,  0,  0,  0,  1},
            {0,  0,  0,  1,  0},
            {0,  0,   0,  0,  0},
            {0,  0,   0,  0,  0},
            {0,  0,   0,  0,  0},
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
            buildSeperableValues();
        }
        return myWeights;
    } else {
        //TODO: perhaps add error handling
            return NULL;
    }
}

Filter::~Filter(){
    //: was not implemented
}

double Filter::getBrightnessOffset(){
    return myBrightnessOffset;
}

double Filter::getScalar(){
    return myScalar;
}
