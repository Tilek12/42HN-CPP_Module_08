/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:13:31 by tkubanyc          #+#    #+#             */
/*   Updated: 2025/01/09 14:38:12 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <list>

/*-------------*/
/*  Functions  */
/*-------------*/
template <typename T>
typename T::iterator	easyfind( T& container, int value );

#include "easyfind.tpp"

#endif
