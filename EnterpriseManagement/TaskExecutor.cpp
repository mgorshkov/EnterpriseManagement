#include <assert.h>
#include <iostream>

#include <boost/algorithm/string.hpp>

#include "TaskExecutor.h"

TaskExecutor::TaskExecutor(const Departments& aDepartments)
    : mDepartments(aDepartments)
{
    RegisterRole(RoleDeveloper::GetRole(), std::make_unique<RoleDeveloper>());
    RegisterRole(RoleTechnicalWriter::GetRole(), std::make_unique<RoleTechnicalWriter>());
    RegisterRole(RoleTester::GetRole(), std::make_unique<RoleTester>());
    RegisterRole(RoleAccountant::GetRole(), std::make_unique<RoleAccountant>());

    RegisterTask(TaskGoOnVacation::GetTask(), std::make_unique<TaskGoOnVacation>());
    RegisterTask(TaskCleanUpWorkplace::GetTask(), std::make_unique<TaskCleanUpWorkplace>());
    RegisterTask(TaskCode::GetTask(), std::make_unique<TaskCode>());
    RegisterTask(TaskProgramDesign::GetTask(), std::make_unique<TaskProgramDesign>());
}

void TaskExecutor::RegisterRole(Role aRole, std::unique_ptr<IRole> aRole)
{
    assert (mRoleHandlers.find(aRole) == mRoleHandlers.end());
    mRoleHandlers.emplace(std::make_pair(aRole, std::move(aRoleHandler)));
}

void TaskExecutor::RegisterTask(Task aTask, std::unique_ptr<ITask> aTask)
{
    assert (mTaskHandlers.find(aTask) == mTaskHandlers.end());
    mTaskHandlers.emplace(std::make_pair(aTask, std::move(aTaskHandler)));
}

TaskResult TaskExecutor::PerformTask(const std::string& aLine)
{
    for (const auto& taskHandler: mTaskHandlers)
    {
        auto taskName = taskHandler.second->GetName();
        auto pos = aLine.find(taskName);
        if (pos != std::string::npos)
        {
            auto task = taskHandler.second->GetTask();

            std::string taskBody;
            if (aLine.length() > taskName.length())
            {
                taskBody = aLine.substr(taskName.length() + 1, aLine.length() - taskName.length());
                taskBody = taskBody.trim();
                return PerformTaskByPersonOrDepartment(task, taskBody);
            }
            else
                return PerformTaskByEverybody(task);
        }
    }   
  
    return TaskResult{Task::Error};
}

TaskResult TaskExecutor::PerformTaskByEmployee(Task aTask, const Employee& aEmployee)
{
    TaskResult taskResult;

    for (const auto& roleHandler: mRoleHandlers)
    {
        auto roleName = roleHandler.second->GetName();
        if (emp.mRole != roleName)
            continue;

        if (roleHandler->CanPerformTask(aTask))
        {
            taskResult << emp.mDepartment << " " << emp.mName << " OK" << std::endl;
        }
    }

    return taskResult;
}

TaskResult TaskExecutor::PerformTaskByDepartment(Task aTask, const Department& aDepartment)
{
    TaskResult taskResult;
    for (const auto& emp : aDepartment)
        taskResult << PerformTaskByEmployee(aTask, emp);

    return taskResult;
}

TaskResult TaskExecutor::PerformTaskByEmployeeOrDepartment(Task aTask, const std::string& aTaskBody)
{
    TaskResult taskResult;

    std::vector<std::string> strs;
    boost::split(strs, aTaskBody, boost::is_any_of(" \t"));

    auto depName = strs[0];
    auto depIt = mDepartments.find(depName);
    if (depIt == mDepartments.end())
        return TaskResult{};

    if (strs.length() == 1)
        return PerformTaskByDepartment(*depIt);
    
    auto person = strs[1];
    auto personIt = depIt->find(person);

    if (personIt == depIt->end())
        return TaskResult{};

    return return ExecuteTaskByPerson(*personIt);
}

TaskResult TaskExecutor::PerformTaskByEverybody(Task aTask)
{
    TaskResult taskResult;

    for (const auto& dep : mDepartments)
        TaskResult << PerformTaskByDepartment(aTask, dep)

    return taskResult;
}
