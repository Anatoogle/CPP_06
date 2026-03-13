/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 08:53:45 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/13 14:19:04 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal)
{
    if(checkIsChar(literal))
    {
        int value = literal[0];
        
        printChar(value);
        printInt(value);
        std::cout << "float: \t" << static_cast<float>(value) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl; 
        
        return;
    }

    if(checkIsPseudo(literal))
    {
        std::cout << "char: \timpossible" << std::endl;
        std::cout << "int: \timpossible" << std::endl;

        std::string pseudo = literal;
        std::transform(pseudo.begin(), pseudo.end(), pseudo.begin(), ::tolower);
        
        if(pseudo == "nan" || pseudo == "+inf" || pseudo == "-inf")
            std::cout << "float: \t" << pseudo << "f" << std::endl;
        else
            std::cout << "float: \t" << pseudo << std::endl;
            
        if(pseudo == "nanf" || pseudo == "+inff" || pseudo == "-inff")
            std::cout << "double: " << pseudo.substr(0, pseudo.length()-1) << std::endl;
        else
            std::cout << "double: " << pseudo << std::endl;
        
        return;
    }

    if(checkIsInt(literal))
    {
        int value = std::atoi(literal.c_str());
        
        printChar(value);
        printInt(value);
        std::cout << "float: \t" << static_cast<float>(value) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
        
        return;
    }

    if(checkIsFloat(literal))
    {
        int value = std::atoi(literal.c_str());

        printChar(value);
        printInt(value);
        printFloat(literal);
        printDouble(literal);

        return;
    }

    if(checkIsDouble(literal))
    {
        int value = std::atoi(literal.c_str());
        
        printChar(value);
        printInt(value);
        printFloat(literal);
        printDouble(literal);
        
        return;
    }
}

bool checkOnlyZeroAfterDot(const std::string &literal)
{
    size_t  dot = literal.find(".");
    if(dot == std::string::npos)
        return false;
    for (size_t i = dot+1; i < literal.length(); i++)
    {
        if(literal[i] != '0' && literal[i] != 'f')
            return false; 
    }

    return true;
}

void printChar(int value)
{
    if(value < 32 || value > 126)
        std::cout << "char: \tNon displayable" << std::endl;
    else
        std::cout << "char: \t'" << static_cast<char>(value) << "'" << std::endl;
}

void printInt(int value)
{
    std::cout << "int: \t" << value << std::endl;
}

void printFloat(const std::string &literal)
{
    double d = std::atof(literal.c_str());
    
    if(checkOnlyZeroAfterDot(literal))
        std::cout << "float: \t" << static_cast<float>(d) << ".0f" << std::endl;
    else
        std::cout << "float: \t" << static_cast<float>(d) << "f" << std::endl;
}

void printDouble(const std::string &literal)
{
    double d = std::atof(literal.c_str());

    if(checkOnlyZeroAfterDot(literal))
        std::cout << "double: " << static_cast<double>(d) << ".0" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(d) << std::endl;     
}

bool checkIsChar(const std::string &literal)
{
    if(literal.length() == 1 && !isdigit(literal[0]))
        return true;
        
    return false;
}

bool checkIsPseudo(const std::string &literal)
{
    std::string pseudoA[] = {"nan", "nanf", "+inf", "-inf", "+inff", "-inff"};
    int len = sizeof(pseudoA) / sizeof(pseudoA[0]);

    std::string s1 = literal;
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    
    for(int i = 0; i < len; i++)
    {
        std::string s2 = pseudoA[i];
        std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
        
        if(s1 == s2)
            return true;
    }
    
    return false;
}

bool checkIsInt(const std::string &literal)
{
    size_t pos = 0;
    if(literal[0] == '+' || literal[0] == '-')
        pos = 1;
    
    for (size_t i = pos; i < literal.length(); i++)
    {
        if(std::isdigit(literal[i]))
            continue;
        else
            return false;
    }
    
    return true;
}

bool checkIsFloat(const std::string &literal)
{
    size_t len = literal.length();

    if(literal[len-1] != 'f')
        return false; 
    
    size_t  pos = 0;
    int     point = 0;
    
    if(literal[0] == '+' || literal[0] == '-')
        pos = 1;
    
    for (size_t i = pos; i < len-1; i++)
    {
        if(std::isdigit(literal[i]))
            continue;
        else if(i < len-1 && literal[i] == '.' && std::isdigit(literal[i+1]))
        {
            point++;
            if(point > 1)
                return false;
            continue;
        }
        else
            return false;
    }
    
    if(point != 1)
        return false;
    
    return true;
}

bool checkIsDouble(const std::string &literal)
{
    size_t  len = literal.length();
    size_t  pos = 0;
    int     point = 0;
    
    if(literal[0] == '+' || literal[0] == '-')
        pos = 1;
    
    for (size_t i = pos; i < len; i++)
    {
        if(std::isdigit(literal[i]))
            continue;
        else if(i < len-1 && literal[i] == '.' && std::isdigit(literal[i+1]))
        {
            point++;
            if(point > 1)
                return false;
            continue;
        }
        else
            return false;
    }
    
    if(point != 1)
        return false;

    return true;
}
