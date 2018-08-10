#include "CvsParser.h"

std::unordered_map<std::list<Employee>> CvsParser::Parse(const std::list<std::string>& aFiles)
{
    std::unordered_map<std::list<Employee>> employees;

    for (const auto& fileName : aFiles)
    {
        boost::filesystem::path path(fileName);
        if (!path.exists())
        {
            std::cerr << "File " << path << "does not exist, skipping" << std::endl;
            continue;
        }
        employees[path.fileName()] = ParseFile(path);
    }
    return employees;
}

std::list<Employee> CvsParser::ParseFile(const boost::filesystem::path& aPath)
{
    std::list<Employee> employeeInfo;
    std::fstream stream(aPath);
    std::string line;
    // header
    std::getline(stream, line);
    while (std::getline(stream, line))
    {
        line = line.trim();
        std::vector<std::string> strs;
        boost::split(strs, line, [](char c) { return c == ';'; });

        if (strs.length() != 2)
        {
            std::cerr << "File " << aPath << ": incorrect format of line " << line << ", skipping" << std::endl;
            continue;
        }

        Employee info{path.filename(), strs[0], strs[1]};
        employeeInfo.push_back(info);
    }

    return employeeInfo;
}
