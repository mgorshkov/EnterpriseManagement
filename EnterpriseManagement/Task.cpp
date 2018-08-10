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
    { GoOnVacation, "���� � ������"},
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


;
