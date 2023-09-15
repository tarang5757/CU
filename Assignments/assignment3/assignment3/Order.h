#ifndef ORDER_H
#define ORDER_H
#include "Location.h"
#include <iostream>
#include <string>

using namespace std;

class Order{
    public:
    Order(const string&, int, const Location&);
    ~Order();
    Location* getLocation() const;
    void print() const;



    private:
    const string& customerName;
    int menuItem;
    Location* location;


};


#endif