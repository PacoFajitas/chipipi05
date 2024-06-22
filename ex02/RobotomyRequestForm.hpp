/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 06:34:42 by tfiguero          #+#    #+#             */
/*   Updated: 2024/06/20 11:17:23 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& old);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& old);
		~RobotomyRequestForm();
		void	acctuallyExecute() const ;
		std::string getTarget() const;
	private:
		std::string _target;
};
std::ostream& operator<<(std::ostream& os, const AForm& param);
#endif