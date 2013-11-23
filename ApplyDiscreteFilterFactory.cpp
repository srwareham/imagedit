//
//  ApplyDiscreteFilterFactory.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/23/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "ApplyDiscreteFilterFactory.h"

ApplyDiscreteFilterFactory::ApplyDiscreteFilterFactory(){};


ImageCommand* ApplyDiscreteFilterFactory::buildImageCommand(std::map<std::string, std::string>* flagMap){

    return new ApplyDiscreteFilterCommand();
}