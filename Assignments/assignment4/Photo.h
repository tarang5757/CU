#ifndef PHOTO_H
#define PHOTO_H
#include <string>
#include <iostream>
#include "Date.h"

using namespace std;


class Photo{
    public:
    //constructor
    Photo(const string& title, const string& category, const Date& date, const string& content);

    
    bool equals(const string&) const;
    void print(ostream& os) const;
    void display(ostream& os) const;

    //getters
    const string& getCategory() const;
    const Date& getDate() const;

    //operator overload
    friend ostream& operator<<(ostream& os, const Photo& photo);


    

    private:
    string title;
    string content;
    Date date;
    string category;


};


#endif