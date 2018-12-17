/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:49:14 by omiroshn          #+#    #+#             */
/*   Updated: 2018/12/11 13:49:15 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.hpp"

std::string getLine()
{
	std::string str;

	if (std::getline(std::cin, str))
		return (str);
	std::exit(1);
}

int main(int argc, char const *argv[])
{
	AbstractVM avm;
	std::string line;
	std::vector<std::string> v;

	if (argc == 1)
	{
		while (1)
		{
			line = getLine();
			if (line == ";;")
				break ;
			v.push_back(line);
		}
		try {
			for (auto &line : v) {
				avm.execute(line);
			}
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	else if (argc == 2)
	{
		std::ifstream infile(argv[1]);
		if (!infile.is_open())
			std::cout << "Error opening file" << std::endl;
		else {
			while (std::getline(infile, line))
				v.push_back(line);
			try {
				for (auto &line : v) {
					avm.execute(line);
				}
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
	} else
	{
		std::cout << "Usage: ./avm [<no parameters>] | <filename>" << std::endl;
	}
	return 0;
}
