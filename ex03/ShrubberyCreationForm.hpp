/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 06:34:53 by tfiguero          #+#    #+#             */
/*   Updated: 2024/06/20 10:40:02 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& old);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& old);
		~ShrubberyCreationForm();
		void	acctuallyExecute() const ;
		std::string getTarget() const;
	private:
		std::string _target;
};
std::ostream& operator<<(std::ostream& os, const AForm& param);
#endif