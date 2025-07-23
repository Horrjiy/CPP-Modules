#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

static int testPresidentialPardonForm()
{
    std::string some_string;
    std::string name_string;
    try
    {
        // Initialize Form
        std::cout << "\033[31mWRITE A TARGET: \033[0m";
        if (!std::getline(std::cin, name_string))
            return (std::cerr << "Stopped.\n", 69);
        PresidentialPardonForm A1(name_string);
        std::cout << A1 << std::endl;

        // Initialize Bureaucrat
        std::cout << "\033[31mGIVE A GRADE(1-150): \033[0m";
        if (!std::getline(std::cin, some_string))
            return (std::cerr << "Stopped.\n", 69);
        std::cout << "\033[31mWRITE A NAME: \033[0m";
        if (!std::getline(std::cin, name_string))
            return (std::cerr << "Stopped.\n", 69);
        Bureaucrat Kek(name_string, std::stoi(some_string));
        std::cout << Kek;

        // signing, then executing form:
        Kek.signForm(A1);
        Kek.executeForm(A1);
    }
    catch (std::exception &e)
    {
        /* handle exception */
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return (0);
}

static int testRobotomyRequestForm()
{
    std::string some_string;
    std::string name_string;
    try
    {
        // Initialize Form
        std::cout << "\033[31mWRITE A TARGET: \033[0m";
        if (!std::getline(std::cin, name_string))
            return (std::cerr << "Stopped.\n", 69);
        RobotomyRequestForm B2(name_string);
        std::cout << B2 << std::endl;

        // Initialize Bureaucrat
        std::cout << "\033[31mGIVE A GRADE(1-150): \033[0m";
        if (!std::getline(std::cin, some_string))
            return (std::cerr << "Stopped.\n", 69);
        std::cout << "\033[31mWRITE A NAME: \033[0m";
        if (!std::getline(std::cin, name_string))
            return (std::cerr << "Stopped.\n", 69);
        Bureaucrat Kek(name_string, std::stoi(some_string));
        std::cout << Kek;

        // signing, then executing form:
        Kek.signForm(B2);
        Kek.executeForm(B2);
    }
    catch (std::exception &e)
    {
        /* handle exception */
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return (0);
}

static int testShrubberyCreationForm()
{
    std::string some_string;
    std::string name_string;
    try
    {
        // Initialize Form
        std::cout << "\033[31mWRITE A TARGET: \033[0m";
        if (!std::getline(std::cin, name_string))
            return (std::cerr << "Stopped.\n", 69);
        ShrubberyCreationForm C3(name_string);
        std::cout << C3 << std::endl;

        // Initialize Bureaucrat
        std::cout << "\033[31mGIVE A GRADE(1-150): \033[0m";
        if (!std::getline(std::cin, some_string))
            return (std::cerr << "Stopped.\n", 69);
        std::cout << "\033[31mWRITE A NAME: \033[0m";
        if (!std::getline(std::cin, name_string))
            return (std::cerr << "Stopped.\n", 69);
        Bureaucrat Kek(name_string, std::stoi(some_string));
        std::cout << Kek;

        // signing, then executing form:
        Kek.signForm(C3);
        Kek.executeForm(C3);
    }
    catch (std::exception &e)
    {
        /* handle exception */
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return (0);
}

int main(void)
{
    std::cout << "\033[33m~-~-~-~-~-~-~-~-~  >> PresidentialPardonForm <<  ~-~-~-~-~-~-~-~-~\033[0m\n";
    if (testPresidentialPardonForm() == 69)
        return (0);
    std::cout << "\033[33m\n~-~-~-~-~-~-~-~-~  >> RobotomyRequestForm <<  ~-~-~-~-~-~-~-~-~\033[0m\n";
    if (testRobotomyRequestForm() == 69)
        return (0);
    std::cout << "\033[33m\n~-~-~-~-~-~-~-~-~  >> ShrubberyCreationForm <<  ~-~-~-~-~-~-~-~-~\033[0m\n";
    if (testShrubberyCreationForm() == 69)
        return (0);
}
