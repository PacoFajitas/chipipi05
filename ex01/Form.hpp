/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 02:25:14 by tfiguero          #+#    #+#             */
/*   Updated: 2024/06/20 02:48:24 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
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
		Form(const Form& old);
		Form& operator=(const Form& old);
		~Form();
		std::string getName() const;
		bool		getSigned() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
};
std::ostream& operator<<(std::ostream& os, const Form& param);
#endif