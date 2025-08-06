//ReportTime.h
#ifndef REPORTTIME_H
#define REPORTTIME_H
#include "Profile.h"
#include <iostream>
#include <string>
using namespace std;


class ReportTime : public Profile {
private:
    string reportType;
    string month;
    int hours;
    int day;
    int year;

public:
    void inputReport(Profile&);
    void displayReport();
};

#endif


