#pragma once

#include <unordered_map>
#include <map>
#include <memory>

#include "Role.h"
#include "Task.h"
#include "Employee.h"
#include "TaskStatus.h"

class TaskExecutor
{
public:
    TaskExecutor(const Departments& aDepartments);

    TaskResult ExecuteTask(const std::string& aLine);

private:
    void RegisterRole(Role aRole, std::unique_ptr<IRole> aRoleHandler);
    void RegisterTask(Task aTask, std::unique_ptr<ITask> aTaskHandler);

    TaskResult ExecuteTaskByPersonOrDepartment(Task aTask, const std::string& aTaskBody);
    TaskResult ExecuteTaskByEverybody(Task aTask);


    std::unordered_map<Role, std::unique_ptr<IRole>> mRoleHandlers;
    std::unordered_map<Task, std::unique_ptr<ITask>> mTaskHandlers;

    Departments mDepartments;
};
