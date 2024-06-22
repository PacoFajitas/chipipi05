/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:05:53 by tfiguero          #+#    #+#             */
/*   Updated: 2024/06/20 11:11:18 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
	private:
		std::string _name;
		int _grade;
	public:
		class GradeTooHighException : public std::exception
		{
			public:
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
			const char* what() const throw();
		};
		Bureaucrat();
		Bureaucrat(const Bureaucrat& old);
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const int grade);
		Bureaucrat& operator=(const Bureaucrat& old);
		~Bureaucrat();
		std::string getName() const;
		int	getGrade() const ;
		void increaseGrade();
		void decreaseGrade();
		void signForm(AForm& param);
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& param);

#endif