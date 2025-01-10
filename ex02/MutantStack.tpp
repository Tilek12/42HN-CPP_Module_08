/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:46:04 by tkubanyc          #+#    #+#             */
/*   Updated: 2025/01/10 17:19:56 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

/*---------------------------*/
/*  Define begin() function  */
/*---------------------------*/
template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin( void ) {
	return this->c.begin();
}

/*-------------------------*/
/*  Define end() function  */
/*-------------------------*/
template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end( void ) {
	return this->c.end();
}

/*---------------------------------*/
/*  Define const_begin() function  */
/*---------------------------------*/
template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::const_begin( void ) const {
	return this->c.cbegin();
}

/*-------------------------------*/
/*  Define const_end() function  */
/*-------------------------------*/
template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::const_end( void ) const {
	return this->c.cend();
}

/*----------------------------*/
/*  Define rbegin() function  */
/*----------------------------*/
template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin( void ) {
	return this->c.rbegin();
}

/*--------------------------*/
/*  Define rend() function  */
/*--------------------------*/
template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend( void ) {
	return this->c.rend();
}

/*----------------------------------*/
/*  Define const_rbegin() function  */
/*----------------------------------*/
template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::const_rbegin( void ) const {
	return this->c.crbegin();
}

/*--------------------------------*/
/*  Define const_rend() function  */
/*--------------------------------*/
template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::const_rend( void ) const {
	return this->c.crend();
}

#endif
