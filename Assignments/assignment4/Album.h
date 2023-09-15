#include "Array.h"
#include "Photo.h"
#ifndef ALBUM_H
#define ALBUM_H


using namespace std;

class Album{


    public:
    Album(const string& title, const string& description);
    
    //getters
    string getTitle() const;
    string getDescription() const;


    bool equals(const string& title);
    bool lessThan(const Album& alb);
    void addPhoto(Photo*);
    Photo* getPhoto(int index) const;
    void print(ostream& output) const;
    void display(ostream& output) const;
    int size() const;

    //output operators
    friend ostream& operator<<(ostream& os, const Album& album);

    private:
    string title;
    string description;
    Array<Photo*> photo_array;
    



};

#endif
