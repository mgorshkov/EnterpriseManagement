#pragma once

#include <boost/filesystem.hpp>

#include "Defines.h"
#include "Employee.h"

class CsvParser
{
public:
    CsvParser(const Files& aFiles);

    Employees GetEmployees() const;

private:
    void ParseFile(const boost::filesystem::path& aPath);

    Employees mEmployees;
};
