#include "Entity.h"

Entity::Entity(char c, int num, const string& name, const Location& location){
    this->name = name;
    this->location = location;
    this->id = c + to_string(num);
}


;
int Entity::getNumOrders() const{
    //get the size
    return orders.size();
}

Order* Entity::getNextOrder(){
    //remove the first element so we can look at the next item.
    return orders.popFirst();
}

void Entity::addOrder(Order* order){
    //add the order to the end of the queue
    orders.addLast(order);
}

Location Entity::getLocation() const{
    return location;
}


void Entity::setLocation(Location location){
    this->location = location;
}


void Entity::print() const{
    //print the location first
    cout << "Location: ";
    location.print();
    cout << endl;
    //number of orders
    cout << "Orders: " << orders.size() << endl;

};



bool Entity::equals(const string& id_2) const{
    return id == id_2;
}





