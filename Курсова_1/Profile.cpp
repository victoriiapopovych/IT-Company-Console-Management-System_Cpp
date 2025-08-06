//Profile.cpp
#include "Profile.h"
#include <iostream>
using namespace std;

Profile::Profile() {}

Profile::Profile(string name, string dob, string email, string pos, string proj,
    string typeProjects, string skills, string level, string typeWork, string location,
    string devices,int working, int benefit, int pin)
    : name(name), dateOfBirth(dob), email(email), position(pos), projects(proj), typeOfProjects(typeProjects),
    skills(skills), level(level), typeOfWork(typeWork), location(location),
    devices(devices),workingHours(working), benefitsPackage(benefit), pinCode(pin) {
}

void Profile::showProfile(int option) {

    switch (option) {
    case 1:
        cout << "Name: " << name << "\n";
        break;
    case 2:
        cout << "Email: " << email << "\n";
        break;
    case 3:
        cout << "Position: " << position << "\n";
        break;
    case 4:
        cout << "Projects: " << projects << "\n";
        cout << "Type of project: " << typeOfProjects << "\n";
        break;
    case 5:
        cout << "Level: " << level << "\n";
        break;
    case 6:
        cout << "Skills: " << skills << "\n";
        break;
    case 7:
        cout << "Location: " << location << "\n";
        break;
    case 8:
        cout << "Type of Work: " << typeOfWork << "\n";
        break;
    case 9:
        cout << "Benefit Package: " << benefitsPackage << "\n";
        break;
    case 10:
        cout << "Devices: " << devices << "\n";
        break;
    default:
        cout << "Invalid option.\n";
        break;
    }
}


int Profile::getPinCode() { return pinCode; }
string Profile::getEmail() { return email; }
string Profile::getTypeOfWork() { return typeOfWork; }
string Profile::getPosition() { return position; }
string Profile::getName() { return name; }
string Profile::getDevices() const { return devices; }
string Profile::getLevel() const { return level; }
string Profile::getProjects() { return projects; }
string Profile::getTypeOfProjects() { return typeOfProjects; }
int Profile::getWorkingHours() { return workingHours; }
int Profile::getBenefitsPackage()  {return benefitsPackage;}

void Profile::setBenefitsPackage(int value) { benefitsPackage = value; }
void Profile::setName(const string& newName) { name = newName; }
void Profile::setDevices(const string& newDevices) { devices = newDevices; }
void Profile::setLevel(const string& newLevel) { level = newLevel; }
void Profile::setTypeOfWork(const string& newType) { typeOfWork = newType; }
void Profile::setPinCode(int newPin) { pinCode = newPin; }
void Profile::setProjects(const string& newProjects) { projects = newProjects;  }
void Profile::setTypeOfProjects(const string& newTypeOfProjects) { typeOfProjects = newTypeOfProjects; }
void Profile::setWorkingHours(int hours) { workingHours = hours; }


