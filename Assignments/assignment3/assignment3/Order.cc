#include "Order.h"


Order::Order(const string& name, int item, const Location& loc)
    : customerName(name), menuItem(item), location(new Location(loc)) {
}

Order::~Order(){
    delete location;
}
Location* Order::getLocation() const{
    return location;
}

void Order::print() const{
    cout << "Customer name: " << customerName << endl;
}