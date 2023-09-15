#include "PhotoGram.h"

//photogram constructor that initializes the albumarray with new albumarray object
PhotoGram::PhotoGram(){
    albumArray = new AlbumArray();
};

//destructor that frees the memory
//efficient memory clean by looping and clearing every element
PhotoGram::~PhotoGram(){
    for (int i = 0; i < albumArray->size(); i++) {
        delete albumArray->get(i);
    };

    delete albumArray;
}


//adds album to albumarray with given title and description
bool PhotoGram::addAlbum(const string& title, const string& description){
Album* alb = new Album(title, description);
return albumArray->add(alb);
};

//this function removes the album given the title
bool PhotoGram::removeAlbum(const string& title) {
    Album* alb = albumArray->remove(title);
    //if alb is null then return false
    if (alb == nullptr) {
        return false;
    }
    //free memory and return true if successfully removed
    delete alb;
    return true;
};

//adds photo to album with the given album_title in albumarray
bool PhotoGram::addPhoto(const string& album_title, const Photo& photo){
Album* alb = albumArray->get(album_title);
    if (alb) {
        Photo* photo_pointer= new Photo(photo);
        //returns true if the photo is added successfully
        return alb->addPhoto(photo_pointer);
    }
    else {
        //else returns false
    cout << "Album was not found lol" << endl;
    return false;
    }
};

//removes the photo with given photo_title from the album with the given album_title in albumarray
bool PhotoGram::removePhoto(const string& album_title, const string& photo_title){
    //retrieves albumtitle
    Album* album = albumArray -> get(album_title);
    //if album is null it was not found and return false
    if (album == nullptr) {
        cout << "album was not found lol" << endl;
        return false;
    }
    else {
        //if photo was not found return false
        Photo* removed_photo = album->removePhoto(photo_title);
        if (removed_photo == nullptr) {
            cout << "photo was not found lol" << endl;
            delete removed_photo;
            return false;
        }
        else {
            //else operation worked and we can free memory and return true
            delete removed_photo; 
            return true;
        }
    }
}   

//returns pointer to album given the title in album array
Album* PhotoGram::downloadAlbum(const string& title){
    //returns nullptr if album was not found
    return albumArray->get(title);
};

//returns pointer to the photo given photo_title in the album with the given album_title  in the array
Photo* PhotoGram::downloadPhoto(const string& album_title, const string& photo_title){
//return null pointer if either album or photo was not found
    Album* album = albumArray->get(album_title);
    if (album == nullptr) {
      return nullptr;
    }
    return album->getPhoto(photo_title);
};

void PhotoGram::printAlbums() const{
    //print to console
    albumArray->print();
}

    //display to console by looping through all the elements and printing them.
  void PhotoGram::displayAlbums() const {
    for (int i = 0; i < albumArray -> size(); i++) {
    albumArray->get(i)->display();
    cout << endl;
    }
  }










