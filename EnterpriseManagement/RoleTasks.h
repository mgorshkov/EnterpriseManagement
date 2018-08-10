#pragma once

struct RoleTasks
{
    Role mRole;
    std::vector<Task> mTasks;
};

extern std::vector<Task> gCommonTasks;

extern RoleTasks gRoleTasks;


