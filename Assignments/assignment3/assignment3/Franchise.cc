#include <iostream>
#include "Franchise.h"

using namespace std;

//initialize static members
int Franchise::nextId = 1;
const char Franchise::code = 'F';
const string Franchise::menu[MENU_ITEMS] = 
{
"1. Large Poutine", 
"2. Medium Poutine",
"3. Small Poutine"
};

//constructor with name and location
Franchise::Franchise(const string& name, const Location& location) : Entity(code, nextId++, name, location) {
};

//constructor with name only
Franchise::Franchise(const string& name) : Entity(code, nextId++, name, Location()) {

};

//getter for location
Location Franchise::getLocation() const{
    return location;
}

//
void Franchise::print() const {
    cout << "Franchise Name: " << name << endl;
    cout << "Franchise ID: " << id << endl; 
    cout << "Franchise Location: ";
    location.print(); 
    cout << endl;
    cout << "Orders: " << orders.size() << endl;
    cout << endl;
}

void Franchise::printMenu() {
    for (int i = 0; i < MENU_ITEMS; i++) {
        cout << menu[i] << endl;
    }
}

string Franchise::getMenu(int index) {
    if (index >= 0 && index < MENU_ITEMS) {
        return menu[index];
    } else {
        return "unknown menu item";
    }
}
