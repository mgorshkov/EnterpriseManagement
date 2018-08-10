#pragma once

enum class Task
{
    GoOnVacation,
    CleanUpWorkplace,
    Code,
    ProgramDesign,
    Translate,
    Test,
    MakeTestPlan,
    CalcSalary,
    MakeQuarterlyReport,
};

inline std::ostream& operator << (std::ostream& stream, Task t)
{
    std::string status;
    switch (t)
    {
    case Task::GoOnVacation:
        status = "Go On Vacation";
        break;
    case Task::CleanUpWorkplace:
        status = "Clean Up Workplace";
        break;
    case Task::Code:
        status = "Code";
        break;
    case Task::ProgramDesign:
        status = "Program Design";
        break;
    case Task::Translate:
        status = "Translate";
        break;
    case Task::Test:
        status = "Test";
        break;
    case Task::MakeTestPlan:
        status = "MakeTestPlan";
        break;
    case Task::CalcSalary:
        status = "CalcSalary";
        break;
    case Task::MakeQuarterlyReport:
        status = "MakeQuarterlyReport";
        break;
    default:
        status = "Unknown Task";
        break;
    }
    return stream << status;
}

struct TaskInfo
{
    Task mTask;
    std::string mTaskDescription;
};

extern std::vector<Task> gCommonTasks;

extern RoleTasks gRoleTasks;

