#pragma once

#include <list>
#include <string>
#include <memory>

#include "TaskExecutor.h"

class EnterpriseManagement
{
public:
    EnterpriseManagement(const std::list<std::string>& aFiles);

    void Run();

private:
	void ParseEmployees();
    void ProcessCommands();

	std::list<std::string> mFiles;
    std::unique_ptr<TaskExecutor> mTaskExecutor;
};
