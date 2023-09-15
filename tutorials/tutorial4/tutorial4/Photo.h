#ifndef PHOTO_H
#define PHOTO_H
#include <string>
#include <iostream>
#include "Date.h"

using namespace std;


class Photo{
    public:
    //constructor
    Photo(const string& title, const Date& date, const string& content);
    Photo();
    Photo(const Photo& copy);
    
    bool equals(const string&);
    void print();
    void display();


    private:
    string title;
    string content;
    Date date;

};

#endif