#include "Pierres.h"


//constructor that initializes member variables
Pierres::Pierres() {
    numDrivers = 0;
    numFranchises = 0;
    drivers = new Driver*[MAX_DRIVERS];
    franchises = new Franchise*[MAX_FRANCHISES];

    
};

//destructor that frees the memory
Pierres::~Pierres(){
    for (int i = 0; i < numDrivers; i++) {
            delete drivers[i];
    }
    delete[] drivers;

    for (int i = 0; i < numFranchises; i++) {
        delete franchises[i];
    }
    delete[] franchises;
    
}


void Pierres::addDriver(const string& name, const Location& location){
        if (numDrivers < MAX_DRIVERS) {
            drivers[numDrivers] = new Driver(name, location);
            numDrivers++;
        } else {
            cerr << "sorry we reached the maximum number of drivers" << endl;
        }
}

void Pierres::addFranchise(const string& name, const Location& location){
        if (numFranchises < MAX_FRANCHISES) {
            franchises[numFranchises] = new Franchise(name, location);
            numFranchises++;
        } else {
            cerr << "Sorry we reached the maximum number of franchises" << endl;
        }
}

void Pierres::takeOrder(const string& customerName, int menuItem, const Location& location){
    // Find the closest Franchise to the given location
    Franchise* closestFranchise = nullptr;
    //just give it a very big number lol cause its going to change anyway
    int minimumDistance = 1000;

    for (int i = 0; i < numFranchises; i++) {
        int distance = franchises[i]->getLocation().getDistance(location);
        if (distance < minimumDistance) {
            closestFranchise = franchises[i];
            minimumDistance = distance;
        }
    }
    // Create a new order with the given criteria
    Order* newOrder = new Order(customerName, menuItem, location);
    // Add the new order to the closest Franchise
    closestFranchise->addOrder(newOrder);

    delete newOrder;



}

void Pierres::driverPickup(const string& franchiseId, int numOrders) {

    //let franchise store the id
    Franchise* franchise;

    for (int i = 0; i < numFranchises; i++) {
        if (franchises[i]->equals(franchiseId)) {
            //when we find the id then we break out of the loop
            franchise = franchises[i];
            break;
        }
    }

    //if there is no Franchise with the given id,
    //output an error message
    if (franchise == nullptr) {
        cerr << "Franchise Id not not found" << endl;
        return;
    }

    
    //finding the closest available driver
    //closestAvailableDriver
    Driver* closestAvailableDriver = closestDriver(franchise);

    //checking if any driver was found
    if (closestAvailableDriver == nullptr) {
        cerr << "No available driver found" << endl;
        return;
    }

    //created a function for this entire commented code.
    /*
    //basically going to store the maximum value for now because its going to be changed later in the if condition.
    int closestDistance = 2147483647;
    for (int i = 0; i < numDrivers; i++) {
        //iterating over number of drivers and checking  if driver is free
        if (drivers[i]->isFree()) {
            //Checking how close he is to the franchise so he can pickup the order.
            int driverDistance = franchise->getLocation().getDistance(drivers[i]->getLocation());
            //if driverDistance is less than closestDistance then closest distance becomes driver
            if (driverDistance < closestDistance) {
                closestDistance = driverDistance;
                closestAvailableDriver = drivers[i];
            }
        }
    }

    //If no available driver was found then display error message in the output
    if (closestAvailableDriver == nullptr) {
        cerr << "No available driver found" << endl;
        return;
    }
    */


    //change their Location to match the Franchise
    //Location so he can pickup the orders
    closestAvailableDriver->setLocation(franchise->getLocation());

    //transfer orders from the franchise to the driver
    int numOrdersInFranchise = franchise->getNumOrders();

    int transferredOrders;

    //get the minimum between numOrders and numOrdersInFranchise so we can transfer the right amount of orders
    if(numOrdersInFranchise > numOrders){
        transferredOrders = numOrders;
    }

    else if(numOrders > numOrdersInFranchise){
        transferredOrders = numOrdersInFranchise;
    }

    else{
        //then they are both the same value and we can assign it to any
        transferredOrders = numOrders;
    }

    //loop through and transfer orders to driver
    for (int i = 0; i < transferredOrders; i++) {
        Order* order = franchise->getNextOrder();
        closestAvailableDriver->addOrder(order);
    }
}


Driver* Pierres::closestDriver(const Franchise* franchise){
    //finding the closest available driver
    //closestAvailableDriver
    Driver* closestAvailableDriver;
    //basically going to store the maximum value for now because its going to be changed later in the if condition.
    int closestDistance = 1000;
    for (int i = 0; i < numDrivers; i++) {
        //iterating over number of drivers and checking  if driver is free
        if (drivers[i]->isFree()) {
            //Checking how close he is to the franchise so he can pickup the order.
            int driverDistance = franchise->getLocation().getDistance(drivers[i]->getLocation());
            //if driverDistance is less than closestDistance then closest distance becomes driver
            if (driverDistance < closestDistance) {
                closestDistance = driverDistance;
                closestAvailableDriver = drivers[i];
            }
        }
    }

    //If no available driver was found then display error message in the output
    if (closestAvailableDriver == nullptr) {
        cerr << "No available driver found" << endl;
        return nullptr;
    }
    return closestAvailableDriver;

}



void Pierres::driverDeliver(const string& driverId, int numOrders){
    //first we are going to check if the driver with the given Id exists
    //make an instance of driver to assign if it matches id;
    Driver* driver;
    for (int i = 0; i < numDrivers; i++) {
        if (drivers[i]->equals(driverId)) {
            //found the matching id so we assign
            driver = drivers[i];
            break;
        }
    }

    //if the driver was not found thenoutput an error message and return
    if (!driver) {
        cout << "Error: Driver with the given id " << driverId << " was not found" << endl;
        return;
    }

    //deliver the orders now
    int deliveredOrders = 0;

    while (!driver->isFree() && deliveredOrders < numOrders) {
        //get the next order and its location
        Order* order = driver->getNextOrder();

        Location* orderLocation = order->getLocation();
        // delivering the order
        cout << "Delivering: ";

        //update the driver location to the order location
        driver->setLocation(*orderLocation);

        //increment the number of delivered orders to keep track of how many we did.
        deliveredOrders++;
    }

    //output the driver's new location
    cout << "Driver's new location: ";
    driver->getLocation().print();
    

};

void Pierres::printFranchises() const{
    //print the franchises
    for (int i = 0; i < numFranchises; i++) {
            franchises[i]->print();
    }
};

void Pierres::printDrivers() const {
    //print the drivers
    for (int i = 0; i < numDrivers; i++) {
            drivers[i]->print();
    }
};







