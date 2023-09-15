#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H
#include "Array.h"
#include "Album.h"
#include "View.h"
#include "MediaFactory.h"
#include "Photo.h"
#include "defs.h"

using namespace std;

class PhotoGram{
    public:
    PhotoGram();
    ~PhotoGram();

    void addAlbum(const string& title, const string& description);
    void addToAlbum(int index, Array<Photo*>& p);
    void uploadPhoto(const string& title);
    void deleteAlbum(int index);
    void getPhotos(const Criteria& criteria, Array<Photo*>& p);

    
    void displayAlbum(int index, View& view) const;
    void displayPhoto(int index, View& view)const ;
    int printPhotos(View& view) const;
    int printAlbums(View& view) const; 
    
    
    



    private:
    Array<Album*> albumArray;
    Array<Photo*> photos;
    MediaFactory mediaFactory;

};


#endif