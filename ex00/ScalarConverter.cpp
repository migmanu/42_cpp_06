/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:51:44 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/05/08 16:47:38 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

static bool isChar(std::string str)
{
	if (str.length() > 1 || std::isalpha(str[0]) == 0)
		return false;
	return true;
}

static bool isInt(std::string str)
{
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
		if (std::isdigit(*it) == 0)
			return false;
	return true;
}

static bool isFloat(std::string str)
{
	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 ||
		str.compare("nanf") == 0)
		return true;

	if (str[0] == '.' || std::count(str.begin(), str.end(), '.') != 1 ||
		str[str.length() - 1] != 'f' || std::count(str.begin(), str.end(), 'f') != 1)
		return false;

	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
		if (std::isdigit(*it) == 0 && *it != '.' && *it != 'f')
			return false;
	return true;
}

static bool isDouble(std::string str)
{
	if (str.compare("-inf") == 0 || str.compare("+inf") == 0 ||
		str.compare("nan") == 0)
		return true;

	if (str[0] == '.' || std::count(str.begin(), str.end(), '.') != 1 ||
		std::isdigit(str[str.length() - 1]) == 0)
		return false;

	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
		if (std::isdigit(*it) == 0 && *it != '.')
			return false;
	return true;
}

static int _getType(std::string str)
{
	if (str.length() == 0 || str.length() > 6)
		return TOO_LARGE;
	else if (isChar(str))
		return CHAR;
	else if (isInt(str))
		return INT;
	else if (isFloat(str))
		return FLOAT;
	else if (isDouble(str))
		return DOUBLE;
	return UNKNOWN;
}

// static bool isPseudoLiteral(const std::string &literal)
// {
// 	return (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
// 			literal == "-inf" || literal == "+inf" || literal == "nan");
// }

static int _stoi(const std::string &str)
{
	int num;
	std::stringstream stream(str);

	stream >> num;
	return num;
}

static float _stof(const std::string &str)
{
	float num;
	std::stringstream stream(str);

	stream >> num;
	return num;
}

static void handleChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void handleInt(int nbr)
{
	if (isprint(nbr))
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << nbr << std::endl;
	std::cout << "float: " << static_cast<float>(nbr) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(nbr) << ".0" << std::endl;
}

static void handleFLoat(float nbr)
{
	if (isprint(nbr))
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << nbr << "f"
			  << std::endl;
	std::cout << std::fixed << std::setprecision(1)
			  << "double: " << static_cast<double>(nbr) << std::endl;
	std::cout.unsetf(std::ios_base::fixed);
	std::cout.precision(std::numeric_limits<double>::digits10 + 1);
}

static void handleDouble(float nbr)
{
	if (isprint(nbr))
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	std::cout << std::fixed << std::setprecision(1)
			  << "float: " << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << nbr
			  << std::endl;
	std::cout.unsetf(std::ios_base::fixed);
	std::cout.precision(std::numeric_limits<double>::digits10 + 1);
}

void ScalarConverter::convert(std::string str)
{
	switch (_getType(str))
	{
	case CHAR: {
		handleChar(str[0]);
		break;
	}
	case INT: {
		handleInt(_stoi(str));
		break;
	}
	case FLOAT: {
		handleFLoat(_stof(str));
		break;
	}
	case DOUBLE: {
		handleDouble(_stof(str));
		break;
	}
	case TOO_LARGE: {
		std::cout << "Inputed literal is too large." << std::endl << std::endl;
		break;
	}
	case UNKNOWN: {
		std::cout << "Inputed literal is type unknown." << std::endl << std::endl;
		break;
	}
	}
}
