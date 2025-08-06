//Projects.cpp
#include "Projects.h"
#include "Profile.h"
#include <iostream>
using namespace std;

Projects::Projects() {}

Projects::Projects(string name, string projects, string typeOfProjects)
    : userName(name), userProjects(projects), userTypeOfProjects(typeOfProjects) { }

void Projects::showProjects( Profile& employee) {
    cout << "\n=== PM - User Projects ===\n";
    cout << "Name: " << employee.getName() << "\n";
    cout << "Email: " << employee.getEmail() << "\n";
    cout << "Current projects: " << employee.getProjects() << "\n";
    cout << "Type of projects: " << employee.getTypeOfProjects() << "\n";
    cout << "===============================\n";
}


void Projects::changeProject(Profile& employee) {
    cout << "Name: " << employee.getName() << "\n";
    cout << "Current project: " << employee.getProjects() << "\n";
    cout << "Write new project: ";
    string newProject;
    cin >> newProject;
    employee.setProjects(newProject);
    cout << "Project updated to:  \n" << employee.getProjects() << endl;
    cout << "===============================\n";
}


void Projects::changeTypeOfProject(Profile& employee) {
    cout << "                 Name: " << employee.getName() << "\n";
    cout << "Current project: " << employee.getProjects() << "       " << "Type of this project - " << employee.getTypeOfProjects() <<"\n";
    cout << "\nWrite new type of project: ";
    string newTypeOfProject;
    cin >> newTypeOfProject;
    employee.setTypeOfProjects(newTypeOfProject);
    cout << "Project type updated to:  " << employee.getTypeOfProjects() << endl;
    cout << "===============================\n";
}


