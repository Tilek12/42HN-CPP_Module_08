/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:27:21 by tkubanyc          #+#    #+#             */
/*   Updated: 2025/01/09 12:29:27 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind( T& container, int value ) {

	auto it = std::find( container.begin(), container.end(), value );

	if ( it == container.end() ) {
		throw std::runtime_error( "Value not found in the container ");
	}

	return it;
}
