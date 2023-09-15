#include "PhotoArray.h"
#ifndef ALBUM_H
#define ALBUM_H
using namespace std;

class Album{


    public:
    Album(const string& title, const string& description);
    Album(const Album& album);
    ~Album();
    
    //getters
    string getTitle() const;
    string getDescription() const;


    bool equals(const string& title);
    bool lessThan(const Album& alb);
    bool addPhoto(Photo*);
    bool addPhoto(int index, Photo* photo);
    Photo* getPhoto(const string& title);
    Photo* getPhoto(int index);
    Photo* removePhoto(const string& title);
    Photo* removePhoto(int index);
    void print() const;
    void display() const;
    int size() const;

    private:
    string title;
    string description;
    PhotoArray* photo_array;
    



};

#endif
