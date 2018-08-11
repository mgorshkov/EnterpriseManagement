#include "EnterpriseManagement.h"
#include "CsvParser.h"
#include "TaskExecutor.h"

EnterpriseManagement::EnterpriseManagement(const Files& aFiles)
{
    auto employees = ParseEmployees(aFiles);
    if (!employees.empty())
        ProcessCommands(employees);
}

Employees EnterpriseManagement::ParseEmployees(const Files& aFiles)
{
    CsvParser parser(aFiles);
    return parser.GetEmployees();
}

void EnterpriseManagement::ProcessCommands(const Employees& aEmployees)
{
    TaskExecutor taskExecutor(aEmployees);

    std::wstring line;
    while (std::getline(std::wcin, line))
    {
        auto status = taskExecutor.PerformTask(line);
        std::wcout << status << std::endl;
    }
}
