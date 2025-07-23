#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    std::string some_string;
    std::string name_string;
    std::string some_formstr;
    try
    {
        // Initialize Bureaucrat
        std::cout << "\033[31mGIVE A GRADE(1-150): \033[0m";
        if (!std::getline(std::cin, some_string))
            return (std::cerr << "Stopped.\n", 69);
        std::cout << "\033[31mWRITE A NAME: \033[0m";
        if (!std::getline(std::cin, name_string))
            return (std::cerr << "Stopped.\n", 69);
        Bureaucrat Kek(name_string, std::stoi(some_string));
        std::cout << Kek;

        // Initialize Form
        std::cout << "\033[31mGIVE A EXECUTION GRADE (1-150): \033[0m";
        if (!std::getline(std::cin, some_formstr))
            return (std::cerr << "Stopped.\n", 69);
        std::cout << "\033[31mGIVE A SIGN GRADE (1-150): \033[0m";
        if (!std::getline(std::cin, some_string))
            return (std::cerr << "Stopped.\n", 69);
        std::cout << "\033[31mWRITE A NAME: \033[0m";
        if (!std::getline(std::cin, name_string))
            return (std::cerr << "Stopped.\n", 69);
        Form A1(name_string, std::stoi(some_formstr), std::stoi(some_string));
        std::cout << A1 << std::endl;

        // test signing form:
        Kek.signForm(A1);
    }
    catch (std::exception &e)
    {
        /* handle exception */
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
