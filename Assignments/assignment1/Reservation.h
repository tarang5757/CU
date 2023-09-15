#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Reservation{

    public:
    //constructor
    Reservation(string customerName, Date& checkIn, int duration);
    //destructor
    ~Reservation();
    //functions definitions
    void setDuration(int duration);
    bool overlaps(Reservation& r);
    bool lessThan(Reservation& res);
    bool lessThan(Date& d);
    void print();
    string getCustomerName();





    private:
    string customerName;
    Date checkIn;
    int duration;

};

#endif