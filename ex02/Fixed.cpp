/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:17:00 by mgayout           #+#    #+#             */
/*   Updated: 2024/08/16 12:17:00 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	this->value = 0;
}

Fixed::Fixed(int const nb)
{
	this->value = (nb << bits);
}

Fixed::Fixed(float const nb)
{
	this->value = int(roundf(nb * (1 << bits)));
}

Fixed::Fixed(const Fixed& fixed)
{
	this->value = fixed.value;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	this->value = rhs.value;
	return *this;
}

bool Fixed::operator>(const Fixed& rhs)
{
	return this->value > rhs.value;
}

bool Fixed::operator<(const Fixed& rhs)
{
	return this->value < rhs.value;
}

bool Fixed::operator>=(const Fixed& rhs)
{
	return this->value >= rhs.value;
}

bool Fixed::operator<=(const Fixed& rhs)
{
	return this->value <= rhs.value;
}

bool Fixed::operator==(const Fixed& rhs)
{
	return this->value == rhs.value;
}

bool Fixed::operator!=(const Fixed& rhs)
{
	return this->value != rhs.value;
}

Fixed Fixed::operator+(const Fixed& rhs)
{
	Fixed	nb;

	nb.setRawBits(this->value + rhs.value);
	return nb;
}

Fixed Fixed::operator-(const Fixed& rhs)
{
	Fixed	nb;

	nb.setRawBits(this->value - rhs.value);
	return nb;
}

Fixed Fixed::operator*(const Fixed& rhs)
{
	Fixed	nb;

	nb.setRawBits(this->value * rhs.value >> bits);
	return nb;
}

Fixed Fixed::operator/(const Fixed& rhs)
{
	Fixed	nb;

	nb.setRawBits(this->value / rhs.value >> bits);
	return nb;
}

Fixed& Fixed::operator++()
{
	this->value++;
	return *this;
}

Fixed& Fixed::operator--()
{
	this->value--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++*this;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--*this;
	return tmp;
}

Fixed::~Fixed(void)
{
	return ;
}

int	Fixed::getRawBits(void) const
{
	return this->value;
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return float(this->value) / (1 << bits);
}

int	Fixed::toInt(void) const
{
	return this->value >> bits;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.value < b.value)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.value > b.value)
		return a;
	return b;
}

std::ostream&	operator<<(std::ostream& o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return o;
}
