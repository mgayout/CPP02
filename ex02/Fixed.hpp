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
			Fixed(Fixed const &fixed);
			Fixed& operator=(Fixed const &rhs);
			bool operator>(Fixed const &rhs);
			bool operator<(Fixed const &rhs);
			bool operator>=(Fixed const &rhs);
			bool operator<=(Fixed const &rhs);
			bool operator==(Fixed const &rhs);
			bool operator!=(Fixed const &rhs);
			Fixed operator+(Fixed const &rhs);
			Fixed operator-(Fixed const &rhs);
			Fixed operator*(Fixed const &rhs);
			Fixed operator/(Fixed const &rhs);
			Fixed& operator++();
			Fixed& operator--();
			Fixed operator++(int);
			Fixed operator--(int);
			~Fixed();
			int					getRawBits(void) const;
			void				setRawBits(int const raw);
			float				toFloat(void) const;
			int					toInt(void) const;
			static Fixed&		min(Fixed& a, Fixed&b);
			static const Fixed&	min(const Fixed& a, const Fixed& b);
			static Fixed&		max(Fixed& a, Fixed& b);
			static const Fixed&	max(const Fixed& a, const Fixed& b);

	private:
			static int const	bits = 8;
			int					value;

};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);

#endif