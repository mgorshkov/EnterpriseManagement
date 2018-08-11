#pragma once

#include "Defines.h"
#include "Employee.h"

class EnterpriseManagement
{
public:
    EnterpriseManagement(const Files& aFiles);

private:
    Employees ParseEmployees(const Files& aFiles);
    void ProcessCommands(const Employees& aEmployees);
};
