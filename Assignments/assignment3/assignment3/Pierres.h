#ifndef PIERRES_H
#define PIERRES_H

#include "Driver.h"
#include "Franchise.h"

#define MAX_DRIVERS 128
#define MAX_FRANCHISES 128

class Pierres{
    public:
    Pierres();
    ~Pierres();
    void addDriver(const string& name, const Location& location);
    void addFranchise(const string& name, const Location& location);
    void takeOrder(const string& customerName, int menuItem, const Location&);
    void driverPickup(const string& franchiseId, int numOrders);
    void driverDeliver(const string& driverId, int numOrders);
    void printFranchises() const;
    void printDrivers() const;
    Driver* closestDriver(const Franchise* franchise);


    private:

    Driver** drivers;
    Franchise** franchises;
    int numDrivers;
    int numFranchises;

};

#endif