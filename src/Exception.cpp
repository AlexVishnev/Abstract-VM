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

Overflow::Overflow() : value("0")
{}
Overflow::Overflow(std::string value) : value(value)
{}
Overflow::~Overflow()
{}
const char *Overflow::what() const throw()
{
	std::string str = "Overflow with the value: " + value;
	return str.c_str();
}

DivisionByZero::DivisionByZero()
{}
DivisionByZero::~DivisionByZero()
{}
const char *DivisionByZero::what() const throw()
{
	std::string str = "Division by zero!";
	return str.c_str();
}

ModuloByZero::ModuloByZero()
{}
ModuloByZero::~ModuloByZero()
{}
const char *ModuloByZero::what() const throw()
{
	std::string str = "Modulo by zero!";
	return str.c_str();
}