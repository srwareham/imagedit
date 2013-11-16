//
//  RemoveRedCommand.h
//  imagedit
//
//  Created by Sean Wareham on 11/7/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
//

#ifndef __imagedit__RemoveRedCommand__
#define __imagedit__RemoveRedCommand__

#include <iostream>
#include "ImageCommand.h"

class RemoveRedCommand : public ImageCommand {
public:
    RemoveRedCommand(void);
    Image* execute(Image* image);
};

#endif /* defined(__imagedit__RemoveRedCommand__) */
