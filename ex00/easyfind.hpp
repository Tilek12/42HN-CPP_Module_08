/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:13:31 by tkubanyc          #+#    #+#             */
/*   Updated: 2025/01/09 12:18:59 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator	easyfind( T& container, int value ) {

	auto it = std::find( container.begin(), container.end(), value );

	if ( it == container.end() ) {
		throw std::runtime_error( "Value not found in the container ");
	}

	return it;
}

#endif
