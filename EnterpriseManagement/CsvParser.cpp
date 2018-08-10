#include <iostream>

#include <boost/algorithm/string.hpp>

#include "CsvParser.h"

Departments CsvParser::Parse(const std::list<std::string>& aFiles)
{
    Departments departments;

    for (const auto& pathName : aFiles)
    {
        boost::filesystem::path path(pathName);
        if (!boost::filesystem::exists(path))
        {
            std::cerr << "File " << path << "does not exist, skipping" << std::endl;
            continue;
        }
        auto depName = path.filename().string();
        departments[depName] = ParseFile(path);
    }
    return departments;
}

Department CsvParser::ParseFile(const boost::filesystem::path& aPath)
{
    Department department;
    std::fstream stream(aPath.string());
    std::string line;
    // header
    std::getline(stream, line);
    while (std::getline(stream, line))
    {
        boost::algorithm::trim(line);
        std::vector<std::string> strs;
        boost::split(strs, line, boost::is_any_of(" \t"));

        if (strs.size() != 2)
        {
            std::cerr << "File " << aPath << ": incorrect format of line " << line << ", skipping" << std::endl;
            continue;
        }

        Employee info{aPath.filename().string(), strs[0], strs[1]};
        department.push_back(info);
    }

    return department;
}
