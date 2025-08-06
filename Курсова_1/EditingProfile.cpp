//EditingProfile.cpp
#include "EditingProfile.h"

EditingProfile::EditingProfile() {}

EditingProfile::EditingProfile(string name, string devices, string level, string typeOfWork, int pin)
    : userName(name), userDevices(devices), userLevel(level), userTypeOfWork(typeOfWork), userPinCode(pin) {
}

void EditingProfile::changeDevices(string newDevice) {
    userDevices = newDevice;
    cout << "Device updated to: " << userDevices << endl;
}

void EditingProfile::changeLevel(string newLevel) {
    userLevel = newLevel;
    cout << "Level updated to: " << userLevel << endl;
}

void EditingProfile::changeTypeOfWork(string newType) {
    userTypeOfWork = newType;
    cout << "Type of Work updated to: " << userTypeOfWork << endl;
}

void EditingProfile::changePinCode(int newPin) {
    userPinCode = newPin;
    cout << "PIN Code updated." << endl;
}

void EditingProfile::changeName(string newName) {
    userName = newName;
    cout << "Name updated to: " << userName << endl;
}

void EditingProfile::editUserMenu(Profile& target) {
    while (true) {
        cout << "\n=== EDIT USER MENU ===\n";
        cout << "1. Name\n"
            << "2. Devices\n"
            << "3. Level\n"
            << "4. Type of work\n"
            << "5. PIN code\n"
            << "6. Exit\n"
            << "Enter option to edit: ";

        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 6) break;

        switch (choice) {
        case 1: {
            string name;
            cout << "Enter new name: ";
            getline(cin, name);
            changeName(name);
            target.setName(name);
            break;
        }
        case 2: {
            string devices;
            cout << "Enter new devices: ";
            getline(cin, devices);
            changeDevices(devices);
            target.setDevices(devices);
            break;
        }
        case 3: {
            string level;
            cout << "Enter new level: ";
            getline(cin, level);
            changeLevel(level);
            target.setLevel(level);
            break;
        }
        case 4: {
            string type;
            cout << "Enter new type of work: ";
            getline(cin, type);
            changeTypeOfWork(type);
            target.setTypeOfWork(type);
            break;
        }
        case 5: {
            int pin;
            cout << "Enter new PIN: ";
            cin >> pin;
            changePinCode(pin);
            target.setPinCode(pin);
            break;
        }
        default:
            cout << "Invalid option.\n";
        }
    }

    cout << "Editing completed.\n";
}
