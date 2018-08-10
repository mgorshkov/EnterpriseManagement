#include "EnterpriseManagement.h"

EnterpriseManagement::EnterpriseManagement(const std::list<std::string>& aFiles)
    : mFiles(aFiles)
{
}

void EnterpriseManagement::Run()
{
    ParseEmployees();
    ProcessCommands();
}

void EnterpriseManager::ParseEmployees()
{
    auto employees = CvsParser::Parse(mFiles);
    mTaskExecutor.SetEmployees(employees);
}

void EnterpriseManager::ProcessCommands()
{
    std::string line;
	while (std::getline(std::cin, line))
    {
        auto status = mTaskExecutor.RunTask(line);
        std::cout << status << std::endl;
    }
}
