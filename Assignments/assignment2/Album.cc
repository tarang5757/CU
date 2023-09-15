#include "Album.h"

Album::Album(const string& title, const string& description){
    this->title = title;
    this->description = description;
    photo_array = new PhotoArray();
}

//copy constructor
Album::Album(const Album& album) {
    title = album.title;
    description = album.description;
    photo_array = new PhotoArray();
    
    for (int i = 0; i < album.photo_array->size(); i++) {
        photo_array->add(new Photo(*album.photo_array->get(i)));
    };
};

//destructor that frees memory
Album::~Album(){
    delete photo_array;
}

string Album::getTitle() const{
    return title;
}

string Album::getDescription() const{
    return description;
}

bool Album::equals(const string& title){
    //checking if equals
    if(this->title == title){
        return true;
    }
    else{
        return false;
    }
}

bool Album::lessThan(const Album& alb){
    return title < alb.title;  //this will just return boolean whatever output we get instead of using if.
}

bool Album::addPhoto(Photo* p){
    return photo_array->add(p); //add element in the array
}

bool Album::addPhoto(int index, Photo* p){
    return photo_array -> add(index, p); //will add at certain position.
    //same as sayinh photo_array.push(position, item); o(n)
}

Photo* Album::getPhoto(const string& title){
    return photo_array -> get(title);
};

Photo* Album::getPhoto(int index){
    return photo_array-> get(index);
};

Photo* Album::removePhoto(const string& title){
    return photo_array->remove(title);
};

Photo* Album::removePhoto(int index){
    return photo_array-> remove(index);
};

void Album::print() const{
cout << "Title: " << title << endl;
cout << "Description: " << description << endl;
};

int Album::size() const{
    return photo_array->size();
};

void Album::display() const{
//print the meta data mentioned in the assignment
print();
for(int i = 0; i < photo_array->size(); i++) {
    //looping to display all the photos
    photo_array->get(i)->display();
}
}

