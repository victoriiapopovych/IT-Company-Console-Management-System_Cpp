//System.cpp
#include "System.h"
#include <iostream>
#include <vector>
#include "ProjectManager.h"
#include "SystemAdmin.h"

using namespace std;

void System::menu(Profile& user, vector<Profile>& allUsers) {
    ReportTime report;
    BookingPlace place;
    ProjectManager pm;
    SystemAdmin admin;
    string role = user.getPosition();

    while (true) {
        int choice;
        cout << "\n=== MENU ===\n"
            << "1. Profile\n"
            << "2. Booking place\n"
            << "3. SysAdmin team \n"
            << "4. Report time\n";

        if (role == "Project Manager") {
            cout << "5. Projects\n"
                << "6. Edit projects\n"
                << "7. Working time\n"
                << "8. Logout\n";
        }
        else if (role == "System Admin") {
            cout << "5. Edit profile\n"
                << "6. View requests\n"
                << "7. Control panel\n"
                << "8. Logout\n";
        }
        else if (role == "Developer") {
            cout << "5. Logout\n";
        }

        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "\n=== PROFILE INFO MENU ===" << endl;
            cout << "1. Name\n"
                << "2. Email\n"
                << "3. Position\n"
                << "4. Projects\n"
                << "5. Level\n"
                << "6. Skills\n"
                << "7. Location\n"
                << "8. Type of Work\n"
                << "9. Benefit Package\n"
                << "10. Devices\n";

            int infoOption;
            cin >> infoOption;
            user.showProfile(infoOption);
            break;
        }

        case 2: {
            place.bookPlaceIfNeeded(user.getTypeOfWork());
            break;
        }

        case 3: {
            cout << "\n=== SYSTEM ADMIN TEAM ===" << endl;
            cout << "1. My device is broken\n";
            cout << "2. Request device\n";
            cout << "Choose option: ";
            int helpOption;
            cin >> helpOption;
            cin.ignore();

            if (helpOption == 1) {
                string problem;
                cout << "Describe the problem with your device: ";
                getline(cin, problem);
                cout << "Request for repair sent: " << problem << endl;
                admin.addRequest(user.getName(), user.getDevices(), "Repair: " + problem);
            }
            else if (helpOption == 2) {
                string reason, device;
                cout << "For what you want to request a new device?\n";
                getline(cin, reason);
                cout << "Enter the device you want to request: ";
                getline(cin, device);
                cout << "Request for new device - " << device
                    << " because of the reason: " << reason << " was sent.\n";
                admin.addRequest(user.getName(), device, reason);
            }
            else {
                cout << "Invalid option.\n";
            }
            break;
        }

        case 4: {
            report.inputReport(user);
            break;
        }

        case 5:
            if (role == "Project Manager") {
                cout << "\n=== PROJECTS OF USERS ===\n";
                for (size_t i = 0; i < allUsers.size(); ++i) {
                    cout << i + 1 << ". " << allUsers[i].getName() << " (" << allUsers[i].getEmail() << ")\n";
                }
                cout << "\nSelect user to view (by number): ";
                int index;
                cin >> index;

                if (index < 1 || index > allUsers.size()) {
                    cout << "Invalid user index.\n";
                    break;
                }

                pm.showProjects(allUsers[index - 1]);
            }

            else if (role == "System Admin") {
                cout << "\n=== EDIT OTHER USERS ===\n";
                for (size_t i = 0; i < allUsers.size(); ++i) {
                    cout << i + 1 << ". " << allUsers[i].getName() << " (" << allUsers[i].getEmail() << ")\n";
                }
                cout << "Select user to edit (by number): ";
                int index;
                cin >> index;
                if (index < 1 || index > allUsers.size()) {
                    cout << "Invalid user index.\n";
                    break;
                }

                Profile& target = allUsers[index - 1];

                EditingProfile editor(
                    target.getName(),
                    target.getDevices(),
                    target.getLevel(),
                    target.getTypeOfWork(),
                    target.getPinCode()
                );


                editor.editUserMenu(target);
            }
            else {
                cout << "Invalid option.\n";
            }
            break;
        case 6:

            if (role == "Project Manager") {
                cout << "\n=== EDIT PROJECTS ===\n";
                cout << "1. Change a project of user\n";
                cout << "2. Change a type of project for user\n";
                cout << "\nChoose option: ";
                int choice;
                cin >> choice;
                if (choice == 1) {

                    cout << "\n=== CHANGE A PROJECT ===\n";
                    for (size_t i = 0; i < allUsers.size(); ++i) {
                        cout << i + 1 << ". " << allUsers[i].getName() << " (" << allUsers[i].getEmail() << ")\n" ;
                    }
                    cout << "\nSelect user to change a project (by number):";
                    int index;
                    cin >> index;
                    cout << "\n";
                    if (index < 1 || index > allUsers.size()) {
                        cout << "Invalid user index.\n";
                        break;
                    }

                    pm.changeProject(allUsers[index - 1]);
                }
                else if (choice == 2) {
                     cout << "\n=== CHANGE A TYPE OF PROJECT ===\n";
                    for (size_t i = 0; i < allUsers.size(); ++i) {
                        cout << i + 1 << ". " << allUsers[i].getName() << " (" << allUsers[i].getEmail() << ")\n";
                    }
                    cout << " \nSelect user to change a type of project (by number):";
                    int index;
                    cin >> index;
                    cout << "\n";
                    if (index < 1 || index > allUsers.size()) {
                        cout << "Invalid user index.\n";
                        break;
                    }

                    pm.changeTypeOfProject(allUsers[index - 1]);

                }
                else {
                    cout << "Invalid option.\n";
                }

               
            }
            else if (role == "System Admin") {
                admin.viewAndHandleRequests();
            }

            else {
                cout << "Invalid option.\n";
            }
            break;

        case 7:
            if (role == "Project Manager") {
                cout << "\n=== WORKING TIME  ===\n";
                cout << "1. Show working time\n";
                cout << "2. Change benefit package\n";
                cout << "\nChoose option: ";
                int choice;
                cin >> choice;
                if (choice == 1) {

                    for (size_t i = 0; i < allUsers.size(); ++i) {
                        cout << i + 1 << ". " << allUsers[i].getName() << " (" << allUsers[i].getEmail() << ")\n";
                    }
                    cout << "\nSelect user to watch working time and benefit package (by number): ";
                    int index;
                    cin >> index;
                    cout << "\n";
                    if (index < 1 || index > allUsers.size()) {
                        cout << "Invalid user index.\n";
                        break;
                    }

                    pm.showWorkingTime(allUsers[index - 1]);
                }
                else if (choice == 2) {
                    for (size_t i = 0; i < allUsers.size(); ++i) {
                        cout << i + 1 << ". " << allUsers[i].getName() << " (" << allUsers[i].getEmail() << ")\n";
                    }
                    cout << " \nSelect user to change benefit package (by number):";
                    int index;
                    cin >> index;
                    cout << "\n";
                    if (index < 1 || index > allUsers.size()) {
                        cout << "Invalid user index.\n";
                        break;
                    }

                    pm.changeBenefitPackage(allUsers[index - 1]);

                }
                else {
                    cout << "Invalid option.\n";
                }
                
            }
            else if (role == "System Admin") {

                cout << "\n=== SYSTEM ADMIN - User Profiles ===" << endl;
                cout << "1. View User Profiles\n";
                cout << "2. Delete User Profile\n";
                cout << "Choose option: ";
                int choice;
                cin >> choice;

                if (choice == 1) {

                    cout << "\n=== VIEWING PROFILES ===\n";
                    for (size_t i = 0; i < allUsers.size(); ++i) {
                        cout << i + 1 << ". " << allUsers[i].getName() << " (" << allUsers[i].getEmail() << ")\n";
                    }
                    cout << "Enter user number to view details (0 to go back): ";
                    int userIndex;
                    cin >> userIndex;

                    if (userIndex == 0) {
                        break;
                    }

                    if (userIndex < 1 || userIndex > allUsers.size()) {
                        cout << "Invalid option.\n";
                        break;
                    }


                    Profile& target = allUsers[userIndex - 1];
                    SystemAdmin admin;
                    admin.showUserInfo(&target, 1);
                }
                else if (choice == 2) {

                    cout << "Enter email of user to delete: ";
                    string email;
                    cin >> email;
                    SystemAdmin admin;
                    admin.deleteProfile(allUsers.data(), allUsers.size(), email);
                }
                else {
                    cout << "Invalid option.\n";
                }
            }
            else {
                cout << "Invalid option.\n";
            }
            break;

        case 8:
            cout << "\nLogging out...\n";
            return;




        default:
            cout << "\nInvalid choice. Please try again.\n";
        }
    }
}


vector<Profile> System::getEmployees() {
    vector<Profile> employees = {
        Profile("Anna Petrova", "15.06.1995", "anna@company.com", "Developer", "AppDev", "Full-time", "C++, Python", "Middle", "hybrid", "Lviv", "Dell Laptop",338, 9, 1234),
        Profile("Ivan Bondar", "21.03.1992", "ivan@company.com", "Developer", "WebPlatform", "Full-time", "Java, React", "Senior", "office based", "Kyiv", "MacBook Pro",482, 13, 5678),
        Profile("Olha Kovalenko", "10.10.1987", "olha@company.com", "Project Manager", "Analytics", "Part-time", "Management, Python", "Senior", "full remote", "Kharkiv", "Lenovo ThinkPad",416, 17, 1011),
        Profile("Serhii Melnyk", "05.01.1985", "serhii@company.com", "System Admin", "IT Support", "Part-time", "Networks, Linux", "Middle", "office based", "Dnipro", "HP EliteBook",473, 18, 1213)
    };
    return employees;
}


