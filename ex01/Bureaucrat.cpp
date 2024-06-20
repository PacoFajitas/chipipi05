/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:04:36 by tfiguero          #+#    #+#             */
/*   Updated: 2024/06/20 03:19:52 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade is too high or is already the highest and couldnt increase it anymore");
}


const char* Bureaucrat::GradeTooLowException::what() const  throw()
{
	return("Grade is too low or is already the lowest and couldnt decrease it anymore");
}


Bureaucrat::Bureaucrat()
{
	_grade = 2;
	_name = "John Doe";
	std::cout << "Basic Bureaucrat constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(const int grade)
{
	if (grade < 151 && grade > 0)
	{
		_name = "John Doe";
		std::cout << "Bureaucrat constructor called with grade"<< grade << std::endl;
		_grade = grade;
	}
	else if(grade > 150)
		throw GradeTooLowException();
	else
		throw GradeTooHighException();
	
}
Bureaucrat::Bureaucrat(const std::string name)
{
	_name = name;
	std::cout << "Bureaucrat constructor called with name "<< name <<std::endl;
	_grade = 5;
}
Bureaucrat::Bureaucrat(const std::string name, const int grade)
{
	if (grade < 151 && grade > 0)
	{
		_name = name;
		std::cout << "Bureaucrat constructor called with name "<< name <<" and with grade"<< grade <<std::endl;
		_grade = grade;
	}
	else if(grade > 150)
		throw GradeTooLowException();
	else
		throw GradeTooHighException();
}
Bureaucrat::Bureaucrat(const Bureaucrat& old)
{
	*this = old;
	std::cout << "Copy Bureaucrat constructor called" << std::endl;	
		
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& old)
{
	this->_name = old._name;
	this->_grade = old._grade;
	std::cout <<  "Bureaucrat equal operator overload called" << std::endl;
	return *this;
}
Bureaucrat::~Bureaucrat()
{
	std::cout <<  "Bureaucrat destructor called" << std::endl;
}
std::string Bureaucrat::getName() const
{
	return _name;
}
int	Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::increaseGrade()
{
	if (_grade - 1 < 1)
	{
		throw GradeTooHighException();
	}
	this->_grade -= 1;
	
}

void Bureaucrat::decreaseGrade()
{
	if (_grade + 1 > 150)
	{
		throw GradeTooLowException();
	}
	this->_grade += 1;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& param)
{
	os << param.getName() <<  ", bureaucrat grade " << param.getGrade();
	return(os);
}