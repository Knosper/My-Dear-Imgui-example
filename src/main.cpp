#include "AppGui.hpp"
#include "tData.hpp"

int main()
{
    T_data params;

    /*if (params.getDatabaseConnection())
    {
        std::cout << "Connection established!" << std::endl;
    } else {
        std::cout << "No connection to the database!" << std::endl;
    }*/
    if (initGui(params))
    {
        std::cout << "Error main.cpp!" << std::endl;
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
