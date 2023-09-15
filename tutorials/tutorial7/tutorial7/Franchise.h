#ifndef FRANCHISE_H
#define FRANCHISE_H

#include <string>
#include "Entity.h"
#include "defs.h"

using namespace std;

class Franchise : public Entity {
public:
    Franchise(const string& name, const Location& location);
    Franchise(const string&);
    bool isFree() const;
    void print() const;
    static void printMenu();
    static string getMenu(int index);
    //getter
    Location getLocation();

private:
    static const char code = 'F';
    static int nextId;
    static const string menu[MENU_ITEMS];
};

#endif