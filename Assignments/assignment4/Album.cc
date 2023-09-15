#include "Album.h"

Album::Album(const string& title, const string& description){
    this->title = title;
    this->description = description;
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

void Album::addPhoto(Photo* p){
    photo_array.add(p); //add element in the array
}



Photo* Album::getPhoto(int index) const{
    return photo_array[index];
};


void Album::print(ostream& output) const{
output << "Title: " << title << endl;
output << "Description: " << description << endl;
output << "# Photos: " << size() << endl;
};


int Album::size() const{
    return photo_array.size();
};

//this needs to get checked again
void Album::display(ostream& output) const{
print(output);
for(int i = 0; i < size(); i++) {
    output << "Photo " << i+1 << ":" << endl;
    getPhoto(i)->display(output);
}
}

ostream& operator<<(ostream& os, const Album& album) {
    album.print(os);
    return os;
}

