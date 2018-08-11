#include "Task.h"

std::wstring TaskGoOnVacationDescriptor::GetName() const
{
    return L"уйти в отпуск";
}

std::wstring TaskCleanUpWorkplaceDescriptor::GetName() const
{
    return L"убрать рабочее место";
}

std::wstring TaskCodeDescriptor::GetName() const
{
    return L"программировать";
}

std::wstring TaskProgramDesignDescriptor::GetName() const
{
    return L"проектировать";
}

std::wstring TaskTranslateDescriptor::GetName() const
{
    return L"переводить тексты";
}

std::wstring TaskTestDescriptor::GetName() const
{
    return L"тестировать";
}

std::wstring TaskMakeTestPlanDescriptor::GetName() const
{
    return L"составлять тестовые планы";
}

std::wstring TaskCalcSalaryDescriptor::GetName() const
{
    return L"начислять зарплату";
}

std::wstring TaskMakeQuarterlyReportDescriptor::GetName() const
{
    return L"составить квартальный отчет";
}
