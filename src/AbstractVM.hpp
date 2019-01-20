/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:49:58 by omiroshn          #+#    #+#             */
/*   Updated: 2018/12/11 13:49:58 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP

#include "IOperand.hpp"
#include "FactoryMethod.hpp"
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <map>

class AbstractVM
{
private:
	FactoryMethod f;
	std::vector<IOperand const *> v;

	bool already_exited;

	void push(eOperandType type, std::string const &value);
	void assert(eOperandType type, std::string const &value);
	void pop();
	void dump();
	eOperandType getType(std::string const &type);
public:
	void execute(std::string line);
	void verify(std::string line, int count);
	AbstractVM();
	~AbstractVM();
};

#endif
