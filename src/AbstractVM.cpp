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

void	AbstractVM::execute(std::string line)
{
	std::map<std::string, void (AbstractVM::*)(eOperandType type, std::string const &value)> value_map = {
		{"push", &AbstractVM::push},
		{"assert", &AbstractVM::assert},
	};
	std::map<std::string, void (AbstractVM::*)()> instruction_map = {
		{"pop", &AbstractVM::pop},
		{"dump", &AbstractVM::dump},
	};
	std::regex insert_value("([\t ]*)(push|assert)([\t ]*)((int8|int16|int32)\\([-]?[0-9]+\\)|(float|double)\\([-]?[0-9]+.[0-9]+\\))([\t ]*)([;].*)?");
	std::regex exec_instruction("([\t ]*)(pop|dump|add|sub|mul|div|mod|print|exit)([\t ]*)([;].*)?");
	std::regex comment("([\t ]*)([;].*)");

	if (regex_match(line, insert_value)) {
		std::cout << "(push|assert)" << std::endl;
	} else if (regex_match(line, exec_instruction)) {
		std::cout << "(pop|dump|add|sub|mul|div|mod|print|exit)" << std::endl;
	} else if (regex_match(line, comment)) {
		std::cout << "comment" << std::endl;
	} else {
		std::cout << "WRONG!" << std::endl;
	}
}

void	AbstractVM::verify(std::string line) {
	std::regex insert_value("([\t ]*)(push|assert)([\t ]*)((int8|int16|int32)\\([-]?[0-9]+\\)|(float|double)\\([-]?[0-9]+.[0-9]+\\))([\t ]*)([;].*)?");
	std::regex exec_instruction("([\t ]*)(pop|dump|add|sub|mul|div|mod|print|exit)([\t ]*)([;].*)?");
	std::regex comment("([\t ]*)([;].*)");

	if (!regex_match(line, insert_value)
		&& !regex_match(line, exec_instruction)
		&& !regex_match(line, comment))
	{
		throw "Lexical exeption";
	} else if (regex_match(line, exec_instruction) && line.find("exit")) {
		if (already_exited) {
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
