//SystemAdmin.h
#ifndef SYSTEMADMIN_H
#define SYSTEMADMIN_H

#include "Profile.h"
#include <string>
#include <vector>
#include "EditingProfile.h"

struct Request {
    string senderName;
    string deviceRequested;
    string reason;
    bool isHandled;
    bool isApproved;
};

class SystemAdmin : public EditingProfile {

private: 
    vector<Request> requests;
public:
    void showUserInfo(Profile employees[], int size);
    void deleteProfile(Profile employees[], int size, string email);
    void addRequest(const string& sender, const string& device, const string& reason);
    void viewAndHandleRequests();
};

#endif


