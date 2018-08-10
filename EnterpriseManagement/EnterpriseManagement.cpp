#include "EnterpriseManagement.h"
#include "CsvParser.h"

EnterpriseManagement::EnterpriseManagement(const std::list<std::string>& aFiles)
    : mFiles(aFiles)
{
}

void EnterpriseManagement::Run()
{
    ParseEmployees();
    ProcessCommands();
}

void EnterpriseManagement::ParseEmployees()
{
    auto employees = CsvParser::Parse(mFiles);
    mTaskExecutor = std::make_unique<TaskExecutor>(employees);
}

void EnterpriseManagement::ProcessCommands()
{
    std::string line;
	while (std::getline(std::cin, line))
    {
        auto status = mTaskExecutor->ExecuteTask(line);
        std::cout << status << std::endl;
    }
}
