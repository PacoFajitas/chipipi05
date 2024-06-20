/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 02:25:14 by tfiguero          #+#    #+#             */
/*   Updated: 2024/06/20 05:10:00 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Form
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
		Form();
		Form(const std::string name);
		Form(const std::string name, const int gradeSign);
		Form(const std::string name, const int gradeSign, const int gradeExec);
		Form(const int gradeSign, const int gradeExec);
		Form(const int gradeSign);
		Form(const std::string name, const int gradeExec);
		Form(const int gradeExec);
		Form(const Form& old);
		Form& operator=(const Form& old);
		~Form();
		std::string getName() const;
		bool		getSigned() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
		void		beSigned(const Bureaucrat& param);
};
std::ostream& operator<<(std::ostream& os, const Form& param);
#endif