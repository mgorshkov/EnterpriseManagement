#pragma once

#include <iostream>
#include <string>
#include <assert.h>

enum class TaskStatus
{
    Ok,
    UnknownEmployeeOrDepartment,
    UnknownTask,
};

inline std::ostream& operator << (std::ostream& stream, TaskStatus os)
{
    std::string status;
    switch (os)
    {
    case TaskStatus::Ok:
        status = "OK";
        break;
    case TaskStatus::UnknownEmployeeOrDepartment:
        status = "ERR unknown employee or department";
        break;
    case TaskStatus::UnknownTask:
        status = "ERR cannot execute this task";
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

    friend std::ostream& operator << (std::ostream& stream, TaskResult result)
    {
        stream << result.mEmployee;
        stream << result.mStatus;
        stream << std::endl;
        return stream;
    }
};
