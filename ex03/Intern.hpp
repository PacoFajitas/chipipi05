/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:21 by tfiguero          #+#    #+#             */
/*   Updated: 2024/09/04 17:51:11 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &old);
		Intern& operator=(const Intern& old);
		~Intern();
		AForm* makeForm(std::string FName, std::string FTarget);
	
};
#endif