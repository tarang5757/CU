#ifndef HOTEL_H
#define HOTEL_H
#include "Reservation.h"
#include "Room.h"
#include "Date.h"
#include <string>
#include "defs.h"

class Hotel {
  public:
    Hotel();
    //destructor
    ~Hotel();
    

    bool addRoom(int roomNumber, string bedType, int capacity, bool fr);
    bool deleteRoom(int roomNumber);
    bool getRoom(int roomNumber, Room** room);
    bool addReservation(string customer, string bedType, int capacity, bool fr, Date& date, int duration);
    void print();
    void printReservations();
    

    private:
    Room* rooms[MAX_ROOMS];
    int numRooms;
};





#endif