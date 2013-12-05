//
//  Filter.h
//  imagedit
//
//  Created by Sean Wareham on 11/23/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__Filter__
#define __imagedit__Filter__

#include <iostream>
#include <string>
#include <vector>

class Filter {
protected:
    int myFilterR;
    double myHeightScalingFactor = 1.0;
    double myWidthScalingFactor = 1.0;
    std::string myFilterName;
    std::vector<double>* myWeights;
    std::vector<std::vector<double>>* myFilterValues;
    void buildFilterValues();
    void buildSeperableValues();
    double myScalar =1.0;
    double myBrightnessOffset = 0.0;
    
public:
    Filter(std::string filterNname, int filterR);
    int getFilterR();
    double getHeightScalingFactor();
    double getWidthScalingFactor();
    std::vector<double>* getSeperableVector();
    std::vector<std::vector<double>>* getFilterArray();
    virtual ~Filter();
    bool isSeperable();
    double getBrightnessOffset();
    double getScalar();
};


#endif /* defined(__imagedit__Filter__) */
