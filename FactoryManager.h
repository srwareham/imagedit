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
#include "Factory.h"

class FactoryManager {
private:
    std::map<std::string, Factory*>* myCommandFactories;
    
    void defineFactory(std::string referenceName, Factory* factoryInstance);
    void instantiateFactories();
public:
    FactoryManager(void);
    std::map<std::string, Factory*>* getFactories();
};

#endif /* defined(__imagedit__FactoryManager__) */
