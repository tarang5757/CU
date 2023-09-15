#include "Driver.h"

int Driver::nextId = 1;
const char Driver::code = 'D';

Driver::Driver(const string& name, const Location& location) : Entity(code, nextId++, name, location) {

}


Driver::Driver(const string& name) : Entity(code, nextId++, name, Location()) {}


bool Driver::isFree() const{
    return orders.empty();
};



void Driver::print() const{
    cout << "Driver: " << name << endl;
    cout << "ID: " << id << endl;
    Entity::print();
    cout << endl;
    


};