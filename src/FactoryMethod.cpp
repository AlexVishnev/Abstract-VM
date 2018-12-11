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

#include "FactoryMethod.hpp"

IOperand const *FactoryMethod::createInt8(std::string const &value) const {
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

FactoryMethod::FactoryMethod() {

}

FactoryMethod::~FactoryMethod() {
	
}

IOperand const *FactoryMethod::createOperand(eOperandType type, std::string const &value) const {
	switch (type) {
		case Int8:
			return createInt8(value);
			break;
		case Int16:
			return createInt16(value);
			break;
		case Int32:
			return createInt32(value);
			break;
		case Float:
			return createFloat(value);
			break;
		case Double:
			return createDouble(value);
			break;
	}
	return nullptr;
}

