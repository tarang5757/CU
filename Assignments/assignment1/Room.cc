#include <iostream>
#include <string>
#include "Room.h"

using namespace std;

// constructor for room class
Room::Room(int roomNumber, string bedType, int capacity, bool hasFridge)
{
    this->roomNumber = roomNumber;
    this-> bedType = bedType;
    this->capacity = capacity;
    this->hasFridge = hasFridge;
    numReservations = 0;
    // setting every reservation to null so we don't get a segmentation fault and allocate only when needed
    for (int i = 0; i < MAX_RESERVATIONS; i++) 
    {
        reservations[i] = nullptr;
    }
}

int Room::getRoomNumber()  
{
    return roomNumber;
}

bool Room::isMatch(string bt, int cap, bool fr) 
{
    /*
    If f is true then a fridge is required, so hasFridge must also be true. If f is false then hasFridge may
    be true or false. That is, we don’t mind if the room has a fridge even if we did not request it, but if we
    requested a fridge then the Room must have it.
    */

    // satisfies the condition.
    if (bedType != bt || capacity < cap || (fr == true && hasFridge == false)) 
    {
        return false;
    }
    return true;
}

bool Room::lessThan(Room& r) 
{
    return roomNumber < r.roomNumber;
}

bool Room::addReservation(string customerName, Date& d, int duration) 
{
    //checking if the customer has already made a reservation in the room or not
    //iterating through all existing reservations
    for (int i = 0; i < numReservations; i++) 
    {
        //comparing the customer name of the current reservation with given customer name in parameter
        if (reservations[i]->getCustomerName() == customerName) 
        {
            //customer already has a reservation in room
            return false;
        }
    }
    //checking if the number of reservations has reached max limits which is 64
    if (numReservations == MAX_RESERVATIONS) 
    {
        //if reached we return false
        return false;
    }

    //creating new reservation
    Reservation* newReservation = new Reservation(customerName, d, duration);
    //find index where new reservation needs to be added
    int index;
    for (index = 0; index < numReservations; index++) 
    {
        //check if new reservation is less than current one
        if (newReservation->lessThan(*reservations[index])) 
        {   //if it is then we break out of the loop
            break;
        }
        //checking for overlaping
        if (newReservation->overlaps(*reservations[index])) 
        {   //deallocate memory and return false
            delete newReservation;
            return false;
        }
    }

    //move the reservations after the index to make room for incoming new reservation
    for (int j = numReservations; j > index; j--) 
    {
        reservations[j] = reservations[j-1];
    }
    //add reservation at the index
    reservations[index] = newReservation;
    //increament
    numReservations++;

    //the reservation was added with no problems so we return true
    return true;
}

// getters that we need
string Room::getBedType() 
{
    return bedType;
}

int Room::getCapacity() 
{
    return capacity;
}

bool Room::getFr() 
{
    return hasFridge;
}



//clear memory. destructor
Room::~Room(){
    for (int i = 0; i < numReservations; i++) {
        delete reservations[i];
    }

}
//print the reservations
void Room::printReservations() {
    cout << "Room Number: " << roomNumber << endl;
    cout << "Bed Type: " << bedType << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Has Fridge: " << hasFridge << endl;
    cout << "Reservations: " << endl;
    for (int i = 0; i < numReservations; i++) {
        cout << "  ";
        reservations[i]->print();
    }
};