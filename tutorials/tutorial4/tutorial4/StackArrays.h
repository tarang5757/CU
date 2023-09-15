#ifndef STACKARRAYS_H
#define STACKARRAYS_H

#include "Photo.h"
#include "defs.h"

class StackArrays {
public:
    StackArrays();
    ~StackArrays();
    Photo* getObjectArray();
    Photo** getPointerArray();
    void addPhoto(Photo&);

private:
    Photo objectArray[ARR_SIZE];
    Photo* pointerArray[ARR_SIZE];
    int count;
};

#endif