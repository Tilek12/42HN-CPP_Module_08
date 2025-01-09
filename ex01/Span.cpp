/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:08:41 by tkubanyc          #+#    #+#             */
/*   Updated: 2025/01/09 16:04:42 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int N ) : _maxSize( N ) {}

Span::Span( const Span& other ) : _maxSize( other._maxSize ),
								  _numbers( other._numbers ) {}

Span	Span::operator=( const Span& other ) {

	if ( this != &other ) {
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}

	return *this;
}

Span::~Span( void ) {}

void	Span::addNumber( int number ) {

	if ( _numbers.size() >= _maxSize ) {
		throw std::overflow_error( "Span is already full" );
	}

	_numbers.push_back( number );
}

template <typename InputIterator>
void	Span::addNumbersFromRange( InputIterator first, InputIterator last ) {

	unsigned int numToAdd = std::distance( first, last );

	if ( _numbers.size() + numToAdd > _maxSize ) {
		throw std::overflow_error( "Adding this number exceeds the maximum size");
	}
	_numbers.insert( _numbers.end(), first, last );
}

int	Span::shortestSpan( void ) const {

	if ( _numbers.size() < 2 ) {
		throw std::logic_error( "Not enough numbers to find a span");
	}

	std::vector<int> sortedNumbers = _numbers;
	std::sort( sortedNumbers.begin(), sortedNumbers.end() );

	int	shortest = sortedNumbers[1] - sortedNumbers[0];

	for ( size_t i = 1; i < sortedNumbers.size() - 1; i++ ) {
		int span = sortedNumbers[i + 1] - sortedNumbers[i];
		if ( span < shortest ) {
			shortest = span;
		}
	}

	return shortest;
}

int	Span::longestSpan( void ) const {

	if ( _numbers.size() < 2 ) {
		throw std::logic_error( "Not enough numbers to find a span");
	}

	int	minElem = *std::min_element( _numbers.begin(), _numbers.end() );
	int	maxElem = *std::max_element( _numbers.begin(), _numbers.end() );

	return maxElem - minElem;
}

unsigned int	Span::getSize( void ) const { return _numbers.size(); }

template void	Span::addNumbersFromRange<std::vector<int>::iterator>(std::vector<int>::iterator, std::vector<int>::iterator);
