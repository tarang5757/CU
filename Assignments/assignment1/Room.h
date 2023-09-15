#ifndef ROOM_H
#define ROOM_H
#include "Reservation.h"
#include <iostream>
#include <string>
#include "defs.h" //for constants access.



using namespace std;

class Room{
private:
  int roomNumber;
  string bedType;
  int capacity;
  bool hasFridge;
  Reservation* reservations[MAX_RESERVATIONS];
  int numReservations;

public:
  Room(int roomNumber, string bedType, int capacity, bool hasFridge);
  ~Room();
  int getRoomNumber();
  bool isMatch(string bt, int cap, bool f);
  bool lessThan(Room& r);
  bool addReservation(string customerName, Date& d, int duration);
  void printReservations();
  string getBedType();
  int getCapacity();
  bool getFr();


};


#endif