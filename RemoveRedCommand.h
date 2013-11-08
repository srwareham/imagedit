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
#include "Interface_ImageComand.h"

class RemoveRedCommand : public Interface_ImageCommand {
public:
    RemoveRedCommand(void);
    void OverrideMe(void);
};

#endif /* defined(__imagedit__RemoveRedCommand__) */
