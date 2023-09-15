#include "PhotoArray.h"

//constructor that initializes photoPointers and numPhotos
PhotoArray::PhotoArray() {
    photoPointers = new Photo*[MAX_ARRAY];
    numPhotos = 0;
}

//destructor that frees the memory
PhotoArray::~PhotoArray() {
    for (int i = 0; i < numPhotos; i++) {
        delete photoPointers[i];
    }
    delete[] photoPointers;
}


//check is numPhotos is max size and return true if it is and false otherwise
bool PhotoArray::isFull() const {
    return numPhotos == MAX_ARRAY;
}

//add a photo pointer at the end element in the array and return true if the operation was successful or false otherwise
bool PhotoArray::add(Photo* photo) {
    //first check if array is full
    if (isFull()) {
        return false;
    }
    //now add the photo at the entry
    photoPointers[numPhotos] = photo;
    //increament the size of array
    numPhotos++;
    return true;
}

//add a photo pointer at specified index in the array. returns true if the opeartion was successfull and false if not

bool PhotoArray::add(int index, Photo* photo) {
    //if index is greater than size of array or less than 0 it will throw indexbound error.
    //also check isFull
    if (index < 0 || index > numPhotos) {
        return false;
    }

    //shifting all the element to the right
    for (int i = index; i < numPhotos; i++) {
        photoPointers[i+1] = photoPointers[i];
    }

    //adding photo, increamenting numPhotos and return true
    photoPointers[index] = photo;
    numPhotos++;
    return true;
}

//this function returns the pointer to photo with the given title
//if there is no photo then we return null
Photo* PhotoArray::get(const string& title) const {
    for (int i = 0; i < numPhotos; i++) {
        if (photoPointers[i]->equals(title)) {
            return photoPointers[i];
        }
    }
    return NULL;
}

//same function as above but this time  its index based not title
Photo* PhotoArray::get(int index) const {
    if (index >= 0 && index < numPhotos) {
        return photoPointers[index];
    } else {
        return NULL;
    }
}

//removes photo with the given title from array and return pointer type
//return null if photo was not found given the title
Photo* PhotoArray::remove(const string& title) {
    for (int i = 0; i < numPhotos; i++) {
        if (photoPointers[i]->equals(title)) {
            Photo* removed_photo = photoPointers[i];
            for (int j = i; j < numPhotos-1; j++) {
                photoPointers[j] = photoPointers[j+1];
            }
            numPhotos--;
            return removed_photo;
        }
    }
    return NULL;
}

//same as above but index based instead of title.
Photo* PhotoArray::remove(int index) {
    //check if index is above or lower than 0 and max size
    if (index < 0 || index >= numPhotos) {
        return NULL;
    }

    Photo* removed_photo = photoPointers[index];
    for (int i = index; i < numPhotos-1; i++) {
        photoPointers[i] = photoPointers[i+1];
    }
    //decreaement numPhotos and return removed_photo
    numPhotos--;
    return removed_photo;
}



//return the size of the array 
int PhotoArray::size() const{
    return numPhotos;
};


