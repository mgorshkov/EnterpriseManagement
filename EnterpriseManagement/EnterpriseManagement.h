#pragma once

#include <list>
#include <string>

#include "TaskExecutor.h"

class EnterpriseManagement
{
public:
    EnterpriseManagement(const std::list<std::string>& aFiles);

    void Run();

private:
    TaskExecutor mTaskExecutor;
};
