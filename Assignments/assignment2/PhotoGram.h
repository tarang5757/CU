#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H
#include "AlbumArray.h"
#include "defs.h"

using namespace std;

class PhotoGram{
    public:
    PhotoGram();
    ~PhotoGram();

    bool addAlbum(const string& title, const string& description);
    bool removeAlbum(const string& title);
    bool addPhoto(const string& album_title, const Photo& photo);
    bool removePhoto(const string& album_title, const string& photo_title);
    Album* downloadAlbum(const string& title);
    Photo* downloadPhoto(const string& album_title, const string& photo_title);

    void printAlbums() const ; 
    void displayAlbums() const; 



    private:
    AlbumArray* albumArray;
};


#endif