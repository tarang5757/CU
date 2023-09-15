#include "Hotel.h"
#include <string>
#include <iostream>

using namespace std;

  //constructor
  Hotel::Hotel(){
    //initializes the number of rooms to 0
    numRooms = 0;
  };




  bool Hotel::addRoom(int roomNumber, string bedType, int capacity, bool fr){

  //this code was presented in zip file 6, p5, calender.cc brightspace  
  //we check if the max rooms in hotel is reached or not 
    if (numRooms >= MAX_ROOMS){
      //return false if not.
        return false;
        }
    ///creating new room object
    Room* newRoom = new Room(roomNumber, bedType, capacity, fr);

  //find index where new room needs to be added
    int index = 0;

     while (index < numRooms){
        if(newRoom->lessThan(*rooms[index])){
          //found position where to insert the new room
            break;
        }
        //increament index
        index++;
    }
    //move the rooms after the index to make room for incoming new rooms
    for (int i = numRooms; i > index; i--){
        rooms[i] = rooms[i-1];
    }

    //add room at the index
    rooms[index] = newRoom;

    //increament numRooms
    numRooms++;
    return true;

}

  //this function deletes the room
  bool Hotel::deleteRoom(int roomNumber) {
    //keeping track of the room index to be deleted
    int roomIndex = -1;
    //find the room with the given room number
    for (int i = 0; i < numRooms; i++) {
      if (rooms[i]->getRoomNumber() == roomNumber) {
        roomIndex = i;
        break;
      }
    }

    if (roomIndex == -1) {
      //room not found then return false
      return false;
    }

    //delete the room
    delete rooms[roomIndex];
    //move the rooms after the deleted room to the left
    for (int i = roomIndex; i < numRooms - 1; i++) {
      rooms[i] = rooms[i + 1];
    }
    //decrement the number of rooms
    numRooms--;
    //return true because the room was deleted successfully
    return true;
  }


  //this function gets a room with the given room number
  bool Hotel::getRoom(int roomNumber, Room** room) {
    //find the room with the given room number
    for (int i = 0; i < numRooms; i++) {
      if (rooms[i]->getRoomNumber() == roomNumber) {
        //set the room pointer to the found room
        *room = rooms[i];
        return true;
      }
    }

    //room not found then return false
    return false;
  }


    



//Function to add a reservation to room in the hotel
bool Hotel::addReservation(string customer, string bedType, int capacity, bool fr, Date& date, int duration){
    for(int i = 0; i < numRooms; i++){
        if(rooms[i]->isMatch(bedType, capacity, fr)){
            return rooms[i]->addReservation(customer, date, duration);
        }
    }
    return false;
}


  
//this function  prints the reservations in all rooms in the hotel
void Hotel::print() {
    for (int i = 0; i < numRooms; i++) {
      //print the reservations in each room
      rooms[i]->printReservations();
    }
  }

//destructor for memory leak
Hotel::~Hotel(){
for(int i = 0; i < numRooms; i++){
delete rooms[i];
}
}

//this function print the reservations in all rooms in the hotel
void Hotel::printReservations() {
    cout << "Hotel Reservations:" << endl;
    for (int i = 0; i < numRooms; i++) {
        cout << "Room " << rooms[i]->getRoomNumber() << ": " << endl;
        //print the reservations in each room
        rooms[i]->printReservations();
    }
}