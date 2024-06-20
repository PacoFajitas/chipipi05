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
class AForm
{
	private:
		const std::string 	_name;
		bool 				_signed;
		const int 			_grade_sign;
		const int			_grade_exec;
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
		AForm();
		AForm(const std::string name);
		AForm(const std::string name, const int gradeSign);
		AForm(const std::string name, const int gradeSign, const int gradeExec);
		AForm(const int gradeSign, const int gradeExec);
		AForm(const int gradeSign);
		AForm(const std::string name, const int gradeExec);
		AForm(const int gradeExec);
		AForm(const AForm& old);
		AForm& operator=(const AForm& old);
		virtual ~AForm();
		std::string getName() const;
		bool		getSigned() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
		virtual std::string 		getTarget() const = 0;
		void		beSigned(const Bureaucrat& param);
		virtual void		beExecuted() const = 0;
};
std::ostream& operator<<(std::ostream& os, const AForm& param);
#endif