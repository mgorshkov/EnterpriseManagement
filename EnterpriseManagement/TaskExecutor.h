#pragma once

#include <unordered_map>
#include <map>
#include <memory>

#include "Taskhandler.h"

class TaskExecutor
{
public:
    TaskExecutor(ITaskManager* aTaskManager);

    CompleteOperationStatus RunTask(const std::string& aLine);

private:
    void RegisterHandler(Task aTask, std::unique_ptr<TaskHandler> aTaskHandler);
    CompleteTask Parse(const std::string& aLine);

    std::unordered_map<Task, std::unique_ptr<TaskHandler>> mTaskHandlers;
};
