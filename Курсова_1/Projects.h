//Projects.h
#pragma once
#ifndef PROJECTS_H
#define PROJECTS_H
#include "System.h"
#include "Profile.h"
#include <string>
using namespace std;

class Projects : public System {
protected:
    string userName;
    string userProjects;
    string userTypeOfProjects;

public:
    Projects();
    Projects(string name, string projects, string typeOfProjects);

    
    void changeProject(Profile&);
    void changeTypeOfProject(Profile&);
    void showProjects( Profile&);
};

#endif
