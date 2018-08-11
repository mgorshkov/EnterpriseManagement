#include <iostream>
#include <list>
#include <string>
#include <fcntl.h>
#ifdef _WIN32
	#include <io.h>
#endif
#include "Defines.h"
#include "EnterpriseManagement.h"

int main(int argc, char* argv[])
{
#ifdef _WIN32
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);
#endif

    try
    {
        if (argc < 2)
        {
            std::wcerr << LR"(Использование: EnterpriseManagement <csv1> <csv2>...
Пример. ExterpriseManagement dep1.txt dep2.txt
уйти в отпуск
dep1.txt Волков Бухгалтер OK
dep1.txt Иванов Разработчик OK
dep1.txt Кузнецов Специалист тестирования OK
dep1.txt Сидоров Технический писатель OK
dep2.txt Горшков Разработчик OK
dep2.txt Иванов Бухгалтер OK
dep2.txt Иванов Специалист тестирования OK
dep2.txt Кузнецов Специалист тестирования OK
dep2.txt Рябцов Технический писатель OK

тестировать dep1
dep1 Иванов Разработчик ERR не может выполнить эту задачу
dep1 Сидоров Технический писатель ERR не может выполнить эту задачу
dep1 Кузнецов Специалист тестирования OK
dep1 Волков Бухгалтер ERR не может выполнить эту задачу

переводить тексты dep2 Рябцов
dep2 Рябцов Технический писатель OK)" << std::endl;
            return 1;
        }

        Files files;
        for (int i = 1; i < argc; ++i)
            files.push_back(argv[i]);

        EnterpriseManagement enterpriseManagement(files);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
