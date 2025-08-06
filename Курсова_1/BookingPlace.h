//BookingPlace.h
#ifndef BOOKINGPLACE_H
#define BOOKINGPLACE_H

#include <string>
using namespace std;

class BookingPlace {
private:
    string city;
    string address;
    int floor;
    int table;

public:
    BookingPlace();
    BookingPlace(string c, string a, int f, int t);

    void showBooking();
    void bookPlaceIfNeeded(string typeOfWork);
};

#endif
