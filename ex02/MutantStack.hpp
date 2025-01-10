/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:19:02 by tkubanyc          #+#    #+#             */
/*   Updated: 2025/01/10 17:16:37 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

/*----------------------------*/
/*  Define MutantStack class  */
/*----------------------------*/
template <typename T>
class	MutantStack : public std::stack<T> {

public:

	MutantStack( void ) = default;
	MutantStack( const MutantStack& other ) = default;
	MutantStack&	operator=( const MutantStack& other ) = default;
	~MutantStack( void ) = default;

	using	std::stack<T>::stack;
	using	iterator = typename std::deque<T>::iterator;
	using	const_iterator = typename std::deque<T>::const_iterator;
	using	reverse_iterator = typename std::deque<T>::reverse_iterator;
	using	const_reverse_iterator = typename std::deque<T>::const_reverse_iterator;

	iterator				begin( void );
	iterator				end( void );
	const_iterator			const_begin( void ) const;
	const_iterator			const_end( void ) const;
	reverse_iterator		rbegin( void );
	reverse_iterator		rend( void );
	const_reverse_iterator	const_rbegin( void ) const;
	const_reverse_iterator	const_rend( void ) const;

};

#include "MutantStack.tpp"

#endif
