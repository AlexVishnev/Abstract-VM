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

AbstractVM::AbstractVM()
{
	
}

void	AbstractVM::process(std::string line)
{
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

AbstractVM::~AbstractVM()
{

}
