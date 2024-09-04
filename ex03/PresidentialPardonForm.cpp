/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 06:25:33 by tfiguero          #+#    #+#             */
/*   Updated: 2024/09/03 22:24:42 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardon", 25, 5), _target("paco")
{
	std::cout << "Basic constructor for PresidentialPardonForm has been called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardon", 25, 5), _target(target)
{
	std::cout << "A PresidentialPardonForm has been constructed with the target defined as " << target << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& old): AForm(old), _target(old._target)
{
	std::cout << "Copy constructor has been called for PresidentialPardonForm" << std::endl;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& old)
{
	AForm::operator=(old);
	_target = old._target;
	std::cout << "= operator overload has been called for PresidentialPardonForm" << std::endl;	
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor has been called for PresidentialPardonForm" << std::endl;
}
void	PresidentialPardonForm::acctuallyExecute() const 
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
std::string PresidentialPardonForm::getTarget() const
{
	return _target;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& param)
{
	os << "The form " << param.getName() << " requieres a grade of" << param.getGradeExec();
	os << " to be executed and a grade of " << param.getGradeSign() << " to be signed";
	if(param.getSigned())
		os << ", it has been signed";
	else
		os << ", it hasn't been signed";
	os << "and is targeting: " << param.getTarget() << std::endl;
	return os;
}