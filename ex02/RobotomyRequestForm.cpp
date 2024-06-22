/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 06:25:42 by tfiguero          #+#    #+#             */
/*   Updated: 2024/06/20 10:35:35 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequest", 72, 45), _target("Paco")
{
	std::cout << "Basic constructor for a RobotomyRequestForm has been called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequest", 72, 45), _target(target)
{
	std::cout << "A RobotomyRequestForm has been constructed with the target defined as" << target << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& old) : AForm(old), _target(old._target)
{
	std::cout << "Copy constructor for RobotomyRequestForm has been called" << std::endl;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& old)
{
	AForm::operator=(old);
	this->_target = old._target;
	return *this;
	std::cout << "RobotomyRequestForm operator overload for equal called";	
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

std::string 	RobotomyRequestForm::getTarget() const
{
	return _target;
}
void	RobotomyRequestForm::acctuallyExecute() const
{
	std::srand(std::time(NULL));

	std::cout << "DRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR..." << std::endl;
	std::cout << _target << (std::rand() % 2 == 0 ? " has been robotomized!" : "'s robotomy failed. Try another limb.") << std::endl;
}