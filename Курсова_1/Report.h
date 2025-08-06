#ifndef REPORT_H
#define REPORT_H

#include "Profile.h"

class CReportTime : public CProfile {
public:
    void inputReport() {
        int day, hours;
        string month, dayType;
        cout << "\n=== REPORT TIME ===" << endl;

        cout << "Enter day: ";
        cin >> day;
        if (day < 1 || day > 31) {
            cout << "Invalid day! Day must be between 1 and 31.\n";
            return;  
        }

        
        cout << "Enter month: ";
        cin >> month;

        
        if (month == "January" || month == "March" || month == "May" || month == "July" || month == "August" ||
            month == "October" || month == "December") {
            if (day > 31) {
                cout << "Invalid day for " << month << "! Maximum day is 31.\n";
                return;  
            }
        }
        else if (month == "April" || month == "June" || month == "September" || month == "November") {
            if (day > 30) {
                cout << "Invalid day for " << month << "! Maximum day is 30.\n";
                return;  
            }
        }
        else if (month == "February") {
           
            int year;
            cout << "Enter year: ";
            cin >> year;

            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) { 
                if (day > 29) {
                    cout << "Invalid day for " << month << " in a leap year! Maximum day is 29.\n";
                    return; 
                }
            }
            else {
                if (day > 28) {
                    cout << "Invalid day for " << month << " in a non-leap year! Maximum day is 28.\n";
                    return; 
                }
            }
        }
        else {
            cout << "Invalid month! Please enter a valid month name.\n";
            return;  
        }

        
        cout << "Enter type of day (working, vacation, sick, off): ";
        cin >> dayType;


        if (dayType == "working") {
            cout << "Enter hours worked: ";
            cin >> hours;
            if (hours > 8) cout << "Overtime!\n";
        }

        cout << "Reported " << dayType << " on " << day << " " << month << ".\n";
    }
};

#endif

