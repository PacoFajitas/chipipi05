/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:15 by tfiguero          #+#    #+#             */
/*   Updated: 2024/09/04 22:15:36 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

typedef AForm* (*ptrarray)(std::string);

Intern::Intern()
{
	std::cout <<  "Intern default constructor called" << std::endl;
}
Intern::Intern(const Intern &old)
{
	*this = old;
	std::cout << "Intern copy constructor called" << std::endl;
}
Intern& Intern::operator=(const Intern& old)
{
	(void) old;
	std::cout << "Intern = operator overload called" << std::endl;
	return *this;
}
Intern::~Intern()
{
	std::cout << "Intern default destructor called" << std::endl;
}
std::string	ft_toLower(std::string check)
{
	for (size_t i = 0; i < check.length(); i++)
	{
		if(check.at(i) >= 'A' && check.at(i) <= 'Z')
			check.at(i) = check.at(i) + 32;
	}
	return check;	
}

AForm *makePresidential(std::string FTarget)
{
	return(new PresidentialPardonForm (FTarget));	
}

AForm *makeRobotomy(std::string FTarget)
{
	return(new RobotomyRequestForm (FTarget));	
}

AForm *makeShrubbery(std::string FTarget)
{
	return(new ShrubberyCreationForm(FTarget));	
}
AForm* Intern::makeForm(std::string FName, std::string FTarget)
{
	ptrarray fun[3] = {makePresidential, makeRobotomy, makeShrubbery};
	std::string jiji[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	FName = ft_toLower(FName);
	for (size_t i = 0; i < 3; i++)
	{
		if (!FName.compare(jiji[i]))
		{
			return fun[i](FTarget);
		}	
	}
	std::cerr << "Intern couldn't create the form because it doesn't exist" << std::endl;
	return NULL;
}