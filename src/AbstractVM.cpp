/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:46:31 by omiroshn          #+#    #+#             */
/*   Updated: 2018/12/11 11:46:33 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.hpp"

AbstractVM::AbstractVM() {
	already_exited = false;
}

AbstractVM::~AbstractVM() {
	
}

std::regex insert_value("[\t ]*(push|assert)[\t ]*((int8|int16|int32|float|double)\\(([-]?[0-9]+(.[0-9]+)?)\\))[\t ]*([;].*)?");
std::regex exec_instruction("[\t ]*(pop|dump|add|sub|mul|div|mod|print|exit)[\t ]*([;].*)?");
std::regex comment("[\t ]*([;].*)");

//group 1 - cmd (push|assert)
//group 2 -     (int32(42))
//group 3 - type (int32)
//group 4 - value (42)
//grpup 5 - mantissa (.23)

void	AbstractVM::execute(std::string line)
{
	std::map<std::string, void (AbstractVM::*)(eOperandType type, std::string const &value)> value_map = {
		{"push", &AbstractVM::push},
		{"assert", &AbstractVM::assert},
	};
	std::map<std::string, void (AbstractVM::*)()> instruction_map = {
		{"pop", &AbstractVM::pop},
		{"dump", &AbstractVM::dump},
		/*
		{"add", &AbstractVM::add},
		{"sub", &AbstractVM::sub},
		{"mul", &AbstractVM::mul},
		{"div", &AbstractVM::div},
		{"mod", &AbstractVM::mod},
		{"print", &AbstractVM::print},
		{"exit", &AbstractVM::exit}
		*/
	};
	std::smatch match;

	if (regex_match(line, insert_value)) {
		std::regex_search(line, match, insert_value);
		// (this->*value_map[match.str(1)])
		// for (std::smatch::iterator it = match.begin(); it!=match.end(); ++it) {
		// 	std::cout << *it << "|";
		// }
		// std::cout << std::endl;
		std::cout << match.str(3) << " " << match.str(4) << std::endl;
		// std::cout <<  << std::endl;
		std::cout << "(push|assert)" << std::endl;
	} else if (regex_match(line, exec_instruction)) {
		std::cout << "(pop|dump|add|sub|mul|div|mod|print|exit)" << std::endl;
	} else if (regex_match(line, comment)) {
		std::cout << "comment" << std::endl;
	} else {
		std::cout << "WRONG!" << std::endl;
	}
}

void	AbstractVM::verify(std::string line, int count) {
	if (!regex_match(line, insert_value)
		&& !regex_match(line, exec_instruction)
		&& !regex_match(line, comment))
	{
		std::cout << "Lexical exeption" << std::endl;
	} else if (regex_match(line, exec_instruction) && !line.find("exit")) {
		if (already_exited == true) {
			already_exited = false;
			throw "Lexical exeption: double exit.";
		}
		already_exited = true;
	}
}

void	AbstractVM::push(eOperandType type, std::string const &value) {
	v.push_back(fabric.createOperand(type, value));
}

void	AbstractVM::assert(eOperandType type, std::string const &value) {
	
}

void AbstractVM::pop() {
	if (v.empty())
		throw "Vector is empty";
	v.pop_back();
}

void AbstractVM::dump() {
	
}
