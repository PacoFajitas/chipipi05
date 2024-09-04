#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
    std::cout << "------- CREATING AN INTERN -------" << std::endl;
    Intern someIntern;

    std::cout << std::endl << "------- CREATING THREE FORMS BY INTERN -------" << std::endl;
    AForm* f1;
    AForm* f2;
    AForm* f3;

	f1 = someIntern.makeForm("shrubbery creation", "someTarget1");
	f2 = someIntern.makeForm("robotomy request", "someTarget2");
	f3 = someIntern.makeForm("presidential pardon", "someTarget3");
	
    if (f1)
        std::cout << *f1 << std::endl;
    if (f2)
        std::cout << *f2 << std::endl;
    if (f3)
        std::cout << *f3 << std::endl;

    delete f1;
    delete f2;
    delete f3;

    std::cout << std::endl << "------- TRYING TO CREATE UNEXISTING FORM -------" << std::endl;
    AForm* f;

    f = someIntern.makeForm("unexisting form", "target");
	
    if (f)
        std::cout << *f << std::endl;
    delete f;  

    return (0);
}