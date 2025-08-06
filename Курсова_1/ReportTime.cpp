//ReportTime.cpp
#include "ReportTime.h"
#include "Profile.h"

void ReportTime::inputReport(Profile& employee) {
    int reportChoice;
    cout << "Select report type:\n";
    cout << "1. Working time\n";
    cout << "2. Sick leave\n";
    cout << "3. Vacation\n";
    cout << "4. Day off\n";
    cout << "Enter choice (1-4): ";
    cin >> reportChoice;

    switch (reportChoice) {
    case 1:
        reportType = "Working time";
        cout << "Select month:\n";
        cout << "1. January\n2. February\n3. March\n4. April\n5. May\n6. June\n";
        cout << "7. July\n8. August\n9. September\n10. October\n11. November\n12. December\n";
        cout << "Enter month number: ";
        int monthChoice;
        cin >> monthChoice;

        switch (monthChoice) {
        case 1: month = "January"; break;
        case 2: month = "February"; break;
        case 3: month = "March"; break;
        case 4: month = "April"; break;
        case 5: month = "May"; break;
        case 6: month = "June"; break;
        case 7: month = "July"; break;
        case 8: month = "August"; break;
        case 9: month = "September"; break;
        case 10: month = "October"; break;
        case 11: month = "November"; break;
        case 12: month = "December"; break;
        default:
            cout << "Invalid month!\n";
            return;
        }

        cout << "Enter day: ";
        cin >> day;

        if (day < 1 || day > 31) {
            cout << "Invalid day! Day must be between 1 and 31.\n";
            return;
        }

        if (month == "April" || month == "June" || month == "September" || month == "November") {
            if (day > 30) {
                cout << "Invalid day for " << month << "! Maximum is 30.\n";
                return;
            }
        }
        else if (month == "February") {
            cout << "Enter year: ";
            cin >> year;
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                if (day > 29) {
                    cout << "Invalid day! February in leap year has max 29 days.\n";
                    return;
                }
            }
            else {
                if (day > 28) {
                    cout << "Invalid day! February in non-leap year has max 28 days.\n";
                    return;
                }
            }
        }
        else {
            cout << "Enter year: ";
            cin >> year;
        }
        cout << "Enter number of hours worked: ";
        cin >> hours;
        employee.setWorkingHours(employee.getWorkingHours() + hours);
        cout << "Reported " << reportType << " on " << day << " " << month << ".\n";
        break;

    case 2:
        reportType = "Sick leave";
        employee.setBenefitsPackage(employee.getBenefitsPackage() - 1);
        cout << "Benefit package decreased by 1. - " << employee.getBenefitsPackage() << endl;
        break;

    case 3:
        reportType = "Vacation";
        employee.setBenefitsPackage(employee.getBenefitsPackage()-1);
        cout << "Benefit package decreased by 1. - "<< employee.getBenefitsPackage() << endl;
        break;

    case 4:
        reportType = "Day off";
        break;

    default:
        cout << "Invalid choice.\n";
        return;
    }
}

void ReportTime::displayReport() {
    cout << "Report Type: " << reportType << endl;
    if (reportType == "Working time") {
        cout << "Date: " << day << " " << month << " " << year << endl;
        cout << "Hours Worked: " << hours << endl;
    }
}
