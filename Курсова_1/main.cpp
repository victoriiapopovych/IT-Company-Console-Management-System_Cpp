// main.cpp
#include "Profile.h"
#include "System.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<Profile> employees = System::getEmployees();


    int pin;
    cout << "==============================\n";
    cout << " Welcome to IT Company System \n";
    cout << "==============================\n";
    cout << "Enter your PIN to log in: ";
    cin >> pin;

    bool found = false;
    for (auto& emp : employees) {
        if (emp.getPinCode() == pin) {
            System s;
            s.menu(emp, employees); 
            found = true;
            break;
        }
    }


    if (!found) {
        cout << "Access denied: wrong PIN.\n";
    }

    return 0;
}
