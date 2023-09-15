#ifndef HEAPARRAYS_H
#define HEAPARRAYS_H

#include "Photo.h"
#include "defs.h"

class HeapArrays {
  public:
    HeapArrays();
    ~HeapArrays();

    Photo* getObjectArray();
    Photo** getPointerArray();
    void addPhoto( Photo&);
  
  private:
    Photo* photos;
    Photo** photoPointer;
    int numPhotos;
};

#endif