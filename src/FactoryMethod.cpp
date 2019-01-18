/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FactoryMethod.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:54:46 by omiroshn          #+#    #+#             */
/*   Updated: 2018/12/11 11:54:47 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operand.hpp"
#include <limits>

IOperand const *FactoryMethod::createInt8(std::string const &value) const {
	try {
		int t = std::stoi(value);
		if (t < std::numeric_limits<int8_t>::min())
			throw Overflow();
		if (t > std::numeric_limits<int8_t>::max())
			throw Overflow();
		return new Operand<int8_t>(Int8, value);
	} catch (std::exception &e) {
		throw Overflow();
	}
	return nullptr;
}

IOperand const *FactoryMethod::createInt16(std::string const &value) const {
	return nullptr;
}

IOperand const *FactoryMethod::createInt32(std::string const &value) const {
	return nullptr;
}

IOperand const *FactoryMethod::createFloat(std::string const &value) const {
	return nullptr;
}

IOperand const *FactoryMethod::createDouble(std::string const &value) const {
	return nullptr;
}

IOperand const *FactoryMethod::createOperand(eOperandType type, std::string const &value) const {
	IOperand const *(FactoryMethod::*method[])(std::string const &value) const = {
		&FactoryMethod::createInt8,
		&FactoryMethod::createInt16,
		&FactoryMethod::createInt32,
		&FactoryMethod::createFloat,
		&FactoryMethod::createDouble
	};
	return ((this->*method[type])(value));
}

