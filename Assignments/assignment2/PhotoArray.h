#ifndef PHOTOARRAY_H
#define PHOTOARRAY_H

#include "Photo.h"
#include "defs.h"
using namespace std;
class PhotoArray{

    public:

    //constructor
    PhotoArray();
    ~PhotoArray();
    
    //methods
    bool isFull() const;

    bool add(Photo* photo);
    bool add(int index, Photo*);

    Photo* get(const string& title) const;
    Photo* get(int index) const;

    Photo* remove(const string& title);
    Photo* remove(int index);

    int size() const;


    private:
    Photo **photoPointers;
    int numPhotos;
};

#endif