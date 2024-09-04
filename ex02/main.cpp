#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat di("di", 1);
	std::cout << "-------------------------" << std::endl;
    Bureaucrat bob("bob", 1);
	std::cout << "-------------------------" << std::endl;
    PresidentialPardonForm a("Joan");
	std::cout << "-------------------------" << std::endl;
	RobotomyRequestForm b("Anna");
	std::cout << "-------------------------" << std::endl;
	ShrubberyCreationForm c("Tomasin");
	std::cout << "-------------------------" << std::endl;
    try
	{
		bob.signForm(a);
		std::cout << "-------------------------" << std::endl;
		bob.executeForm(a);
		std::cout << "-------------------------" << std::endl;
		di.signForm(b);
		std::cout << "-------------------------" << std::endl;
		di.executeForm(b);
		di.executeForm(b);
		di.executeForm(b);
		di.executeForm(b);
		di.executeForm(b);
		di.executeForm(b);
		di.executeForm(b);
		di.executeForm(b);
		di.executeForm(b);
		di.executeForm(b);
		std::cout << "-------------------------" << std::endl;
		bob.signForm(c);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-------------------------" << std::endl;

	Bureaucrat aux("Lua", 150);
	try
	{
		aux.signForm(c);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

    return (0);
}