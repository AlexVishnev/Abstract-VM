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

#include <iostream>
#include <fstream>

class AbstractVM
{
private:
	std::string getLine();
public:
	AbstractVM();
	AbstractVM(const char *file);
	~AbstractVM();
	
};

#endif
