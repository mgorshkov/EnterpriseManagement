#include <assert.h>
#include <iostream>

#include "Taskexecutor.h"

TaskExecutor::TaskExecutor(ITaskManager* aTaskManager)
{
    RegisterHandler(Task::Code, std::make_unique<CodeTaskHandler>(aTaskManager));
    RegisterHandler(Task::Design, std::make_unique<DesignTaskHandler>(aTaskManager));
    RegisterHandler(Task::Translate, std::make_unique<TranslateTaskHandler>(aTableManager));
    RegisterHandler(Task::Test, std::make_unique<TestTaskHandler>(aTableManager));
}

CompleteOperationStatus TaskExecutor::RunTask(const std::string& aLine)
{
    CompleteTask task = Parse(aLine);
    if (task.mTask == Task::Error)
    {
        return CompleteOperationStatus{OperationStatus::UnknownTask};
    }
    assert (mTaskHandlers.find(task.mTask) != mTaskHandlers.end());
    return mTaskHandlers[task.mTask]->Handle(task);
}

void TaskExecutor::RegisterHandler(Task aTask, std::unique_ptr<TaskHandler> aTaskHandler)
{
    assert (mTaskHandlers.find(aTask) == mTaskHandlers.end());
    mTaskHandlers.emplace(std::make_pair(aTask, std::move(aTaskHandler)));
}

CompleteTask TaskExecutor::Parse(const std::string& aLine)
{
    for (const auto& handler: mTaskHandlers)
    {
        auto taskName = handler.second->GetTask();
        auto pos = aLine.find(taskName);
        if (pos != std::string::npos)
        {
            std::string taskBody;
            if (aLine.length() > taskName.length())
                taskBody = aLine.substr(taskName.length() + 1, aLine.length() - taskName.length());

            return handler.second->Parse(taskBody);
        }
    }   
  
    return CompleteTask{Task::Error};
}
