/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:17:06 by mgayout           #+#    #+#             */
/*   Updated: 2024/08/16 12:17:06 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
			Fixed();
			Fixed(int const nb);
			Fixed(float const nb);
			Fixed(const Fixed& fixed);
			Fixed& operator=(const Fixed& rhs);
			~Fixed();
			int		getRawBits(void) const;
			void	setRawBits(int const raw);
			float	toFloat(void) const;
			int		toInt(void) const;
	private:
			static int const	bits = 8;
			int					value;

};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);

#endif