/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:51:36 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/04/24 15:54:05 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <variant>

class ScalarConverter
{
  public:
	static void convert(std::string str);

  private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &src);
	~ScalarConverter(void);

	ScalarConverter &operator=(const ScalarConverter &rhs);
};
