cmake_minimum_required(VERSION 3.5)
project(EnterpriseManagement VERSION 0.0.1)

set(DEBUG_PRINT "0")

if (DEBUG_PRINT)
    message("DEBUG_PRINT is activated!")
    add_definitions(-DDEBUG_PRINT)
endif()

add_executable(EnterpriseManagement
    CsvParser.cpp
    CsvParser.h
    Employee.cpp
    Employee.h
    EnterpriseManagement.cpp
    EnterpriseManagement.h
    Main.cpp
    Role.h
    RoleTasks.cpp
    RoleTasks.h
    Task.cpp
    Task.h
    TaskExecutor.cpp
    TaskExecutor.h
    TaskStatus.h)

set(THREADS_PREFER_PTHREAD_FLAG ON)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)

find_package(Boost REQUIRED COMPONENTS system filesystem)

set_target_properties(EnterpriseManagement PROPERTIES
    COMPILE_OPTIONS -Wpedantic -Wall -Wextra
    CMAKE_CXX_STANDARD 14
    CMAKE_CXX_STANDARD_REQUIRED ON
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(EnterpriseManagement
    ${Boost_LIBRARIES}
)
