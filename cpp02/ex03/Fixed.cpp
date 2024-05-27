/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:12:24 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/03 13:36:38 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
}

Fixed::Fixed(int const value) : _fixedPointValue(value << _fractionalBits)
{
}

Fixed::Fixed(float const value) : _fixedPointValue(roundf(value * (1 << _fractionalBits)))
{
}

Fixed::Fixed(const Fixed &copy) : _fixedPointValue(copy._fixedPointValue)
{
}

Fixed& Fixed::operator=(const Fixed &copy)
{
	_fixedPointValue = copy._fixedPointValue;
	return *this;
}

Fixed::~Fixed()
{
}

int		Fixed::getRawBits(void) const
{
	return _fixedPointValue;
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

int		Fixed::toInt(void) const
{
	return _fixedPointValue >> _fractionalBits;
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return _fixedPointValue > rhs._fixedPointValue;
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return _fixedPointValue < rhs._fixedPointValue;
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return _fixedPointValue >= rhs._fixedPointValue;
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return _fixedPointValue <= rhs._fixedPointValue;
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return _fixedPointValue == rhs._fixedPointValue;
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return _fixedPointValue != rhs._fixedPointValue;
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	Fixed result;

	result._fixedPointValue = _fixedPointValue + rhs._fixedPointValue;
	return result;
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	Fixed result;

	result._fixedPointValue = _fixedPointValue - rhs._fixedPointValue;
	return result;
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	Fixed result;

	result._fixedPointValue = (_fixedPointValue * rhs._fixedPointValue) >> _fractionalBits;
	return result;
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	Fixed result;

	result._fixedPointValue = (_fixedPointValue << _fractionalBits) / rhs._fixedPointValue;
	return result;
}

Fixed&	Fixed::operator++(void)
{
	_fixedPointValue++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);

	_fixedPointValue++;
	return temp;
}

Fixed&	Fixed::operator--(void)
{
	_fixedPointValue--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);

	_fixedPointValue--;
	return temp;
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	return (a._fixedPointValue < b._fixedPointValue) ? a : b;
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	return (a._fixedPointValue > b._fixedPointValue) ? a : b;
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a._fixedPointValue < b._fixedPointValue) ? a : b;
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a._fixedPointValue > b._fixedPointValue) ? a : b;
}

std::ostream &operator<<(std::ostream &ostream, const Fixed &fixed)
{
	ostream << fixed.toFloat();
	return ostream;
}
