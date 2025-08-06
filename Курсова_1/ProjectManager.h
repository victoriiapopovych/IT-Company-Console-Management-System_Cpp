//ProjectManager.h
#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include "Profile.h"
#include "Projects.h"
#include "ReportTime.h"
#include <string>

class ProjectManager : public Projects, ReportTime {
public:
    void showWorkingTime(Profile&);
    void changeBenefitPackage(Profile&);
};

#endif
