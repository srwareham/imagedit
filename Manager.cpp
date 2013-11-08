//
//  Manager.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "Manager.h"


Manager::Manager() {
    myCommands = new std::map<std::string, Interface_ImageCommand*>;
};

void Manager::addCommand(std::string referenceName, Interface_ImageCommand* commandInstance){
    
}
bool Manager::isACommand(std::string referenceName){
//    if (*myCommands[referenceName] != NULL){
//        return true;
//    }
    return false;
}

Interface_ImageCommand* getReferencedCommand(std::string referenceName){
    return NULL;
}