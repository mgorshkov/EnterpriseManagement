﻿#include <iostream>
#include <fstream>
#include <codecvt>

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
            std::wcerr << L"Файл " << path << L" не существует, пропускаю..." << std::endl;
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
	stream.imbue(std::locale(stream.getloc(), new std::codecvt_utf8<wchar_t>));

    std::wstring line;
    // header
    std::getline(stream, line);
	auto Split = [](const std::wstring& aLine)
	{
		auto line(aLine);
		boost::algorithm::trim(line);
		std::vector<std::wstring> strs;
		boost::split(strs, line, boost::is_any_of(L";"));
		return strs;
	};

	auto strs = Split(line);

    if (strs.size() != 2)
    {
        std::wcerr << L"Неверный формат, файл " << aPath.wstring() << L", пропускаю..." << std::endl;
        return;
    }

    std::size_t surnameIndex, roleIndex;
	std::vector <std::wstring> columns = { L"Фамилия", L"Специальность" };
    if (strs[0] == columns[0] && strs[1] == columns[1])
    {
        surnameIndex = 0;
        roleIndex = 1;
    }
    else if (strs[0] == columns[1] && strs[1] == columns[0])
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
        auto strs = Split(line);
        if (strs.size() != 2)
        {
            std::wcerr << L"Неверный формат, файл " << aPath.wstring() << L", строка " << line << L", пропускаем" << std::endl;
            continue;
        }

		auto department = aPath.stem().wstring();
        mEmployees.insert({department, strs[surnameIndex], strs[roleIndex]});
    }
}
