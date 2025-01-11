/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:07:28 by tkubanyc          #+#    #+#             */
/*   Updated: 2025/01/11 21:09:00 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*-----------------*/
/*  Main function  */
/*-----------------*/
int	main( void ) {

	try {
		// Creating a Span with a max size of 5
		Span sp = Span( 5 );

		// Adding numbers one by one
		sp.addNumber( 6 );
		sp.addNumber( 3 );
		sp.addNumber( 17 );
		sp.addNumber( 9 );
		sp.addNumber( 11 );

		// Printing shortest and longest span
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		// Generate a Span with 10,000 unique random numbers in the range 1 to 20,000
		Span randomSpan = Span::generateRandomSpan( 10000, 1, 20000 );

		// Printing shortest and longest spans
		std::cout << "Shortest Span in randomSpan: " << randomSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span in randomSpan: " << randomSpan.longestSpan() << std::endl;
	} catch ( const std::exception& e ) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
