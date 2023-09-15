#include "Client.h"
#include <iostream>

using namespace std;

//constructor of the client class that initializes album array
Client::Client() {
    albumArray = new AlbumArray();
}

//destructor that frees memory
Client::~Client() {
    for(int i = 0; i < albumArray->size(); i++){
        delete albumArray->get(i);
    }

    delete albumArray;

}

//this function basically download album from photogram to client
bool Client::downloadAlbum(PhotoGram* p, const string& album_title) {
    //download album from the photogram
    Album* album = p->downloadAlbum(album_title);
    //if album is null return false
    if (album == nullptr) {
        return false;
    }
    //checking to see if the client albumarray is full and if it is then return false and delete the album
    //free memory
    
    if (albumArray->isFull()) {
        delete album;
        return false;
        
    }
    //if the album of the same title already exists in client
    //then delete the album and return false
    if (albumArray->get(album_title) != nullptr) {
        delete album;
        return false;
    }
    
    //all the above conditions are not met then
    //we do our main operation which is adding new album to client albumarray and returning true.
    albumArray->add(new Album(*album));
    return true;
}

//display photo from photogram
bool Client::displayOnlinePhoto(PhotoGram* p, const string& album_title, const string& photo_title) {
    //download the photo from photogram
    Photo* photo = p->downloadPhoto(album_title, photo_title);
    if (photo == nullptr) {
        return false;
    }
    //display the photo and then delete it to free the memory
    photo->display();
    return true;
}


//display local photo from client album
bool Client::displayLocalPhoto(const string& album_title, const string& photo_title) {
    //get the album from client album array
    Album* album = albumArray->get(album_title);
    if (album == nullptr) {
        cout << "album was not found in client" << endl;
        return false;
    }
    Photo* photo = album->getPhoto(photo_title);
    if (photo == nullptr) {
        cout << "photo was not found in album" << endl;
        return false;
    }
    //display the photo if operation was successful
    photo->display();
    //delete photo; 
    return true;
}


void Client::printLocalAlbums() const{
    //print the localAlbums
    albumArray->print();
}

void Client::displayLocalAlbums() const{
    //display the photo in the console
    for (int i = 0; i < albumArray->size(); i++) {
        //iterate over album array and print ever item
        albumArray->get(i)->display();
        cout << endl;
    }
}