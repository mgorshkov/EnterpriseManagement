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

std::vector<TaskInfo> gTaskInfo
{
    { GoOnVacation, "Уйти в отпуск"},
}

#pragma once

std::vector<Task> gCommonTasks =
{
    GoOnVacation,
    CleanUpWorkplace,
};

RoleTasks gRoleTasks =
{
    {
        Developer, "Разработчик", {Code, ProgramDesign}
    },
    {
        TechnicalWriter, "Технический писатель", {Translate}
    },
    {
        Tester, {Test, MakeTestPlan}
    },
    {
        Accountant, {CalcSalary, MakeQuarterlyReport}
    },
};


;
