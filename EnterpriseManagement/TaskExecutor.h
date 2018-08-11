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
    TaskExecutor(const Employees& aEmployees);

    TaskResults PerformTask(const std::wstring& aLine);

private:
    void RegisterRoles();
    void RegisterTasks();

    void RegisterRole(Role aRole, std::unique_ptr<IRoleHandler> aRoleHandler);
    void RegisterTask(Task aTask, std::unique_ptr<ITaskDescriptor> aTaskDescriptor);

    TaskResults PerformTaskByEmployee(Task aTask, const Employee& aEmployee);
    TaskResults PerformTaskByEmployee(Task aTask, const std::wstring& aDepartment, const std::wstring& aEmployeeName);
    TaskResults PerformTaskByDepartment(Task aTask, const std::wstring& aDepartment);
    TaskResults PerformTaskByEmployeeOrDepartment(Task aTask, const std::wstring& aTaskBody);
    TaskResults PerformTaskByEverybody(Task aTask);


    std::unordered_map<Role, std::unique_ptr<IRoleHandler>> mRoleHandlers;
    std::unordered_map<Task, std::unique_ptr<ITaskDescriptor>> mTaskDescriptors;

    Employees mEmployees;
};
