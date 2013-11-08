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

//TODO: just make the Manager main.  have it instantiate the parser
void Manager::setMyCommandMap(Parser* p, int argc, const char **argv){
    myCommandMap =  p->parse(argc, argv);
}

void Manager::defineFactory(std::string referenceName, Factory* factoryInstance){
    myCommandFactories->insert(std::make_pair(referenceName, factoryInstance));
}

//This is where new Commands are defined.  Simply create a class, a factory for it, and then instantiate a factory here
//referenceName is exactly what will be typed in the commandline. case sensitive.
void Manager::instantiateFactories(){
    defineFactory("Blur", new BlurFactory());
}

bool Manager::isPossibleCommand(std::string referenceName){
    return (myCommandFactories->find(referenceName) != myCommandFactories->end());
}

void Manager::queueCommand(std::string referenceName){
    if (!isPossibleCommand(referenceName)){
        //TODO:perhaps add some error handling here
        return;
    }else{
        //TODO: not sure this is the correct way to access a map
        Factory* factory = myCommandFactories->at(referenceName);
        myCommandsToExecute->push_back(factory->buildImageCommand(myCommandMap->at(referenceName)));
        
    }
}