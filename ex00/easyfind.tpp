/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:27:21 by tkubanyc          #+#    #+#             */
/*   Updated: 2025/01/09 14:37:26 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*----------------------------*/
/*  Define easyfind function  */
/*----------------------------*/
template <typename T>
typename T::iterator	easyfind( T& container, int value ) {

	auto it = std::find( container.begin(), container.end(), value );

	if ( it == container.end() ) {
		throw std::runtime_error( "Value not found in the container ");
	}

	return it;
}
