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

std::string AbstractVM::getLine()
{
	std::string str;

	if (std::getline(std::cin, str))
		return (str);
	std::exit(1);
}

AbstractVM::AbstractVM()
{
	std::string str;

	while (1)
	{
		str = getLine();
	}
}

AbstractVM::AbstractVM(const char *file)
{
	std::ifstream infile(file);
	std::string line;

	while (std::getline(infile, line))
	{
		std::cout << line << std::endl;
	}
}

AbstractVM::~AbstractVM()
{

}
