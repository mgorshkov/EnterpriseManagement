#pragma once

#include <string>
#include <list>
#include <unordered_map>

struct Employee
{
    std::string mDepartment;
    std::string mName;
    std::string mRole;

    friend std::ostream& operator << (std::ostream& stream, const Employee& aEmployee)
    {
        stream << aEmployee.mDepartment
        	<< std::string(" ")
        	<< aEmployee.mName
        	<< std::string(" ")
        	<< aEmployee.mRole;
        return stream;
    }
};

using Department = std::list<Employee>;
using Departments = std::unordered_map<std::string, Department>;