#pragma once

#include <unordered_map>
#include <list>

#include "Employeee.h"

class CvsParser
{
public:
    static std::unordered_map<std::list<Employee>> Parse(const std::list<std::string>& aFiles);

    static std::list<Employee> ParseFile(const boost::filesystem::path& aPath);
};
