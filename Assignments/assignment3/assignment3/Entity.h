#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include "Queue.h"

using namespace std;


class Entity{

    public:
    Entity(char, int, const string&, const Location&);
    int getNumOrders() const;
    Order* getNextOrder();
    void addOrder(Order* order);
    void print() const;
    bool equals(const string& id_2) const;
    void setLocation(Location location);

    //getter
    Location getLocation()  const;
         
    



    protected:
    string id;
    string name;
    Location location;
    Queue orders;

    

};

#endif