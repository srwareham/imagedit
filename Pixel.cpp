//
//  Pixel.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/15/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "Pixel.h"

Pixel::Pixel(float r, float g, float b){
    
}

void Pixel::setCartCords(int x, int y){
    
}
void Pixel::setX(){
    
}

void Pixel::setY(){
    
}

int Pixel::getX(){
    //do math on i,j to find these
    return 0;
}

int Pixel::getY(){
    return 0;
}

void Pixel::setI(){
    
}

void Pixel::setJ(){
    
}

int Pixel::getI(){
    return i;
}

int Pixel::getJ(){
    return j;
}

//TODO: decide where i want this memory to be allocated. Perhaps on the heap at read time?
//also need to perhaps have methods return an image instead of modify an existing one
//this would be much easier for the case of shrinking an image
float* Pixel::R(){
    return r;
}
float* Pixel::G(){
    return g;
}
float* Pixel::B(){
    return b;
}

