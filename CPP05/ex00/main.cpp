#include "Bureaucrat.hpp"

int main(void)
{
    std::string some_string;
    std::string name_string;
    try
    {
        /* do some stuff with bureaucrats */

        std::cout << "\033[31mGIVE A GRADE (1-150): \033[0m";
        if (!std::getline(std::cin, some_string))
            return (std::cerr << "Stopped.\n", 69);
        std::cout << "\033[31mWRITE A NAME: \033[0m";
        if (!std::getline(std::cin, name_string))
            return (std::cerr << "Stopped.\n", 69);
        Bureaucrat Kek(name_string, std::stoi(some_string));
        std::cout << Kek;

        std::cout << "\033[31mGIVE A NEW GRADE (1-150): \033[0m";
        if (!std::getline(std::cin, some_string))
            return (std::cerr << "Stopped.\n", 69);
        int i = stoi(some_string);
        while (Kek.getGrade() != i)
        {
            if (i > Kek.getGrade())
                Kek.gradeDegr();
            else
                Kek.gradeProm();
        }
        std::cout << "\033[31mNew: \033[0m" << Kek;
    }
    catch (std::exception &e)
    {
        /* handle exception */
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
