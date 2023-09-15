#include "PhotoGram.h"


PhotoGram::PhotoGram(){
};

//destructor that frees the memory
PhotoGram::~PhotoGram(){
    for (int i = 0; i < albumArray.size(); i++) {
        delete albumArray[i];
    };

    for(int i = 0; i < photos.size(); i++){
        delete photos[i];
    }
}

//add to album method that adds photo to album
void PhotoGram::addToAlbum(int index, Array<Photo*>& p){
    Album* album = albumArray[index];
    for (int i = 0; i < p.size(); i++) {
        album->addPhoto(p[i]);
    }

}

void PhotoGram::deleteAlbum(int index){
    if (index < 0 || index >= albumArray.size()) {
        cout << "Index out of bounds" << endl;
        return;
    }
        albumArray -= albumArray[index];    
    
}



//adds album to albumarray with given title and description
void PhotoGram::addAlbum(const string& title, const string& description){
Album* album = mediaFactory.createAlbum(title, description);
albumArray.add(album);

};

void PhotoGram::uploadPhoto(const string& title){
    Photo* photo = mediaFactory.uploadPhoto(title);
    photos.add(photo);
}

void PhotoGram::getPhotos(const Criteria& criteria, Array<Photo*>& p){
    for (int i = 0; i < photos.size(); i++) {
        if(criteria.matches(*photos[i])) {
            p += photos[i];
        }
    }

}



 int PhotoGram::printAlbums(View& view)const{
    //print to console
    view.printAlbums(albumArray);
    return albumArray.size();

}
int PhotoGram::printPhotos(View& view) const{
    view.printPhotos(photos);
    return photos.size();
    
}

    //display to console by looping through all the elements and printing them.
  void PhotoGram::displayAlbum(int index, View& view)const{
    if(index < 0 || index >= albumArray.size()){
        cout << "Index out of bounds" << endl;
        return;
    }
    //convert to object
    Album& album = *(albumArray[index]);
    view.displayAlbum(album);

  }

   void PhotoGram::displayPhoto(int index, View& view)const{
    if(index < 0 || index >= photos.size()){
        cout << "Index out of bounds" << endl;
    }
    
    Photo& photo = *(photos[index]);
    view.displayPhoto(photo);
   }














