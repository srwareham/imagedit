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
    Image* red = new Image(image->getWidth(), image->getHeight(), image->getMax());
    float*** newImage = red->getImage();
    float*** originalImage = image->getImage();
    int height = image->getHeight();
    int width = image->getWidth();
    for(int i = height-1; i >= 0; i--) {
        for(int j = 0; j<width; j++) {
            newImage[i][j][0] = 0; //r
            newImage[i][j][1] = originalImage[i][j][1]; //g
            newImage[i][j][2] = originalImage[i][j][2]; //b
        }
    }
    
    return red;
    return NULL;
}

std::string RemoveRedCommand::getStartMessage(){
    return "removing red";
};
std::string RemoveRedCommand::getEndMessage(){
    return "removed red";
}

