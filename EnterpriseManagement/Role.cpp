#include <algorithm>

#include "Role.h"
#include "Task.h"

bool IRole::CanPerformTask(Task aTask) const
{
    auto tasks = GetAvailableTasks();
    return tasks.find(aTask) != tasks.end();
}

Tasks RoleCommon::GetAvailableTasks() const
{
    return Tasks{Task::GoOnVacation, Task::CleanUpWorkplace};
}

Tasks RoleCommon::AppendTasks(const Tasks& aTasks) const
{
    auto tasks = RoleCommon::GetAvailableTasks();
    Tasks output;
    std::set_union(tasks.begin(), tasks.end(),
                   aTasks.begin(), aTasks.end(),
                   std::inserter(output));
    return output;
}

Role RoleDeveloper::GetRole() const
{
    return Role::Developer;
}

Tasks RoleDeveloper::GetAvailableTasks() const
{
    return AppendTasks(Tasks{Task::Code, Task::ProgramDesign});
}

std::wstring RoleDeveloper::GetName() const
{
    return L"Разработчик";
}

Role RoleTechnicalWriter::GetRole() const
{
    return Role::TechnicalWriter;
}

Tasks RoleTechnicalWriter::GetAvailableTasks() const
{
    return AppendTasks(Tasks{Task::Translate});
}

std::wstring RoleTechnicalWriter::GetName() const
{
    return L"Технический писатель";
}

Role RoleTester::GetRole() const
{
    return Role::Tester;
}

Tasks RoleTester::GetAvailableTasks() const
{
    return AppendTasks(Tasks{Task::Test, Task::MakeTestPlan});
}

std::wstring RoleTester::GetName() const
{
    return L"Специалист тестирования";
}

Role RoleAccountant::GetRole() const
{
    return Role::Accountant;
}

Tasks RoleAccountant::GetAvailableTasks() const
{
    return AppendTasks(Tasks{Task::CalcSalary, Task::MakeQuarterlyReport});
}

std::wstring RoleAccountant::GetName() const
{
    return L"Бухгалтер";
}
