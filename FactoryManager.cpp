//
//  FactoryManager.cpp
//  imagedit
//
//  Created by Sean Wareham on 12/5/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "FactoryManager.h"
#include "ConvolveFactory.h"
#include "BilinearScaleFactory.h"
#include "FactoryManager.h"

FactoryManager::FactoryManager(){
    myCommandFactories = new std::map<std::string, Factory*>();
}

void FactoryManager::defineFactory(std::string referenceName, Factory* factoryInstance){
    myCommandFactories->insert(std::make_pair(referenceName, factoryInstance));
}

void FactoryManager::instantiateFactories(){
    defineFactory("convolve", new ConvolveFactory());
    defineFactory("scale", new BilinearScaleFactory());
}

std::map<std::string, Factory*>* FactoryManager::getFactories(){
    instantiateFactories();
    return myCommandFactories;
}