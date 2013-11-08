//
//  Manager.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "Manager.h"
#include "RemoveRedCommand.h"


Manager::Manager() {
    myPossibleCommands = new std::map<std::string, Interface_ImageCommand*>;
    myActiveCommands = new std::vector<Interface_ImageCommand*>;
    buildMyPossibleCommands();
};

bool Manager::isPossibleCommand(std::string referenceName){
    return (myPossibleCommands->find(referenceName) != myPossibleCommands->end());

}
//Used to get an instance of a command and add the command to the active commands
//hmm this inheriently can only use a given command once in a series.  May need to switch to factories. We'll see.
Interface_ImageCommand* getReferencedCommand(std::string referenceName){
    return NULL;
}

void Manager::addPossibleCommand(std::string referenceName, Interface_ImageCommand* commandInstance){
    myPossibleCommands->insert(std::make_pair(referenceName, commandInstance));
}
//This is where new commands can manually be added
//--assuming the desired command implements the interface for commands
//TODO: maychange this to a factory implementation. in which case a factory will be needed as well...
void Manager::buildMyPossibleCommands(){
    addPossibleCommand("RemoveRedCommand", new RemoveRedCommand());
}

