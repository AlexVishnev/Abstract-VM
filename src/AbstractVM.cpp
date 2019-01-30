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

AbstractVM::~AbstractVM() {}

//group 1 - cmd (push|assert)
//group 2 -     (int32(42))
//group 3 - type (int32)
//group 4 - value (42)
//grpup 5 - mantissa (.23)

std::regex insert_value("[\t ]*(push|assert)[\t ]*((int8|int16|int32|float|double)\\(([-]?[0-9]+(.[0-9]+)?)\\))[\t ]*([;].*)?");
std::regex exec_instruction("[\t ]*(pop|dump|add|sub|mul|div|mod|print|exit|sum|avg|sort|min|max)[\t ]*([;].*)?");
std::regex comment("[\t ]*([;].*)");

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
		{"exit", &AbstractVM::exit},
		{"sum", &AbstractVM::sum},
		{"avg", &AbstractVM::avg},
		{"sort", &AbstractVM::sort},
		{"min", &AbstractVM::min},
		{"max", &AbstractVM::max},
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
	} catch (std::invalid_argument &e) {
		std::cerr << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	} catch (char const* msg) {
		std::cerr << msg << std::endl;
	}
}

void	AbstractVM::verify(std::string line, int count) {
	try {
		if (!regex_match(line, insert_value) && !regex_match(line, exec_instruction) && !regex_match(line, comment))
		{
			throw LexicalExeption("(line " + std::to_string(count) + ")");
		}
		else if (regex_match(line, exec_instruction) && !line.find("exit"))
		{
			if (count_of_exits >= 1) {
				throw LexicalExeption("double exit.");
			}
			count_of_exits += 1;
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void	AbstractVM::push(eOperandType type, std::string const &value) {
	v.push_back(FactoryMethod().createOperand(type, value));
}

void	AbstractVM::assert(eOperandType type, std::string const &value)
{
	if (v.empty())
		throw EmpyStackException("Vector is empty. You can't assert am empty stack.");

	const IOperand* o = v.back();

	if (value != o->toString() || type != o->getType())
		throw "\033[31mAn assert instruction is false.\033[0m";

	std::cout << "\033[0;32mAn assert instruction is true\033[0m" << std::endl;
}

void AbstractVM::pop()
{
	if (v.empty())
		throw EmpyStackException("Vector is empty. You can't pop on an empty stack.");

	v.pop_back();
}

void AbstractVM::dump()
{
	for (std::vector<IOperand const *>::reverse_iterator i = v.rbegin();  i != v.rend(); ++i )
	{ 
		std::cout << "\033[0;32m" << (*i)->toString() << "\033[0m" << std::endl;
	}
}

void AbstractVM::add() {
	if (v.size() < 2)
		throw EmpyStackException("Instruction add applies only on two values. You have less.");

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
		throw EmpyStackException("Instruction sub applies only on two values. You have less.");

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
		throw EmpyStackException("Instruction mul applies only on two values. You have less.");

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
		throw EmpyStackException("Instruction div applies only on two values. You have less.");
	
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
		throw EmpyStackException("Instruction mod applies only on two values. You have less.");

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
		throw EmpyStackException("Vector is empty. You can't print on an empty stack.");

	const IOperand* o = v.back();

	if (o->getType() != 0)
		throw "\033[31mValue is not a 8-bit integer.\033[0m";

	int v = std::stoi(o->toString());
	std::cout << "\033[0;32m" << static_cast<char>(v) << " (" << v << ")" << "\033[0m" << std::endl;
}

void AbstractVM::exit() {
	std::exit(0);
}

void AbstractVM::sum() {
	if (v.empty())
		throw EmpyStackException("Vector is empty. You can't sum an empty stack.");

	float sum = 0.0f;
	for (std::vector<IOperand const *>::reverse_iterator i = v.rbegin();  i != v.rend(); ++i )
	{
		sum += std::atof((*i)->toString().c_str());
	}
	std::cout << "\033[0;32m" << sum << "\033[0m" << std::endl;
}

void AbstractVM::avg() {
	if (v.empty())
		throw EmpyStackException("Vector is empty. You can't arg an empty stack.");

	float sum = 0.0f;
	for (std::vector<IOperand const *>::reverse_iterator i = v.rbegin();  i != v.rend(); ++i )
	{
		sum += std::atof((*i)->toString().c_str());
	}
	float ans = sum / v.size();
	std::cout << "\033[0;32m" << ans << "\033[0m" << std::endl;
}

void AbstractVM::sort() {
	if (v.empty())
		throw EmpyStackException("Vector is empty. You can't sort an empty stack.");

	for (size_t i = 0; i < v.size(); i++)
		for (size_t j = 0; j < v.size(); j++)
			if (i != j && v[i]->toString() > v[j]->toString())
			{
				const IOperand *tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
}

void AbstractVM::min() {
	if (v.empty())
		throw EmpyStackException("Vector is empty. You can't min an empty stack.");

	float min = std::numeric_limits<float>::max();
	for (std::vector<IOperand const *>::reverse_iterator i = v.rbegin();  i != v.rend(); ++i )
	{
		if (std::atof((*i)->toString().c_str()) < min)
			min = std::atof((*i)->toString().c_str());
	}
	std::cout << "\033[0;32m" << min << "\033[0m" << std::endl;
}

void AbstractVM::max() {
	if (v.empty())
		throw EmpyStackException("Vector is empty. You can't max an empty stack.");

	float max = 0.0f;
	for (std::vector<IOperand const *>::reverse_iterator i = v.rbegin();  i != v.rend(); ++i )
	{
		if (std::atof((*i)->toString().c_str()) > max)
			max = std::atof((*i)->toString().c_str());
	}
	std::cout << "\033[0;32m" << max << "\033[0m" << std::endl;
}

int AbstractVM::getCountOfExits() {
	return count_of_exits;
}
