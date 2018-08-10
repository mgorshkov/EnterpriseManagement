#include <iostream>
#include <list>
#include <string>

#include "EnperpriseManagement.h"

int main(int argc, char* argv[])
{
    try
    {
        if (argc < 2)
        {
            std::cerr << "Usage: enterprise_management <csv1> <csv2>..." << std::endl;
            return 1;
        }

        std::list<std::string> files;
        for (int i = 0; i < argc; ++i)
            files.push_back(argv[i]);

        EnterpriseManagement enterpriseManagement(files);
        enterpriseManagement.Run();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
