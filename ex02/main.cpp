/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:55:13 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/05/14 18:53:56 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base *generate(void)
{
	std::srand(std::time(0));
	int r = rand();
	r = (r % 3) + 1;
	std::cout << "rand is: " << r << std::endl;
	switch (r)
	{
	case (1): {
		return new A;
	}
	case (2): {
		return new B;
	}
	case (3): {
		return new C;
	}
	}
	return NULL;
}

void identify(Base *p)
{
	A *a = dynamic_cast<A *>(p);
	B *b = dynamic_cast<B *>(p);
	C *c = dynamic_cast<C *>(p);
	if (a)
		std::cout << "Type is: A" << std::endl;
	if (b)
		std::cout << "Type is: B" << std::endl;
	if (c)
		std::cout << "Type is: C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "Type is: A" << std::endl;
		(void)a;
		return;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "Type is: B" << std::endl;
		(void)b;
		return;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "Type is: C" << std::endl;
		(void)c;
		return;
	}
	catch (std::exception &e)
	{
	}
}

int main(void)
{
	Base *ptr_test = generate();
	Base &ref_test = *ptr_test;
	std::cout << "Pointer test" << std::endl;
	identify(ptr_test);
	std::cout << "Reference downcast test" << std::endl;
	identify(ref_test);
	return EXIT_SUCCESS;
}