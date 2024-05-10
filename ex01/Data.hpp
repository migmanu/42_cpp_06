/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:42:57 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/05/10 16:44:52 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Data_HPP
#define Data_HPP

#include <string>
class Data
{
  public:
	Data(void);
	Data(const Data &src);
	~Data(void);

	Data &operator=(const Data &rhs);
	std::string type;
	int value;
};

#endif // !Data_HPP
