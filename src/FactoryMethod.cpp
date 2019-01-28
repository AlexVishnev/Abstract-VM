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
			throw Overflow(value);
		if (t > std::numeric_limits<int8_t>::max())
			throw Overflow(value);
		return new Operand<int8_t>(Int8, value);
	} catch (std::exception &e) {
		throw Overflow(value);
	}
}

IOperand const *FactoryMethod::createInt16(std::string const &value) const {
	try {
		int t = std::stoi(value);
		if (t < std::numeric_limits<int16_t>::min())
			throw Overflow(value);
		if (t > std::numeric_limits<int16_t>::max())
			throw Overflow(value);
		return new Operand<int16_t>(Int16, value);
	} catch (std::exception &e) {
		throw Overflow(value);
	}
}

IOperand const *FactoryMethod::createInt32(std::string const &value) const {
	try {
		int t = std::stoi(value);
		if (t < std::numeric_limits<int32_t>::min())
			throw Overflow(value);
		if (t > std::numeric_limits<int32_t>::max())
			throw Overflow(value);
		return new Operand<int32_t>(Int32, value);
	} catch (std::exception &e) {
		throw Overflow(value);
	}
}

IOperand const *FactoryMethod::createFloat(std::string const &value) const {
	try {
		float t = std::stof(value);
		if (t < std::numeric_limits<float>::lowest()) {
			throw Overflow(value);
		}
		if (t > std::numeric_limits<float>::max()) {
			throw Overflow(value);
		}
		return new Operand<float>(Float, value);
	} catch (std::exception &e) {
		throw Overflow(value);
	}
}

IOperand const *FactoryMethod::createDouble(std::string const &value) const {
	try {
		double t = std::stod(value);
		if (t < std::numeric_limits<double>::lowest())
			throw Overflow(value);
		if (t > std::numeric_limits<double>::max())
			throw Overflow(value);
		return new Operand<double>(Double, value);
	} catch (std::exception &e) {
		throw Overflow(value);
	}
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

