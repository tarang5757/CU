#include "StackArrays.h"

StackArrays::StackArrays() : count(0) {
    for (int i = 0; i < ARR_SIZE; i++) {
        objectArray[i] = Photo();
        pointerArray[i] = nullptr;
    }
}
//destructor
StackArrays::~StackArrays() {
    for (int i = 0; i < ARR_SIZE; i++) {
        delete pointerArray[i];
    }
}

//getter
Photo* StackArrays::getObjectArray() {
    return objectArray;
}

Photo** StackArrays::getPointerArray() {
    return pointerArray;
}

void StackArrays::addPhoto(Photo& photo) {
    if(count <= ARR_SIZE) {
        //Assign photo to next available location in object array
        objectArray[count] = photo;

        // Dynamically allocate a copy of photo and add pointer to the pointer array
        pointerArray[count] = new Photo(photo);

        count++;
    } else {
        cout <<"Array is full" << endl;

    };
}