/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 22:56:06 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/13 14:02:08 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <algorithm>

bool checkIsChar(const std::string &literal);
bool checkIsInt(const std::string &literal);
bool checkIsFloat(const std::string &literal);
bool checkIsDouble(const std::string &literal);
bool checkIsPseudo(const std::string &literal);

void printChar(int value);
void printInt(int value);
void printFloat(const std::string &literal);
void printDouble(const std::string &literal);
bool checkOnlyZeroAfterDot(const std::string &literal);


class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &copy);
    public:
        static void convert(const std::string &literal);      
};
