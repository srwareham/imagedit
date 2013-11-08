//
//  FileHandler.cpp
//  imagedit
//
//  Created by Sean Wareham on 11/8/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#include "FileHandler.h"

//TODO: maybe use ifstream instead.  Look into all of that jazz
//TODO: find extraneous includes
//TODO: Move includes out of h files and into cpp's when possible
FILE* FileHandler::getFile(std::string inputFilePath){
    FILE* file = fopen(inputFilePath.c_str(), "w");
    if(!file) {
        fprintf(stderr, "Unable to open file %s", file_name);
        exit(1);
    }else{
        return file;
    }
}
void FileHandler::writeFile(std::string outputFilePath){
    
}