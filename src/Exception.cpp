/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:15:49 by omiroshn          #+#    #+#             */
/*   Updated: 2019/01/18 19:15:49 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exception.hpp"

OverflowUnderflowException::OverflowUnderflowException() : std::out_of_range(""), value("0")
{}
OverflowUnderflowException::OverflowUnderflowException(std::string value) : std::out_of_range(""), value(value)
{}
OverflowUnderflowException::~OverflowUnderflowException()
{}
const char *OverflowUnderflowException::what() const throw()
{
	std::string str = "\033[31mOverflowUnderflowExeption: Overflow/Underflow of the value: " + value + "\033[0m";
	return str.c_str();
}

EmpyStackException::EmpyStackException() : str("0")
{}
EmpyStackException::EmpyStackException(std::string str) : str(str)
{}
EmpyStackException::~EmpyStackException()
{}
const char *EmpyStackException::what() const throw()
{
	std::string line = "\033[31mEmpyStackException: " + str + "\033[0m";
	return line.c_str();
}

LexicalExeption::LexicalExeption() : str("error.")
{}
LexicalExeption::LexicalExeption(std::string str) : str(str)
{}
LexicalExeption::~LexicalExeption()
{}
const char *LexicalExeption::what() const throw()
{
	std::string line = "\033[31mLexicalExeption: " + str + "\033[0m";
	return line.c_str();
}

DivisionByZero::DivisionByZero() : std::invalid_argument("")
{}
DivisionByZero::~DivisionByZero()
{}
const char *DivisionByZero::what() const throw() {
	return ("\033[31mInvalid argument: Division by zero!\033[0m");
}

ModuloByZero::ModuloByZero() : std::invalid_argument("")
{}
ModuloByZero::~ModuloByZero()
{}
const char *ModuloByZero::what() const throw() {
	return ("\033[31mInvalid argument: Modulo by zero!\033[0m");
}