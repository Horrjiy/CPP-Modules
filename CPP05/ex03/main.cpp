#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

static int testForm()
{
    std::string some_string;
    std::string name_string;
    AForm *A1;
    try
    {
        Intern someRandomIntern;

        // Initialize Form
        std::cout << "\033[31mWRITE A TARGET: \033[0m";
        if (!std::getline(std::cin, some_string))
            return (std::cerr << "Stopped.\n", 69);
        std::cout << "\033[31mGIVE A TYPE: \033[0m";
        if (!std::getline(std::cin, name_string))
            return (std::cerr << "Stopped.\n", 69);
        
        A1 = someRandomIntern.makeForm(name_string, some_string);
        if(!A1)
            return(69);
        std::cout << *A1 << std::endl;

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
        Kek.signForm(*A1);
        Kek.executeForm(*A1);
    }
    catch (std::exception &e)
    {
        /* handle exception */
        std::cerr << "Error: " << e.what() << std::endl;
    }
    delete A1;
    return (0);
}

int main(void)
{
    std::cout << "\033[33m~-~-~-~-~-~-~-~-~  >> InternForm <<  ~-~-~-~-~-~-~-~-~\033[0m\n";
    if (testForm() == 69)
        return (0);
}
