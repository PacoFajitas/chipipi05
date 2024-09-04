/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 02:25:02 by tfiguero          #+#    #+#             */
/*   Updated: 2024/09/03 22:00:52 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return("Form's grade is too high for this bureaucrat");
}

const char* Form::FormSignedException::what() const throw()
{
	return("Form is already signed");
}

const char* Form::GradeTooLowException::what() const  throw()
{
	return("Form's grade is too low for this bureaucrat");
}

Form::Form(): _name("Default"), _grade_sign(15), _grade_exec(15), _signed(false)
{
	
	std::cout << "Basic form constructor called" << std::endl;
}
Form::Form(const std::string name) :_name(name), _grade_sign(15), _grade_exec(15), _signed(false)
{
	std::cout << "Form constructor called with name "<< name << std::endl;
}
Form::Form(const std::string name, const int gradeSign): _name(name), _grade_sign(gradeSign), _grade_exec(15), _signed(false)
{
	try
	{
		if(_grade_exec > 150 || _grade_sign > 150)
			throw GradeTooLowException();
		if(_grade_exec < 1 || _grade_sign < 1)
			throw GradeTooHighException();
		std::cout << "Form constructor called with name "<< name<< " and a grade to sign of "<< gradeSign << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
}
Form::Form(const std::string name, const int gradeSign, const int gradeExec): _name(name), _grade_sign(gradeSign), _grade_exec(gradeExec), _signed(false)
{
	if(_grade_exec > 150 || _grade_sign > 150)
		throw GradeTooLowException();
	if(_grade_exec < 1 || _grade_sign < 1)
		throw GradeTooHighException();
	std::cout << "Form constructor called with name "<< name<< " and a grade to sign of "<< gradeSign;
	std::cout << " and a grade to execute of " << gradeExec << std::endl;
}
Form::Form(const Form& old): _name(old.getName()), _grade_sign(old.getGradeSign()),  _grade_exec(old.getGradeExec()), _signed(old.getSigned())
{
	std::cout << "Form copy constructor called"<< std::endl;
	if(_grade_exec > 150 || _grade_sign > 150)
		throw GradeTooLowException();
	if(_grade_exec < 1 || _grade_sign < 1)
		throw GradeTooHighException();
}
Form& Form::operator=(const Form& old)
{
	std::cout << "Form operator = overload called"<< std::endl;
	_signed = old._signed;
	return *this;
}
Form::~Form()
{
	std::cout << "Form destructor called"<< std::endl;
}
std::string Form::getName() const
{
	return _name;
}
bool		Form::getSigned() const
{
	return _signed;
}
int			Form::getGradeSign() const
{
	return _grade_sign;
}
int			Form::getGradeExec() const
{
	return _grade_exec;
}

void		Form::beSigned(const Bureaucrat& param)
{
	if (this->_signed == true)
		throw FormSignedException();		
	if(param.getGrade()<= this->_grade_sign)
	{
		_signed = true;
	}
	else
		throw GradeTooHighException();	
}

std::ostream& operator<<(std::ostream& os, const Form& param)
{
	os << "The form's name is : " << param.getName() << " and has a execution and signing grade of: " << param.getGradeExec() << ", "<< param.getGradeSign();
	if(param.getSigned())
		os << " and it has been signed" << std::endl;
	else
		os << " and it hasn't been signed" << std::endl;
	return(os);
}
