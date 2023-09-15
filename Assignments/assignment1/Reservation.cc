#include "Reservation.h"
#include <iostream>
#include <string>

using namespace std;
Reservation::Reservation(string customerName, Date& checkIn, int duration) {
    this->customerName  = customerName;
    this->duration = duration;;
    this->checkIn = checkIn;
};



void Reservation::setDuration(int duration) {
   //setting the duration to 1 day atleast
    if (duration < 1) {
        duration = 1;
        cout << "less than 0" <<endl;
    }
    this-> duration = duration;
}


    //this function checks if two reservations overlap or not
bool Reservation::overlaps(Reservation& r) {
    Date checkOut = checkIn;
    checkOut.addDays(duration - 1);
    Date rCheckOut = r.checkIn;
    rCheckOut.addDays(r.duration - 1);

    return !(rCheckOut.lessThan(checkIn) || checkOut.lessThan(r.checkIn));
};




bool Reservation::lessThan(Reservation& res){
    //if reservations overlap then we return false
    if (overlaps(res)) {
        return false;
    }
    //compare the check in dates of the two Reservations
    return checkIn.lessThan(res.checkIn);
};



bool Reservation::lessThan(Date& d) {
    Date end = checkIn;
    end.addDays(duration - 1);
    //return true if end of this reservation happens before d
    return end.lessThan(d);
};

string Reservation::getCustomerName(){
    return customerName;
}






Reservation::~Reservation() {
    //destructor to deallocate memory
}

void Reservation::print(){
    cout << "Reservation for " << customerName << " on " << checkIn.getMonth()  << " " << checkIn.getDay() << ", " << checkIn.getYear() <<  " for " << duration << " days." << endl;
};

