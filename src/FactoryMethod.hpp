/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FactoryMethod.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:54:49 by omiroshn          #+#    #+#             */
/*   Updated: 2018/12/11 11:54:53 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORYMETHOD_HPP
#define FACTORYMETHOD_HPP

#include "IOperand.hpp"

class FactoryMethod
{
private:
	IOperand const *createInt8(std::string const &value) const;
	IOperand const *createInt16(std::string const &value) const;
	IOperand const *createInt32(std::string const &value) const;
	IOperand const *createFloat(std::string const &value) const;
	IOperand const *createDouble(std::string const &value) const;
public:
	FactoryMethod();
	~FactoryMethod();
	
	IOperand const *createOperand(eOperandType type, std::string const &value) const;
};

#endif
