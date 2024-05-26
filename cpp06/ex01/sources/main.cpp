/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:12:29 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/26 17:00:13 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

int	main( void ) {

	Data	data;

	data.x = 42;

	std::cout << "Original data pointer: " << &data << std::endl;
	std::cout << "Original data value: " << data.x << std::endl;

	uintptr_t	serialPtr = Serializer::serialize(&data);

	//std::cout << "uintptr_t: " << &serialPtr << std::endl;
	

	Data*	deserialPtr = Serializer::deserialize(serialPtr);

	std::cout << "New data pointer: " << deserialPtr << std::endl;
	std::cout << "New data value: " << deserialPtr->x << std::endl;

	return 0;
}

