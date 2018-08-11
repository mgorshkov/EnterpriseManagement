#include <iostream>

#include <boost/algorithm/string.hpp>

#include "CsvParser.h"

CsvParser::CsvParser(const Files& aFiles)
{
    mEmployees.clear();

    for (const auto& pathName : aFiles)
    {
        boost::filesystem::path path(pathName);
        if (!boost::filesystem::exists(path))
        {
            std::cerr << "File " << path << " does not exist, skipping" << std::endl;
            continue;
        }
        ParseFile(path);
    }
}

Employees CsvParser::GetEmployees() const
{
    return mEmployees;
}

void CsvParser::ParseFile(const boost::filesystem::path& aPath)
{
    std::wfstream stream(aPath.string());
    std::wstring line;
    // header
    std::getline(stream, line);
    boost::algorithm::trim(line);
    std::vector<std::wstring> strs;
    boost::split(strs, line, boost::is_any_of(" \t"));

    if (strs.size() != 2)
    {
        std::wcerr << L"Неверный формат, файл " << aPath.wstring() << L", пропускаем" << std::endl;
        return;
    }

    std::size_t surnameIndex, roleIndex;
    if (strs[0] == L"Фамилия" && strs[1] == L"Специальность")
    {
        surnameIndex = 0;
        roleIndex = 1;
    }
    else if (strs[0] == L"Специальность" && strs[1] == L"Фамилия")
    {
        surnameIndex = 1;
        roleIndex = 0;
    }
    else
    {
        std::wcerr << L"Неверный формат, файл " << aPath.wstring() << L", пропускаем" << std::endl;
        return;
    }

    while (std::getline(stream, line))
    {
        boost::algorithm::trim(line);
        std::vector<std::wstring> strs;
        boost::split(strs, line, boost::is_any_of(" \t"));

        if (strs.size() != 2)
        {
            std::wcerr << L"Неверный формат, файл " << aPath.wstring() << L", строка " << line << L", пропускаем" << std::endl;
            continue;
        }

        mEmployees.insert({aPath.filename().wstring(), strs[surnameIndex], strs[roleIndex]});
    }
}
