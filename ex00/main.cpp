/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:15:45 by tkubanyc          #+#    #+#             */
/*   Updated: 2025/01/09 14:39:07 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/*-----------------*/
/*  Main finction  */
/*-----------------*/
int	main( void ) {

	try {
		// Test with std::vector
		std::vector<int> vec = { 1, 2, 3, 4, 5 };
		std::cout << "Searching in vector..." << std::endl;
		auto itVec = easyfind( vec, 3 );
		std::cout << "Found value: " << *itVec << " at position: "
				  << std::distance(vec.begin(), itVec ) << std::endl;

		// Test with std::list
		std::list<int> lst = { 10, 20, 30, 40, 50 };
		std::cout << "Searching in list..." << std::endl;
		auto itList = easyfind( lst, 20 );
		std::cout << "Found value: " << *itList << std::endl;

		// Test for a value not in the container
		std::cout << "Searching for missing value..." << std::endl;
		easyfind( vec, 100 ); // This will throw an exception
	}
	catch ( const std::runtime_error& e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
