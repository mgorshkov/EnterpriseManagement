#pragma once

enum class Role
{
    Developer,
    TechnicalWriter,
    Tester,
    Accountant
};

struct RoleInfo
{
    Role mRole;
    std::string mRoleDescription;
    std::vector<Task> mTasks;
};


