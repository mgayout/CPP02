/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:28:07 by mgayout           #+#    #+#             */
/*   Updated: 2024/08/16 11:28:07 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
			Fixed();
			Fixed(const Fixed& other);
			Fixed& operator=(const Fixed& rhs);
			~Fixed();
			int		getRawBits(void) const;
			void	setRawBits(int const raw);

	private:
			int					value;
			static int const	bits = 8;

};

#endif