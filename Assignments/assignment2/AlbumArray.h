#include "Album.h"
#include "defs.h"
class AlbumArray {
public:
    //constructor and destructor
    AlbumArray();
    ~AlbumArray();

    //member functions
    bool isFull();
    bool add(Album* album);
    Album* get(const string& title);
    Album* get(int index);
    Album* remove(const string& title);
    Album* remove(int index);
    int size() const;
    void print() const;

private:
    //private members
    Album** albumPointers;
    int numAlbums;
};