/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:12:29 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/26 18:23:11 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <exception>
#include <ctime>
//t prints the actual type of the object pointed to by p: "A", "B" or "C"

void 	identify(Base* p) {

	if (dynamic_cast<A *>(p))
		std::cout << "Actual type: A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Actual type: B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Actual type: C" << std::endl;
	else
		std::cout << "Actual type not part of Base class" << std::endl;
	
	return ;
}

//It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
//inside this function is forbidden

void 	identify(Base& p) {

	try {
			A &	a = dynamic_cast<A &>(p);
			std::cout << "Actual type: A" << std::endl;
			(void)a;
			return ;
		}
	catch ( std::exception &e ) {
		}
	try 
		{
			B &	b = dynamic_cast<B &>(p);
			std::cout << "Actual type: B" << std::endl;
			(void)b;
			return ;
		}
	catch ( std::exception &e ) {
		}
	try 
		{
			C &	c = dynamic_cast<C &>(p);
			std::cout << "Actual type: C" << std::endl;
			(void)c;
			return ;
			
		}
	catch ( std::exception &e ) {
			std::cout << "Actual type not part of Base class" << std::endl;
		}

	return ;

}

//It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
//to use anything you like for the random choice implementation

Base *	generate(void) {

	std::srand(std::time(NULL)); // use current time as seed for random generator
	int x = rand() % 3 + 1;

	switch (x)
	{
		case 1:
			return new A();
			break;

		case 2:
			return new B();
			break;

		case 3:
			return new C();
	
	default:
			return NULL;
	}


}


int	main( void ) {


	Base* base1 = generate();

	identify(base1);
	identify(NULL);

	Base &	base2 = *base1;
	identify(base2);
	identify(NULL);

	delete base1;

	return 0;
}

