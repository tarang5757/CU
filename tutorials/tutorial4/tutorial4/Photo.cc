#include "Photo.h"

Photo::Photo(const string& title, const Date& date, const string& content)
    : title(title), date(date), content(content) {

    };

bool Photo::equals(const string& title){
    if(this->title == title){
        return true;
    }
    else{
        return false;
    }

};

//copy constructor
Photo::Photo(const Photo& copy){
    content = "RCMP";
    title = copy.title;
    date = copy.date;
    
    
}

//no argument constructor
Photo::Photo() : title(""), date(), content("") {
}

void Photo::print(){
        cout << "Title: " << title << endl;
        cout << "Date: ";
        date.print();
        cout << endl;
}

void Photo::display(){
    print();
    cout << "Content: " << content << endl;
}

