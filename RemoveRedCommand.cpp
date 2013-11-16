//
//  RemoveRedCommand.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "RemoveRedCommand.h"

RemoveRedCommand::RemoveRedCommand(){
    printf("This is a RemoveRedCommand\n");
}


Image* RemoveRedCommand::execute(Image* image){
    printf("HEY IM OVVERIDED\n");
    return NULL;
}