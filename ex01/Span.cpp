/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:08:41 by tkubanyc          #+#    #+#             */
/*   Updated: 2025/01/11 21:00:38 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*--------------------------*/
/*  Span Class constructor  */
/*--------------------------*/
Span::Span( int N ) {

	if ( N <= 0 ) {
		throw std::invalid_argument( "Span size must be a positive number" );
	}

	_maxSize = static_cast<unsigned int>(N);
}

/*-------------------------------*/
/*  Span Class copy constructor  */
/*-------------------------------*/
Span::Span( const Span& other ) : _maxSize( other._maxSize ),
								  _numbers( other._numbers ) {}

/*---------------------------------------*/
/*  Span Class copy assignment operator  */
/*---------------------------------------*/
Span&	Span::operator=( const Span& other ) {

	if ( this != &other ) {
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}

	return *this;
}

/*-------------------------*/
/*  Span Class destructor  */
/*-------------------------*/
Span::~Span( void ) {}

/*-----------------------------*/
/*  Define addNumber function  */
/*-----------------------------*/
void	Span::addNumber( int number ) {

	if ( _numbers.size() >= _maxSize ) {
		throw std::overflow_error( "Span is already full" );
	}

	_numbers.push_back( number );
}

/*--------------------------------*/
/*  Define shortestSpan function  */
/*--------------------------------*/
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

/*-------------------------------*/
/*  Define longestSpan function  */
/*-------------------------------*/
int	Span::longestSpan( void ) const {

	if ( _numbers.size() < 2 ) {
		throw std::logic_error( "Not enough numbers to find a span");
	}

	int	minElem = *std::min_element( _numbers.begin(), _numbers.end() );
	int	maxElem = *std::max_element( _numbers.begin(), _numbers.end() );

	return maxElem - minElem;
}

/*---------------------------*/
/*  Define getSize function  */
/*---------------------------*/
unsigned int	Span::getSize( void ) const { return _numbers.size(); }

/*---------------------------------------*/
/*  Define addNumbersFromRange function  */
/*---------------------------------------*/
template <typename InputIterator>
void	Span::addNumbersFromRange( InputIterator first, InputIterator last ) {

	unsigned int numToAdd = std::distance( first, last );

	if ( _numbers.size() + numToAdd > _maxSize ) {
		throw std::overflow_error( "Adding this number exceeds the maximum size");
	}
	_numbers.insert( _numbers.end(), first, last );
}

/*-----------------------------------*/
/*  Explicit template instantiation  */
/*-----------------------------------*/
template void	Span::addNumbersFromRange<std::vector<int>::iterator>\
					(std::vector<int>::iterator, std::vector<int>::iterator);

/*-----------------------------------------------------------------*/
/*  Function to generate a Span filled with unique random numbers  */
/*-----------------------------------------------------------------*/
Span	Span::generateRandomSpan( unsigned int spanSize, int minValue, int maxValue ) {

	if ( maxValue - minValue + 1 < static_cast<int>(spanSize) ) {
		throw std::invalid_argument( "Range too small to generate the required number of unique numbers" );
	}

	// Using <random> to generate random numbers
	std::random_device rd; // Seed for the random generator
	std::mt19937 gen( rd() ); // Mersenne Twister random generator
	std::uniform_int_distribution<> dist( minValue, maxValue ); // Range of random numbers

	std::unordered_set<int> uniqueNumbers;
	while ( uniqueNumbers.size() < spanSize ) {
		int randomNumber = dist( gen );
		uniqueNumbers.insert( randomNumber ); // Only unique numbers are added to the set
	}

	Span sp( spanSize );
	sp.addNumbersFromRange( uniqueNumbers.begin(), uniqueNumbers.end() );

	return sp;
}
