#pragma once

#include <set>

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

class ITask
{
public:
    virtual ~ITask() = default;

    virtual std::string GetName() const = 0;
};

inline std::ostream& operator << (std::ostream& stream, const ITask& t)
{
    return stream << t.GetName();
}

using Tasks = std::set<Task>;

class TaskGoOnVacation : public ITask
{
public:
    virtual std::string GetName() const;
};

class TaskCleanUpWorkplace : public ITask
{
public:
    virtual std::string GetName() const;
};

class TaskCode : public ITask
{
public:
    virtual std::string GetName() const;
};

class TaskProgramDesign : public ITask
{
public:
    virtual std::string GetName() const;
};

class TaskTranslate : public ITask
{
public:
    virtual std::string GetName() const;
};

class TaskTest : public ITask
{
public:
    virtual std::string GetName() const;
};

class TaskMakeTestPlan : public ITask
{
public:
    virtual std::string GetName() const;
};

class TaskCalcSalary : public ITask
{
public:
    virtual std::string GetName() const;
};

class TaskMakeQuarterlyReport : public ITask
{
public:
    virtual std::string GetName() const;
};
