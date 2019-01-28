/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:30:55 by omiroshn          #+#    #+#             */
/*   Updated: 2018/12/17 15:30:56 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "FactoryMethod.hpp"
#include <sstream>

template<class T>
class Operand : public IOperand
{
private:
	eOperandType type;
	std::string value;
public:
	Operand();
	Operand(eOperandType type, std::string const &value) {
		this->type = type;
		this->value = value;
	}
	Operand(Operand const &rhs) {
		*this = rhs;
	}
	Operand &operator=(Operand const &rhs) {
		if (this != &rhs) {
			type = rhs.type;
			value = rhs.value;
		}
		return *this;
	}
	virtual ~Operand(){}
	
	int					getPrecision(void) const {
		return static_cast<int>(this->type);
	}
	
	eOperandType		getType(void) const {
		return this->type;
	}
	
	std::string const	&toString(void) const {
		return this->value;
	}

	IOperand const		*operator+(IOperand const &rhs) const {
		std::ostringstream ss;
		try {
			eOperandType newType = std::max(this->type, rhs.getType());
			double value = std::stod(this->value) + std::stod(rhs.toString());
			ss << value;
			return FactoryMethod().createOperand(newType, ss.str());
		} catch(std::exception &e) {
			throw Overflow(ss.str());
		}
	}

	IOperand const		*operator-(IOperand const &rhs) const {
		std::ostringstream ss;
		try {
			eOperandType newType = std::max(this->type, rhs.getType());
			double value = std::stod(this->value) - std::stod(rhs.toString());
			ss << value;
			return FactoryMethod().createOperand(newType, ss.str());
		} catch(std::exception &e) {
			throw Overflow(ss.str());
		}
	}

	IOperand const		*operator*(IOperand const &rhs) const {
		std::ostringstream ss;
		try {
			eOperandType newType = std::max(this->type, rhs.getType());
			double value = std::stod(this->value) * std::stod(rhs.toString());
			ss << value;
			return FactoryMethod().createOperand(newType, ss.str());
		} catch(std::exception &e) {
			throw Overflow(ss.str());
		}
	}

	IOperand const		*operator/(IOperand const &rhs) const {
		std::ostringstream ss;
		try {
			double other = std::stod(rhs.toString());
			if (other == 0)
				throw DivisionByZero();
			eOperandType newType = std::max(this->type, rhs.getType());
			double value = std::stod(this->value) / other;
			ss << value;
			return FactoryMethod().createOperand(newType, ss.str());
		} catch(DivisionByZero &e) {
			throw DivisionByZero();
		} catch(std::exception &e) {
			throw Overflow(ss.str());
		}
	}

	IOperand const		*operator%(IOperand const &rhs) const {
		std::ostringstream ss;
		try {
			double other = std::stod(rhs.toString());
			if (other == 0)
				throw ModuloByZero();
			eOperandType newType = std::max(this->type, rhs.getType());
			double value = std::stod(this->value) / other;
			ss << value;
			return FactoryMethod().createOperand(newType, ss.str());
		} catch(ModuloByZero &e) {
			throw ModuloByZero();
		} catch(std::exception &e) {
			throw Overflow(ss.str());
		}
	}

	bool operator==( IOperand const & rhs ) const
	{
		double rv = std::stod(rhs.toString());
		double lv = std::stod(this->toString());

		return (lv == rv) ? true : false;
	}

	bool operator!=( IOperand const & rhs ) const
	{
		return !(*this == rhs);
	}
};

#endif
