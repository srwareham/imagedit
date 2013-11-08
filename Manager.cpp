//
//  Manager.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "Manager.h"
#include "BlurFactory.h"



Manager::Manager() {
    myCommandFactories = new std::map<std::string, Factory*>;
    myCommandsToExecute = new std::vector<ImageCommand*>;
    instantiateFactories();
};

void Manager::defineFactory(std::string referenceName, Factory* factoryInstance){
    myCommandFactories->insert(std::make_pair(referenceName, factoryInstance));
}

//This is where new Commands are defined.  Simply create a class, a factory for it, and then instantiate a factory here
//referenceName is exactly what will be typed in the commandline. case sensitive.
void Manager::instantiateFactories(){
    defineFactory("Blur", new BlurFactory());
}
