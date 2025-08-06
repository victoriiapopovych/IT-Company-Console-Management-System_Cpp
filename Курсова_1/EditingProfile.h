//EditingProfile.h
#pragma once
#ifndef EDITINGPROFILE_H
#define EDITINGPROFILE_H
#include "System.h"
#include <string>
using namespace std;

class EditingProfile : public System{
protected:
    string userName;
    string userDevices;
    string userLevel;
    string userTypeOfWork;
    int userPinCode;

public:
    EditingProfile();
    EditingProfile(string name, string devices, string level, string typeOfWork, int pin);

    void changeName(string name);
    void changeDevices(string newDevice);
    void changeLevel(string newLevel);
    void changeTypeOfWork(string newType);
    void changePinCode(int newPin);
    void editUserMenu(Profile& target);
};

#endif
