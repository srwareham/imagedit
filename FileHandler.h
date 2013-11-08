//
//  FileHandler.h
//  imagedit
//
//  Created by Sean Wareham on 11/8/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__FileHandler__
#define __imagedit__FileHandler__

#include <iostream>
#include <string>

class FileHandler {
public:
    FILE* getFile(std::string inputFilePath);
    void writeFile(std::string outputFilePath);
};

#endif /* defined(__imagedit__FileHandler__) */
