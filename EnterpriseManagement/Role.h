#pragma once

#include <string>

#include "Task.h"

enum class Role
{
    Developer,
    TechnicalWriter,
    Tester,
    Accountant,
    Count // role counter, should be the last
};

class IRoleHandler
{
public:
    virtual ~IRoleHandler() = default;

    virtual Tasks GetAvailableTasks() const = 0;
    virtual std::wstring GetName() const = 0;

    bool CanPerformTask(Task aTask) const;
};

class RoleCommonHandler : public IRoleHandler
{
public:
    Tasks GetAvailableTasks() const;
    std::wstring GetName() const;

protected:
    Tasks AppendTasks(const Tasks& aTasks) const;
};

class RoleDeveloperHandler : public RoleCommonHandler
{
public:
    Tasks GetAvailableTasks() const;
    std::wstring GetName() const;
};

class RoleTechnicalWriterHandler : public RoleCommonHandler
{
public:
    Tasks GetAvailableTasks() const;
    std::wstring GetName() const;
};

class RoleTesterHandler : public RoleCommonHandler
{
public:
    Tasks GetAvailableTasks() const;
    std::wstring GetName() const;
};

class RoleAccountantHandler : public RoleCommonHandler
{
public:
    Tasks GetAvailableTasks() const;
    std::wstring GetName() const;
};



