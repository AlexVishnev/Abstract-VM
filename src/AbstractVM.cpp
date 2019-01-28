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
	count_of_exits = 0;
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

eOperandType AbstractVM::getType(std::string const &type) {
	std::map <std::string, eOperandType> types = {
		{"int8", Int8},
		{"int16", Int16},
		{"int32", Int32},
		{"float", Float},
		{"double", Double}
	};
	return types[type];
}

void	AbstractVM::execute(std::string line)
{
	std::map<std::string, void (AbstractVM::*)(
												eOperandType type,
												std::string const &value
	)> value_map = {
		{"push", &AbstractVM::push},
		{"assert", &AbstractVM::assert}
	};
	std::map<std::string, void (AbstractVM::*)()> instruction_map = {
		{"pop", &AbstractVM::pop},
		{"dump", &AbstractVM::dump},
		{"add", &AbstractVM::add},
		{"sub", &AbstractVM::sub},
		{"mul", &AbstractVM::mul},
		{"div", &AbstractVM::div},
		{"mod", &AbstractVM::mod},
		{"print", &AbstractVM::print}, 
		{"exit", &AbstractVM::exit}
	};
	std::smatch match;

	try {
		if (regex_match(line, insert_value)) {
			std::regex_search(line, match, insert_value);
			(this->*value_map[match.str(1)])(getType(match.str(3)), match.str(4));
		} else if (regex_match(line, exec_instruction)) {
			std::regex_search(line, match, exec_instruction);
			(this->*instruction_map[match.str(1)])();
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	} catch (char const* msg) {
		std::cerr << msg << std::endl;
	}
}

void	AbstractVM::verify(std::string line, int count) {
	if (!regex_match(line, insert_value) && !regex_match(line, exec_instruction) && !regex_match(line, comment))
	{
		// throw
		std::cout << "Lexical exeption(line " << count << ")" << std::endl;
	}
	else if (regex_match(line, exec_instruction) && !line.find("exit"))
	{
		if (count_of_exits >= 1) {
			throw "Lexical exeption: double exit.";
		}
		count_of_exits += 1;
	}
}

void	AbstractVM::push(eOperandType type, std::string const &value) {
	v.push_back(FactoryMethod().createOperand(type, value));
}

void	AbstractVM::assert(eOperandType type, std::string const &value)
{
	if (v.empty())
		throw "Vector is empty. You can't assert am empty stack.";

	const IOperand* o = v.back();

	if (value != o->toString() || type != o->getType())
		throw "An assert instruction is false.";

	std::cout << "An assert instruction is true" << std::endl;
}

void AbstractVM::pop()
{
	if (v.empty())
		throw "Vector is empty. You can't pop on an empty stack.";

	v.pop_back();
}

void AbstractVM::dump()
{
	for (std::vector<IOperand const *>::reverse_iterator i = v.rbegin();  i != v.rend(); ++i )
	{ 
		std::cout << (*i)->toString() << std::endl;
	}
}

void AbstractVM::add() {
	if (v.size() < 2)
		throw "Instruction add applies only on two values. You have less.";

	const IOperand* o1 = v.back();
	v.pop_back();
	const IOperand* o2 = v.back();
	v.pop_back();

	v.push_back(*o1 + *o2);

	delete o1;
	delete o2;
}

void AbstractVM::sub() {
	if (v.size() < 2)
		throw "Instruction sub applies only on two values. You have less.";

	const IOperand* o1 = v.back();
	v.pop_back();
	const IOperand* o2 = v.back();
	v.pop_back();

	v.push_back(*o2 - *o1);

	delete o1;
	delete o2;
}
void AbstractVM::mul() {
	if (v.size() < 2)
		throw "Instruction mul applies only on two values. You have less.";

	const IOperand* o1 = v.back();
	v.pop_back();
	const IOperand* o2 = v.back();
	v.pop_back();

	v.push_back(*o1 * *o2);

	delete o1;
	delete o2;
}

void AbstractVM::div() {
	if (v.size() < 2)
		throw "Instruction div applies only on two values. You have less.";
	
	const IOperand* o1 = v.back();
	v.pop_back();
	const IOperand* o2 = v.back();
	v.pop_back();

	v.push_back(*o2 / *o1);

	delete o1;
	delete o2;
}

void AbstractVM::mod() {
	if (v.size() < 2)
		throw "Instruction mod applies only on two values. You have less.";

	const IOperand* o1 = v.back();
	v.pop_back();
	const IOperand* o2 = v.back();
	v.pop_back();

	v.push_back(*o2 % *o1);

	delete o1;
	delete o2;
}

void AbstractVM::print() {

	if (v.empty())
		throw "Vector is empty. You can't print on an empty stack.";

	const IOperand* o = v.back();

	if (o->getType() != 0)
		throw "Value is not a 8-bit integer.";

	int v = std::stoi(o->toString());
	std::cout << static_cast<char>(v) << " (" << v << ")" << std::endl;
}

void AbstractVM::exit() {
	std::exit(0);
}

int AbstractVM::getCountOfExits() {
	return count_of_exits;
}
