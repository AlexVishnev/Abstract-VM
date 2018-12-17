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
	bool already_exited;
	FactoryMethod fabric;
	std::vector<IOperand const *> v;

	void push(eOperandType type, std::string const &value);
	void assert(eOperandType type, std::string const &value);
	void pop();
	void dump();
public:
	void execute(std::string line);
	void verify(std::string line);
	AbstractVM();
	~AbstractVM();
};

#endif
