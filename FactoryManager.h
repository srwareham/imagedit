//
//  FactoryManager.h
//  imagedit
//
//  Created by Sean Wareham on 12/5/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__FactoryManager__
#define __imagedit__FactoryManager__

#include <iostream>
#include <map>
#include <string>
#include "Factory.h"
#include "ImageCommand.h"

class FactoryManager {
    //(command referenceName, map<CommandFlag,flagVal>)
    //    typedef std::map<std::string, std::map<std::string, std::string>> commandMap;
private:
    std::map<std::string, Factory*>* myCommandFactories;
    
    void defineFactory(std::string referenceName, Factory* factoryInstance);
    void instantiateFactories();
public:
    FactoryManager(void);
    std::map<std::string, Factory*>* getFactories();
};

#endif /* defined(__imagedit__FactoryManager__) */
