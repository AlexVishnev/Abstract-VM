/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:15:52 by omiroshn          #+#    #+#             */
/*   Updated: 2019/01/18 19:15:52 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_HPP

#include <string>
#include <iostream>

class Overflow : public std::exception
{
private:
	std::string value;
public:
	Overflow();
	Overflow(std::string value);
	~Overflow();
	
	virtual const char *what() const throw();
};

class DivisionByZero : public std::exception
{
public:
	DivisionByZero();
	~DivisionByZero();
	virtual const char *what() const throw();
};

class ModuloByZero : public std::exception
{
public:
	ModuloByZero();
	~ModuloByZero();
	virtual const char *what() const throw();
};

#endif
