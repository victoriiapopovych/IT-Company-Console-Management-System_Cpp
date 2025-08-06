//System.h
#ifndef SYSTEM_H
#define SYSTEM_H

#include "Profile.h"
#include "BookingPlace.h"
#include "ReportTime.h"
#include <vector>

class System : public Profile, BookingPlace, ReportTime{
public:
    void menu(Profile& user, vector<Profile>& allUsers);
    static vector<Profile> getEmployees();
};

#endif
