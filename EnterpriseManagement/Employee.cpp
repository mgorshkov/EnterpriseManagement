#pragma once

#include "Employee.h"

Employee::Employee(const std::string& aDepartment, const std::string& aName, Role aRole)
    : mDepartment(aDepartment)
    , mName(aName)
    , mRole(aRole)
{
}

bool Employee::FillTask(Task aTask) const
{
}
