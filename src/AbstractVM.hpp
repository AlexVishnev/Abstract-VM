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
	std::vector<IOperand const *> v;

	int count_of_exits;

	void push(eOperandType type, std::string const &value);
	void assert(eOperandType type, std::string const &value);
	void pop();
	void dump();
	void add();
	void sub();
	void mul();
	void div();
	void mod();
	void print();
	void exit();

	//bonus
	void sum();
	void avg();
	void sort();
	void min();
	void max();
	eOperandType getType(std::string const &type);
public:
	int getCountOfExits();
	void execute(std::string line);
	void verify(std::string line, int count);
	AbstractVM();
	~AbstractVM();
};

#endif
