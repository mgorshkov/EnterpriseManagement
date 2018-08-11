#include <algorithm>
#include <iterator>

#include "Role.h"
#include "Task.h"

bool IRoleHandler::CanPerformTask(Task aTask) const
{
    auto tasks = GetAvailableTasks();
    return tasks.find(aTask) != tasks.end();
}

std::wstring RoleCommonHandler::GetName() const
{
    return L"";
}

Tasks RoleCommonHandler::GetAvailableTasks() const
{
    return Tasks{Task::GoOnVacation, Task::CleanUpWorkplace};
}

Tasks RoleCommonHandler::AppendTasks(const Tasks& aTasks) const
{
    auto tasks = RoleCommonHandler::GetAvailableTasks();
    Tasks output;
    std::set_union(tasks.begin(), tasks.end(),
                   aTasks.begin(), aTasks.end(),
                   std::inserter(output, output.begin()));
    return output;
}

Tasks RoleDeveloperHandler::GetAvailableTasks() const
{
    return AppendTasks(Tasks{Task::Code, Task::ProgramDesign});
}

std::wstring RoleDeveloperHandler::GetName() const
{
    return L"Разработчик";
}

Tasks RoleTechnicalWriterHandler::GetAvailableTasks() const
{
    return AppendTasks(Tasks{Task::Translate});
}

std::wstring RoleTechnicalWriterHandler::GetName() const
{
    return L"Технический писатель";
}

Tasks RoleTesterHandler::GetAvailableTasks() const
{
    return AppendTasks(Tasks{Task::Test, Task::MakeTestPlan});
}

std::wstring RoleTesterHandler::GetName() const
{
    return L"Специалист тестирования";
}

Tasks RoleAccountantHandler::GetAvailableTasks() const
{
    return AppendTasks(Tasks{Task::CalcSalary, Task::MakeQuarterlyReport});
}

std::wstring RoleAccountantHandler::GetName() const
{
    return L"Бухгалтер";
}
