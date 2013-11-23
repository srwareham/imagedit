//
//  ApplyDiscreteFilterFactory.h
//  imagedit
//
//  Created by Sean Wareham on 11/23/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__ApplyDiscreteFilterFactory__
#define __imagedit__ApplyDiscreteFilterFactory__

#include <iostream>
#include <iostream>
#include "ApplyDiscreteFilterCommand.h"
#include <string>
#include <map>
#include <string>
#include "Factory.h"

class ApplyDiscreteFilterFactory : public Factory {
public:
    ApplyDiscreteFilterFactory();
    ImageCommand* buildImageCommand(std::map<std::string, std::string>* flagMap);
    
};


#endif /* defined(__imagedit__ApplyDiscreteFilterFactory__) */
