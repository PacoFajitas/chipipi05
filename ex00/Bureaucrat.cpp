/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:04:36 by tfiguero          #+#    #+#             */
/*   Updated: 2024/06/18 04:36:06 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Holi");
}


const char* Bureaucrat::GradeTooLowException::what() const  throw()
{
	return("Adiu");
}


Bureaucrat::Bureaucrat()
{
	_grade = 2;
	_name = "John Doe";
	std::cout << "Basic Bureaucrat constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(Bureaucrat& old)
{
	*this = old;
		
}
Bureaucrat& Bureaucrat::operator=(Bureaucrat& old){}
Bureaucrat::~Bureaucrat(){}
std::string Bureaucrat::getName(){}
int	Bureaucrat::getGrade()
{
}