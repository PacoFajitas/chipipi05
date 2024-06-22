/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 02:25:14 by tfiguero          #+#    #+#             */
/*   Updated: 2024/06/20 06:32:33 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:
		const std::string 	_name;
		const int			_grade_exec;
		const int 			_grade_sign;
		bool 				_signed;
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
		class NotSignedException : public std::exception
		{
			public:
			const char* what() const throw();
		};
		AForm();
		AForm(const std::string name);
		AForm(const std::string name, const int gradeSign);
		AForm(const std::string name, const int gradeSign, const int gradeExec);
		AForm(const int gradeSign, const int gradeExec);
		AForm(const int gradeSign);
		AForm(const AForm& old);
		AForm& operator=(const AForm& old);
		virtual ~AForm();
		std::string getName() const;
		bool		getSigned() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
		virtual std::string 		getTarget() const = 0;
		void		beSigned(const Bureaucrat& param);
		virtual void		acctuallyExecute() const = 0;
		void execute(Bureaucrat const & executor);
};
std::ostream& operator<<(std::ostream& os, const AForm& param);

#endif