#ifndef CLIENT_H
#define CLIENT_H

#include "PhotoGram.h"
#include "Album.h"

using namespace std;

class Client {
  private:
    AlbumArray* albumArray;

  public:
    Client();
    ~Client();

    bool downloadAlbum(PhotoGram* p, const string& album_title);
    bool displayOnlinePhoto(PhotoGram* p, const string& album_title, const string& photo_title);
    bool displayLocalPhoto(const string& album_title, const string& photo_title);

    //display/print
    void printLocalAlbums() const;
    void displayLocalAlbums() const;
};

#endif