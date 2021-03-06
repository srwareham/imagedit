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
#include "ColorizeFactory.h"
#include "CropFactory.h"
#include "FlipFactory.h"

FactoryManager::FactoryManager(){
    myCommandFactories = new std::map<std::string, Factory*>();
}

void FactoryManager::defineFactory(std::string referenceName, Factory* factoryInstance){
    myCommandFactories->insert(std::make_pair(referenceName, factoryInstance));
}

void FactoryManager::instantiateFactories(){
    defineFactory("convolve", new ConvolveFactory());
    defineFactory("scale", new BilinearScaleFactory());
    defineFactory("colorize", new ColorizeFactory());
    defineFactory("crop", new CropFactory());
    defineFactory("flip", new FlipFactory());
}

std::map<std::string, Factory*>* FactoryManager::getFactories(){
    instantiateFactories();
    return myCommandFactories;
}