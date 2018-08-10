#pragma once

#include <string>

#include "Role.h"
#include "Task.h"

class Employee
{
public:
    Employee(const std::string& aDepartment, const std::string& aName, Role aRole);

    bool FillTask(Task aTask) const;

private:
    std::string mDepartment;
    std::string mName;
    Role mRole;
};
