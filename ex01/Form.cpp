/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 02:25:02 by tfiguero          #+#    #+#             */
/*   Updated: 2024/06/20 10:53:43 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return("Grade is already the highest couldnt increase it anymore");
}


const char* Form::GradeTooLowException::what() const  throw()
{
	return("Grade is already the lowest couldnt decrease it anymore");
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
	if(_grade_exec > 150 || _grade_sign > 150)
		throw GradeTooLowException();
	if(_grade_exec < 1 || _grade_sign < 1)
		throw GradeTooHighException();
	std::cout << "Form constructor called with name "<< name<< " and a grade to sign of "<< gradeSign << std::endl;
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
	if(param.getGrade()<= this->_grade_sign)
	{
		_signed = true;
	}else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& param)
{
	os << "The form's name is : " << param.getName() << "and has a execution and signing grade of: " << param.getGradeExec() << ", "<< param.getGradeSign();
	if(param.getSigned())
		os << "and it has been signed" << std::endl;
	else
		os << "and it hasn't been signed" << std::endl;
	return(os);
}
