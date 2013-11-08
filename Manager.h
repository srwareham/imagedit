//
//  Manager.h
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__Manager__
#define __imagedit__Manager__

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Factory.h"
#include "ImageCommand.h"


class Manager {
private:
    std::map<std::string, Factory*>* myCommandFactories;
    std::vector<ImageCommand*>* myCommandsToExecute;
    void defineFactory(std::string referenceName, Factory* factoryInstance);
    void instantiateFactories();
public:
    Manager(void);
    bool isPossibleCommand(std::string referenceName);
    ImageCommand* queueCommand(std::string referenceName);
};

#endif /* defined(__imagedit__Manager__) */


