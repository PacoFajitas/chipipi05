/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 06:34:31 by tfiguero          #+#    #+#             */
/*   Updated: 2024/06/20 11:20:03 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& old);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& old);
		~PresidentialPardonForm();
		void	acctuallyExecute() const ;
		std::string getTarget() const;
	private:
		std::string _target;	
};
std::ostream& operator<<(std::ostream& os, const AForm& param);
#endif