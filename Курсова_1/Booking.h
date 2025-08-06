#ifndef BOOKING_H
#define BOOKING_H

#include "Profile.h"

class CBookingPlace : public CProfile {
public:
    void bookPlace() {
        if (getTypeOfWork() == "Office") {
            cout << "\nYou are assigned to: Kyiv, Office 3, Table 14\n";
        }
        else {
            string city, street;
            int table;
            cout << "\n=== BOOK A PLACE ===" << endl;
            cout << "Enter city: ";
            cin >> city;
            cout << "Enter street: ";
            cin >> street;
            cout << "Choose table number (1-20): ";
            cin >> table;
            cout << "Booking confirmed: " << city << ", " << street << ", Table " << table << endl;
        }
    }
};

#endif
