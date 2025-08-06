//SystemAdmin.cpp
#include "SystemAdmin.h"
#include <iostream>
#include <string>

using namespace std;

void SystemAdmin::showUserInfo(Profile employees[], int size) {
    cout << "\n=== SYSADMIN - User Information ===\n";
    for (int i = 0; i < size; i++) {
        cout << "Name: " << employees[i].getName() << "\n";
        cout << "Email: " << employees[i].getEmail() << "\n";
        cout << "Level: " << employees[i].getLevel() << "\n";
        cout << "Work Type: " << employees[i].getTypeOfWork() << "\n";
        cout << "PIN Code: " << employees[i].getPinCode() << "\n";
        cout << "Devices: " << employees[i].getDevices() << "\n";
        cout << "===============================\n";
    }
}


void SystemAdmin::deleteProfile(Profile employees[], int size, string email) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (employees[i].getEmail() == email) {
            cout << "\nDeleting profile of: " << employees[i].getName() << " (" << employees[i].getEmail() << ")" << endl;
            
            for (int j = i; j < size - 1; ++j) {
                employees[j] = employees[j + 1];
            }
            found = true;
            size--;  
            break;
        }

    }
    if (!found) {
        cout << "Profile with email " << email << " not found.\n";
    }
}



void SystemAdmin::addRequest(const string& sender, const string& device, const string& reason) {
    requests.push_back({ sender, device, reason, false, false });
}

void SystemAdmin::viewAndHandleRequests() {
    cout << "\n=== REQUESTS ===" << endl;
    cout << "Here are all the requests you have:\n";
    cout << "----------------------------\n";
    if (requests.empty()) {
        cout << "No requests available.\n";
        return;
    }

    for (size_t i = 0; i < requests.size(); ++i) {
        cout << "\nRequest #" << i + 1 << ":\n";
        cout << "From: " << requests[i].senderName << "\n";
        cout << "Device: " << requests[i].deviceRequested << "\n";
        cout << "Reason: " << requests[i].reason << "\n";
        cout << "Status: "
            << (requests[i].isHandled ?
                (requests[i].isApproved ? "Approved" : "Rejected") : "Pending") << "\n";
    }

    while (true) {
        cout << "\nEnter request number to handle (0 to exit): ";
        int index;
        cin >> index;

        if (index == 0) break;

        if (index < 1 || index > requests.size()) {
            cout << "Invalid request number.\n";
            continue;
        }

        Request& req = requests[index - 1];
        if (req.isHandled) {
            cout << "This request has already been handled.\n";
            continue;
        }

        cout << "1. Approve\n2. Reject\nYour choice: ";
        int decision;
        cin >> decision;

        if (decision == 1) {
            req.isApproved = true;
            req.isHandled = true;
            cout << "Request approved.\n";
        }
        else if (decision == 2) {
            req.isApproved = false;
            req.isHandled = true;
            cout << "Request rejected.\n";
        }
        else {
            cout << "Invalid decision.\n";
        }
    }
}
