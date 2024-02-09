#include "Data.hpp"

int main()
{
    Data params;

    /*if (params.getDatabaseConnection())
    {
        std::cout << "Connection established!" << std::endl;
    } else {
        std::cout << "No connection to the database!" << std::endl;
    }*/
    if (params.initGui())
    {
        std::cout << "Error main.cpp!" << std::endl;
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
