#pragma once

#include <iostream>
#include <list>
#include <assert.h>

#include "Employee.h"

enum class TaskStatus
{
    Ok,
    CannotPerform,
    UnknownEmployeeOrDepartment,
    UnknownDepartment,
    UnknownTask,
    UnknownRole
};

inline std::wostream& operator << (std::wostream& stream, TaskStatus ts)
{
    std::wstring status;
    switch (ts)
    {
    case TaskStatus::Ok:
        status = L"OK";
        break;
    case TaskStatus::CannotPerform:
        status = L"ERR не может выполнить эту задачу";
        break;
	case TaskStatus::UnknownEmployeeOrDepartment:
		status = L"ERR неизвестный сотрудник или отдел";
		break;
	case TaskStatus::UnknownDepartment:
        status = L"ERR неизвестный отдел";
        break;
    case TaskStatus::UnknownTask:
        status = L"ERR неизвестная задача";
        break;
	case TaskStatus::UnknownRole:
		status = L"ERR неизвестная специализация";
		break;
	default:
        assert(0);
        break;
    }
    return stream << status;
}

struct TaskResult
{
    TaskResult(TaskStatus aStatus = TaskStatus::Ok, const Employee& aEmployee = Employee())
        : mStatus(aStatus)
        , mEmployee(aEmployee)
    {
    }
    TaskStatus mStatus;
    Employee mEmployee;

    inline friend std::wostream& operator << (std::wostream& stream, const TaskResult& result)
    {
        stream << result.mEmployee
			<< L" "
			<< result.mStatus
			<< std::endl;
        return stream;
    }
};

using TaskResults = std::list<TaskResult>;

inline std::wostream& operator << (std::wostream& stream, const TaskResults& results)
{
    for (auto result : results)
        stream << result;
    return stream;
}
