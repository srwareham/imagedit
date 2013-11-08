//
//  Interface_ImageComand.h
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__Interface_ImageComand__
#define __imagedit__Interface_ImageComand__

#include <iostream>
#include <vector>
#include <map>
#include <string>

class Interface_ImageCommand {
private:
    std::map<std::string,std::string> myFlags; // (flag, flagVal)
public:
    virtual void OverrideMe() = 0;
    virtual ~Interface_ImageCommand();
    void setFlag(std::string flag, std::string flagVal);
};

#endif /* defined(__imagedit__Interface_ImageComand__) */
