#include <iostream>
#include "Franchise.h"

using namespace std;

int Franchise::nextId = 0;
const string Franchise::menu[MENU_ITEMS] = {"1. Large Poutine", "2. Medium Poutine", "3. Small Poutine"};

Franchise::Franchise(const string& name, const Location& location)
    : Entity(code, nextId++, name, location)
{
}

bool Franchise::isFree() const {
    return orders.empty();
}

void Franchise::print() const {
    cout << "Franchise Name: " << name << endl;
    cout << "Franchise Location: ";
    location.print();
    cout << "Number of Orders: " << orders.size() << endl;
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
