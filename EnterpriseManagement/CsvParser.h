#pragma once

#include <unordered_map>
#include <list>

#include <boost/filesystem.hpp>

#include "Employee.h"

class CsvParser
{
public:
    static Departments Parse(const std::list<std::string>& aFiles);

    static Department ParseFile(const boost::filesystem::path& aPath);
};
