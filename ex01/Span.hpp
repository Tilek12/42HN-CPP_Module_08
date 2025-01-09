/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:50:23 by tkubanyc          #+#    #+#             */
/*   Updated: 2025/01/09 15:06:53 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>

class	Span {

private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;

public:
	Span( unsigned int N );
	Span( const Span& other );
	Span	operator=( const Span& other );
	~Span( void );

	void			addNumber( int number );
	template <typename InputIterator>
	void			addNumbersFromRange( InputIterator first, InputIterator last);
	int				shortestSpan( void ) const;
	int				longestSpan( void ) const;
	unsigned int	getSize( void ) const;
};

#endif
