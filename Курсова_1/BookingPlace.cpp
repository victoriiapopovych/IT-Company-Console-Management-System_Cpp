//BookingPlace.cpp
#include "BookingPlace.h"
#include <iostream>
using namespace std;

BookingPlace::BookingPlace() {}

BookingPlace::BookingPlace(string c, string a, int f, int t)
    : city(c), address(a), floor(f), table(t) {
}

void BookingPlace::showBooking() {
    cout << "City: " << city << "\nAddress: " << address
        << "\nFloor: " << floor << "\nTable: " << table << endl;
}

void BookingPlace::bookPlaceIfNeeded(string typeOfWork) {
    if (typeOfWork == "office based") {
        // Якщо користувач офісний, просто надаємо його місце
        BookingPlace fixed("Kyiv", "Shevchenka 10", 2, 2);
        cout << "\nYou are office-based. Your assigned place:\n";
        fixed.showBooking();
    }
    else {
        // Для інших типів роботи показуємо меню з вибором міста, адреси і столика
        int cityChoice, addressChoice, floorChoice, tableChoice;

        // Меню вибору міста
        cout << "\nAvailable cities:\n";
        cout << "1. Kyiv\n2. Lviv\n3. Odesa\n";
        cout << "Select a city (1-3): ";
        cin >> cityChoice;

        // Меню вибору адреси в обраному місті
        cout << "\nAvailable addresses:\n";
        switch (cityChoice) {
        case 1:
            cout << "1. Shevchenka 10\n2. Khreshchatyk 1\n";
            break;
        case 2:
            cout << "1. Lvivska 15\n2. Halytska 12\n";
            break;
        case 3:
            cout << "1. Odesa 23\n2. Deribasovska 45\n";
            break;
        default:
            cout << "Invalid city choice.\n";
            return;
        }
        cout << "Select an address (1-2): ";
        cin >> addressChoice;

        // Меню вибору поверху
        cout << "\nAvailable floors:\n1. 1st Floor\n2. 2nd Floor\n3. 3rd Floor\n";
        cout << "Select a floor (1-3): ";
        cin >> floorChoice;

        // Меню вибору столика
        cout << "\nAvailable tables:\n1. Table 1\n2. Table 2\n3. Table 3\n";
        cout << "Select a table (1-3): ";
        cin >> tableChoice;

        // Підтверджуємо бронювання
        BookingPlace temp(cityChoice == 1 ? "Kyiv" : cityChoice == 2 ? "Lviv" : "Odesa",
            addressChoice == 1 ? (cityChoice == 1 ? "Shevchenka 10" : cityChoice == 2 ? "Lvivska 15" : "Odesa 23") :
            (cityChoice == 1 ? "Khreshchatyk 1" : cityChoice == 2 ? "Halytska 12" : "Deribasovska 45"),
            floorChoice, tableChoice);
        cout << "\nBooking confirmed:\n";
        temp.showBooking();
    }
}
