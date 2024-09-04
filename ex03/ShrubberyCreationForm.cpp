/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 07:11:46 by tfiguero          #+#    #+#             */
/*   Updated: 2024/06/20 11:15:08 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreation", 145, 137), _target("paco")
{
	std::cout <<  "Basic constructor called for ShrubberyCreationForm" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreation", 145, 137), _target(target)
{
	std::cout <<  "Constructor called for ShrubberyCreationForm with target " << target << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& old): AForm(old), _target(old._target)
{
	std::cout <<  "Copyy constructor called for ShrubberyCreationForm" << std::endl;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& old)
{
	std::cout <<  "= operator overload called for ShrubberyCreationForm" << std::endl;
	AForm::operator=(old);
	_target = old._target;
	return(*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout <<  "Destructor called for ShrubberyCreationForm" << std::endl;
}
void	ShrubberyCreationForm::acctuallyExecute() const 
{
	std::string filename = _target + "_shrubbery";
	std::ofstream outfile(filename.c_str(), std::ios::out);
	if(!outfile.is_open())
	{
		std::cerr << "Error opening the file" << std::endl;
		return;
	}
	outfile << "          * " << std::endl;
    outfile << "     	 *** "<< std::endl;
    outfile << " 		**o** " <<std::endl;
    outfile << " 	   ******* " <<std::endl;
    outfile << "      **o**o** " <<std::endl;
	outfile << "     *********** " <<std::endl;
	outfile << "    ***o**o**o*** " <<std::endl;
	outfile << "   *************** " << std::endl;
	outfile << "  **o**o**o**o**o** " << std::endl;
	outfile << " ******************* " << std::endl;
    outfile << " 		  ||| " << std::endl;
	outfile << "		  ||| " << std::endl;
	outfile << "		  ||| " << std::endl;
	outfile.close();	
}
std::string ShrubberyCreationForm::getTarget() const
{
	return _target;
}