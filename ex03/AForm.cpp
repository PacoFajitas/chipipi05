/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 02:25:02 by tfiguero          #+#    #+#             */
/*   Updated: 2024/06/20 05:10:07 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return("Form's grade is too high for this bureaucrat");
}

const char* AForm::FormSignedException::what() const throw()
{
	return("Form is already signed");
}

const char* AForm::GradeTooLowException::what() const  throw()
{
	return("Form's grade is too low for this bureaucrat");
}

const char* AForm::NotSignedException::what() const  throw()
{
	return("This form hasn't been signed yet");
}
AForm::AForm(): _name("Default"), _grade_exec(15), _grade_sign(15), _signed(false)
{
	
	std::cout << "Basic AForm constructor called" << std::endl;
}
AForm::AForm(const std::string name) :_name(name),  _grade_exec(15), _grade_sign(15), _signed(false)
{
	std::cout << "AForm constructor called with name "<< name << std::endl;
}
AForm::AForm(const std::string name, const int gradeSign): _name(name), _grade_exec(15), _grade_sign(gradeSign), _signed(false)
{
	if(_grade_exec > 150 || _grade_sign > 150)
		throw GradeTooLowException();
	if(_grade_exec < 1 || _grade_sign < 1)
		throw GradeTooHighException();
	std::cout << "AForm constructor called with name "<< name<< " and a grade to sign of "<< gradeSign << std::endl;
}
AForm::AForm(const std::string name, const int gradeSign, const int gradeExec): _name(name), _grade_exec(gradeExec), _grade_sign(gradeSign), _signed(false)
{
	if(_grade_exec > 150 || _grade_sign > 150)
		throw GradeTooLowException();
	if(_grade_exec < 1 || _grade_sign < 1)
		throw GradeTooHighException();
	std::cout << "AForm constructor called with name "<< name<< " and a grade to sign of "<< gradeSign;
	std::cout << " and a grade to execute of " << gradeExec << std::endl;
}
AForm::AForm(const int gradeSign, const int gradeExec): _name("Default"), _grade_exec(gradeExec), _grade_sign(gradeSign), _signed(false)
{
	if(_grade_exec > 150 || _grade_sign > 150)
		throw GradeTooLowException();
	if(_grade_exec < 1 || _grade_sign < 1)
		throw GradeTooHighException();	
	std::cout << "AForm constructor called witgh a grade to sign of "<< gradeSign << " and a grade to execute of " << gradeExec << std::endl;
}
AForm::AForm(const int gradeSign): _name("Default"), _grade_exec(15), _grade_sign(gradeSign), _signed(false)
{
	if(_grade_exec > 150 || _grade_sign > 150)
		throw GradeTooLowException();
	if(_grade_exec < 1 || _grade_sign < 1)
		throw GradeTooHighException();
	std::cout << "AForm constructor called witgh a grade to sign of "<< gradeSign << std::endl;
}

AForm::AForm(const AForm& old) : _name(old._name), _grade_exec(old._grade_exec), _grade_sign(old._grade_sign), _signed(old._signed)
{
	std::cout << "AForm copy constructor called " << std::endl;
}
AForm& AForm::operator=(const AForm& old)
{
	std::cout << "AForm operator = overload called"<< std::endl;
	_signed = old._signed;
	return *this;
}
AForm::~AForm()
{
	std::cout << "AForm destructor called"<< std::endl;
}
std::string AForm::getName() const
{
	return _name;
}
bool		AForm::getSigned() const
{
	return _signed;
}
int			AForm::getGradeSign() const
{
	return _grade_sign;
}
int			AForm::getGradeExec() const
{
	return _grade_exec;
}

void		AForm::beSigned(const Bureaucrat& param)
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

void AForm::execute(const Bureaucrat &executor)
{
	if(!_signed)
		throw NotSignedException();
	else if(this->_grade_exec < executor.getGrade())
		throw GradeTooLowException();
	else
		this->acctuallyExecute();
}

std::ostream& operator<<(std::ostream& os, const AForm& param)
{
	os << "The form's name is : " << param.getName() << " and has a execution and signing grade of: " << param.getGradeExec() << ", "<< param.getGradeSign();
	if(param.getSigned())
		os << "and it has been signed" << std::endl;
	else
		os << "and it hasn't been signed" << std::endl;
	return(os);
}
