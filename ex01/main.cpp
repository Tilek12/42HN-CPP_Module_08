/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:07:28 by tkubanyc          #+#    #+#             */
/*   Updated: 2025/01/09 16:09:25 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main( void ) {

	try {
		Span sp1 = Span(5);
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);

		// Test Copy Constructor
		Span sp2 = sp1; // Copy constructor
		std::cout << "Shortest Span (copied): " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest Span (copied): " << sp2.longestSpan() << std::endl;

		// Test Copy Assignment Operator
		Span sp3 = Span(5);
		sp3.addNumber(7);
		sp3.addNumber(8);
		sp3 = sp1; // Copy assignment
		std::cout << "Shortest Span (assigned): " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest Span (assigned): " << sp3.longestSpan() << std::endl;
	} catch ( const std::exception& e ) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
