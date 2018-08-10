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


