#pragma once

std::vector<Task> gCommonTasks =
{
    GoOnVacation,
    CleanUpWorkplace,
};

RoleTasks gRoleTasks =
{
    {
        Developer, "�����������", {Code, ProgramDesign}
    },
    {
        TechnicalWriter, "����������� ��������", {Translate}
    },
    {
        Tester, {Test, MakeTestPlan}
    },
    {
        Accountant, {CalcSalary, MakeQuarterlyReport}
    },
};


