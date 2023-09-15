#include "HeapArrays.h"

HeapArrays::HeapArrays(){
    photos = new Photo[ARR_SIZE];
    photoPointer = new Photo*[ARR_SIZE];
    numPhotos = 0;
}

HeapArrays::~HeapArrays() {
    delete[] photos;
    for (int i = 0; i < numPhotos; i++) {
        delete photoPointer[i];
    }
    delete[] photoPointer;
}

//getters
Photo* HeapArrays::getObjectArray(){
    return photos;
}

Photo** HeapArrays::getPointerArray(){
    return photoPointer;
}

void HeapArrays::addPhoto(Photo& photo) {
    if(numPhotos<= ARR_SIZE) {
        //Assign photo to next available location in object array
        photos[numPhotos] = photo;

        // Dynamically allocate a copy of photo and add pointer to the pointer array
        photoPointer[numPhotos] = new Photo(photo);

        numPhotos++;
    } else {
        cout <<"Array is full" << endl;

    };
}
