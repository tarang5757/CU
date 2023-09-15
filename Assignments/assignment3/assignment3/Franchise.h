#ifndef FRANCHISE_H
#define FRANCHISE_H

#include <string>
#include "Entity.h"
#include "defs.h"

using namespace std;

class Franchise : public Entity { //public Entity allows us to inhert all the functions from Entity
                                
public:
    Franchise(const string& name, const Location& location);
    Franchise(const string&);
    void print() const;
    static void printMenu();
    static string getMenu(int index);
    Location getLocation() const;

private:
    static const char code;
    static int nextId;
    static const string menu[MENU_ITEMS];
};

#endif