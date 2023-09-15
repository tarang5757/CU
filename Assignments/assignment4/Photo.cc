#include "Photo.h"

Photo::Photo(const string& title, const string& category, const Date& date, const string& content)
    : title(title), category(category), date(date), content(content) {

    };

bool Photo::equals(const string& title) const{
    if(this->title == title){
        return true;
    }
    else{
        return false;
    }

};


//getters
const string& Photo::getCategory() const {
    return category;
}

const Date& Photo::getDate() const{
    return date;
}



void Photo::print(ostream& os) const{
    
    cout << "Title: " << title << endl;
    cout << "Category: " << category << endl;
    cout << "Date: " << date << endl;
}

void Photo::display(ostream& os) const{
    print(os);
    os << "Content: " << content << endl;
}

ostream& operator<<(ostream& os, const Photo& photo) {
    photo.print(os);
    return os;
}

