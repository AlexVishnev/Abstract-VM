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

class LexicalExeption : public std::exception
{
private:
	std::string str;
public:
	LexicalExeption();
	LexicalExeption(std::string str);
	virtual ~LexicalExeption();
	
	virtual const char *what() const throw();
};

class EmpyStackException : public std::exception
{
private:
	std::string str;
public:
	EmpyStackException();
	EmpyStackException(std::string str);
	virtual ~EmpyStackException();
	
	virtual const char *what() const throw();
};

class OverflowUnderflowException : public std::out_of_range
{
private:
	std::string value;
public:
	OverflowUnderflowException();
	OverflowUnderflowException(std::string value);
	virtual ~OverflowUnderflowException();
	
	virtual const char *what() const throw();
};

class DivisionByZero : public std::invalid_argument
{
public:
	DivisionByZero();
	virtual ~DivisionByZero();
	virtual const char *what() const throw();
};

class ModuloByZero : public std::invalid_argument
{
public:
	ModuloByZero();
	virtual ~ModuloByZero();
	virtual const char *what() const throw();
};

#endif
