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
#include <regex>
#include <vector>

class AbstractVM
{
public:
	void process(std::string line);
	AbstractVM();
	~AbstractVM();
};

#endif
