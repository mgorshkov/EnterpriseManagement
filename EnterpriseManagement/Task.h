#pragma once

#include <set>
#include <iostream>

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
    Count // task counter, should be the last
};

class ITaskDescriptor
{
public:
    virtual ~ITaskDescriptor() = default;

    virtual std::wstring GetName() const = 0;
};

inline std::wostream& operator << (std::wostream& stream, const ITaskDescriptor& t)
{
    return stream << t.GetName().c_str();
}

using Tasks = std::set<Task>;

class TaskGoOnVacationDescriptor : public ITaskDescriptor
{
public:
    virtual std::wstring GetName() const;
};

class TaskCleanUpWorkplaceDescriptor : public ITaskDescriptor
{
public:
    virtual std::wstring GetName() const;
};

class TaskCodeDescriptor : public ITaskDescriptor
{
public:
    virtual std::wstring GetName() const;
};

class TaskProgramDesignDescriptor : public ITaskDescriptor
{
public:
    virtual std::wstring GetName() const;
};

class TaskTranslateDescriptor : public ITaskDescriptor
{
public:
    virtual std::wstring GetName() const;
};

class TaskTestDescriptor : public ITaskDescriptor
{
public:
    virtual std::wstring GetName() const;
};

class TaskMakeTestPlanDescriptor : public ITaskDescriptor
{
public:
    virtual std::wstring GetName() const;
};

class TaskCalcSalaryDescriptor : public ITaskDescriptor
{
public:
    virtual std::wstring GetName() const;
};

class TaskMakeQuarterlyReportDescriptor : public ITaskDescriptor
{
public:
    virtual std::wstring GetName() const;
};
