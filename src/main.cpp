#include "Data.hpp"

int main()
{
    Data params;
    params._cpuCores = std::thread::hardware_concurrency();
    if (params.initGui())
    {
        std::cout << "Error main.cpp!" << std::endl;
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
