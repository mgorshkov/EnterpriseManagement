#pragma once

#include <string>

#include "Task.h"

enum class Role
{
    Developer,
    TechnicalWriter,
    Tester,
    Accountant
};

class IRole
{
public:
    virtual ~IRole() = default;

    virtual Role GetRole() const = 0;
    virtual Tasks GetAvailableTasks() const = 0;
    virtual std::wstring GetName() const = 0;

    bool CanPerformTask(Task aTask) const;
};

class RoleCommon : public IRole
{
public:
    Role GetRole() const;
    Tasks GetAvailableTasks() const;
    std::wstring GetName() const;

protected:
    Tasks AppendTasks(const Tasks& aTasks) const;
};

class RoleDeveloper : public RoleCommon
{
public:
    Role GetRole() const;
    Tasks GetAvailableTasks() const;
    std::wstring GetName() const;
};

class RoleTechnicalWriter : public RoleCommon
{
public:
    Role GetRole() const;
    Tasks GetAvailableTasks() const;
    std::wstring GetName() const;
};

class RoleTester : public RoleCommon
{
public:
    Role GetRole() const;
    Tasks GetAvailableTasks() const;
    std::wstring GetName() const;
};

class RoleAccountant : public RoleCommon
{
public:
    Role GetRole() const;
    Tasks GetAvailableTasks() const;
    std::wstring GetName() const;
};



