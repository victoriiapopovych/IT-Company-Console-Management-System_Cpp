//Profile.h
#ifndef PROFILE_H
#define PROFILE_H
#include <string>
#include <vector>

using namespace std;

class Profile {
private:
    string name;
    string dateOfBirth;
    string email;
    string position;
    string projects;
    string typeOfProjects;
    string skills;
    string level;
    string typeOfWork;
    string location;
    string devices;
    int workingHours;
    int benefitsPackage;
    int pinCode;
    

public:
    Profile();
    Profile(string, string, string, string, string, string, string, string, string, string, string, int, int, int);

    void showProfile(int option);

    string getEmail();
    string getTypeOfWork();
    string getPosition();
    string getName();
    string getDevices() const;
    string getLevel() const;
    string getProjects();
    string getTypeOfProjects();
    int getWorkingHours();
    int getPinCode();
    int getBenefitsPackage();

    void setName(const string&);
    void setDevices(const string&);
    void setLevel(const string&);
    void setTypeOfWork(const string&);
    void setPinCode(int);
    void setProjects(const string&);
    void setTypeOfProjects(const string&);
    void setWorkingHours(int hours);
    void setBenefitsPackage(int value);


};

#endif
