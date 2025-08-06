//ProjectManager.cpp
#include "ProjectManager.h"
#include <iostream>
#include <string>

using namespace std;

void ProjectManager::showWorkingTime(Profile& employee) {
    cout << "\n=== WATCHING TIME ===\n";
    cout << "Name: " << employee.getName() << "\n";
    cout << "Email: " << employee.getEmail() << "\n";
    cout << "Benefit package: " << employee.getBenefitsPackage() << "\n";
    cout << "Working hours: " << employee.getWorkingHours() << "\n";
    cout << "=======================================\n";
}

void ProjectManager::changeBenefitPackage(Profile& employee) {
    cout << "\n=== CHANGE BENEFIT PACKAGE ===\n";
    cout << "Name: " << employee.getName() << "\n";
    cout << "Current benefit package: " << employee.getBenefitsPackage() << "\n";
    cout << "Write number of days off to add : ";
    int dayoff;
    cin >> dayoff;
    employee.setBenefitsPackage(employee.getBenefitsPackage()+dayoff);
    cout << "Benefit package updated to:  \n" << employee.getBenefitsPackage() << endl;
    cout << "===============================\n";
}


