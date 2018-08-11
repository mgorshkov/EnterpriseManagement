#include <assert.h>
#include <iostream>
#include <vector>

#include <boost/algorithm/string.hpp>

#include "TaskExecutor.h"

TaskExecutor::TaskExecutor(const Employees& aEmployees)
    : mEmployees(aEmployees)
{
    RegisterRoles();
    RegisterTasks();
}

void TaskExecutor::RegisterRoles()
{
    RegisterRole(Role::Developer, std::make_unique<RoleDeveloperHandler>());
    RegisterRole(Role::TechnicalWriter, std::make_unique<RoleTechnicalWriterHandler>());
    RegisterRole(Role::Tester, std::make_unique<RoleTesterHandler>());
    RegisterRole(Role::Accountant, std::make_unique<RoleAccountantHandler>());

    assert (mRoleHandlers.size() == static_cast<std::size_t>(Role::Count));
}

void TaskExecutor::RegisterTasks()
{
    RegisterTask(Task::GoOnVacation, std::make_unique<TaskGoOnVacationDescriptor>());
    RegisterTask(Task::CleanUpWorkplace, std::make_unique<TaskCleanUpWorkplaceDescriptor>());
    RegisterTask(Task::Code, std::make_unique<TaskCodeDescriptor>());
    RegisterTask(Task::ProgramDesign, std::make_unique<TaskProgramDesignDescriptor>());
    RegisterTask(Task::Translate, std::make_unique<TaskTranslateDescriptor>());
    RegisterTask(Task::Test, std::make_unique<TaskTestDescriptor>());
    RegisterTask(Task::MakeTestPlan, std::make_unique<TaskMakeTestPlanDescriptor>());
    RegisterTask(Task::CalcSalary, std::make_unique<TaskCalcSalaryDescriptor>());
    RegisterTask(Task::MakeQuarterlyReport, std::make_unique<TaskMakeQuarterlyReportDescriptor>());

    assert (mTaskDescriptors.size() == static_cast<std::size_t>(Task::Count));
}

void TaskExecutor::RegisterRole(Role aRole, std::unique_ptr<IRoleHandler> aRoleHandler)
{
    assert (mRoleHandlers.find(aRole) == mRoleHandlers.end());
    mRoleHandlers.emplace(std::make_pair(aRole, std::move(aRoleHandler)));
}

void TaskExecutor::RegisterTask(Task aTask, std::unique_ptr<ITaskDescriptor> aTaskDescriptor)
{
    assert (mTaskDescriptors.find(aTask) == mTaskDescriptors.end());
    mTaskDescriptors.emplace(std::make_pair(aTask, std::move(aTaskDescriptor)));
}

TaskResults TaskExecutor::PerformTask(const std::wstring& aLine)
{
    for (const auto& taskDescriptor : mTaskDescriptors)
    {
        auto taskName = taskDescriptor.second->GetName();
        auto pos = aLine.find(taskName);
        if (pos != std::wstring::npos)
        {
            auto task = taskDescriptor.first;

            std::wstring taskBody;
            if (aLine.length() > taskName.length())
            {
                taskBody = aLine.substr(taskName.length() + 1, aLine.length() - taskName.length());
                boost::algorithm::trim(taskBody);
                return PerformTaskByEmployeeOrDepartment(task, taskBody);
            }
            else
                return PerformTaskByEverybody(task);
        }
    }   
  
    return TaskResults{TaskResult{TaskStatus::UnknownTask}};
}

TaskResults TaskExecutor::PerformTaskByEmployee(Task aTask, const Employee& aEmployee)
{
    for (const auto& roleHandler: mRoleHandlers)
    {
        auto roleName = roleHandler.second->GetName();
        if (aEmployee.mRole != roleName)
            continue;

        return TaskResults{TaskResult{roleHandler.second->CanPerformTask(aTask) ? TaskStatus::Ok : TaskStatus::CannotPerform, aEmployee}};
    }

    return TaskResults{TaskResult{TaskStatus::UnknownRole, aEmployee}};
}

TaskResults TaskExecutor::PerformTaskByDepartment(Task aTask, const std::wstring& aDepartment)
{
    Employees::index<Employee::ByDepartment>::type::iterator depItBegin, depItEnd;
    std::tie(depItBegin, depItEnd) = mEmployees.get<Employee::ByDepartment>().equal_range(aDepartment);
    if (depItBegin == depItEnd)
        return TaskResults{TaskResult{TaskStatus::UnknownDepartment}};

    TaskResults taskResults;
    while (depItBegin != depItEnd)
        taskResults.splice(taskResults.end(), PerformTaskByEmployee(aTask, *depItBegin++));

    return taskResults;
}

TaskResults TaskExecutor::PerformTaskByEmployee(Task aTask, const std::wstring& aDepartment, const std::wstring& aEmployeeName)
{
    Employees::index<Employee::ByDepartmentAndName>::type::iterator keyItBegin, keyItEnd;
    std::tie(keyItBegin, keyItEnd) = mEmployees.get<Employee::ByDepartmentAndName>().equal_range(std::make_tuple(aDepartment, aEmployeeName));
    if (keyItBegin == keyItEnd)
        return TaskResults{TaskResult{TaskStatus::UnknownEmployeeOrDepartment}};

    TaskResults taskResults;
    while (keyItBegin != keyItEnd)
        taskResults.splice(taskResults.end(), PerformTaskByEmployee(aTask, *keyItBegin++));

    return taskResults;
}

TaskResults TaskExecutor::PerformTaskByEmployeeOrDepartment(Task aTask, const std::wstring& aTaskBody)
{
    std::vector<std::wstring> strs;
	boost::split(strs, aTaskBody, boost::is_any_of(L" \t"));

    auto department = strs[0];
    if (strs.size() == 1)
        return PerformTaskByDepartment(aTask, department);
    
    auto employee = strs[1];
    return PerformTaskByEmployee(aTask, department, employee);
}

TaskResults TaskExecutor::PerformTaskByEverybody(Task aTask)
{
    TaskResults taskResults;

    for (const auto& emp : mEmployees)
        taskResults.splice(taskResults.end(), PerformTaskByEmployee(aTask, emp));

    return taskResults;
}
