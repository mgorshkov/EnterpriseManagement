#pragma once

#include <string>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/composite_key.hpp>
#include <boost/multi_index/ordered_index.hpp>

struct Employee
{
    std::wstring mDepartment;
    std::wstring mName;
    std::wstring mRole;

    struct ByDepartment {};
    struct ByDepartmentAndName {};

    inline friend std::wostream& operator << (std::wostream& stream, const Employee& aEmployee)
    {
        stream << aEmployee.mDepartment
            << std::wstring(L" ")
            << aEmployee.mName
            << std::wstring(L" ")
            << aEmployee.mRole;
        return stream;
    }
};

using Employees = boost::multi_index_container<Employee,
    boost::multi_index::indexed_by<
        boost::multi_index::ordered_non_unique<
            boost::multi_index::tag<Employee::ByDepartmentAndName>, boost::multi_index::composite_key<
                Employee,
                boost::multi_index::member<Employee, std::wstring, &Employee::mDepartment>,
                boost::multi_index::member<Employee, std::wstring, &Employee::mName>
            >
        >,
        boost::multi_index::ordered_non_unique<
            boost::multi_index::tag<Employee::ByDepartment>, boost::multi_index::member<Employee, std::wstring, &Employee::mDepartment>
        >
    >
>;
