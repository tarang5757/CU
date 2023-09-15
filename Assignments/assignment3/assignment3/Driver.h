#ifndef DRIVER_H
#define DRIVER_H
#include <string>
#include "Entity.h"

using namespace std;

class Driver: public Entity{ //public Entity allows us to inhert Entity functions in our driver class
    public:
    Driver(const string& name, const Location& location);
    Driver(const string&);
    bool isFree() const;
    void print() const;
    


    private:
    static const char code;
    static int nextId;

};



#endif