/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:03:14 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/01 10:47:06 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fixedPointValue = copy.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)this->_fixedPointValue / (1 << this->_fractionalBits);
}

int		Fixed::toInt(void) const
{
	return this->_fixedPointValue >> this->_fractionalBits;
}

std::ostream &operator<<(std::ostream &ostream, const Fixed &fixed)
{
	ostream << fixed.toFloat();
	return ostream;
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return this->_fixedPointValue > rhs.getRawBits();
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return this->_fixedPointValue < rhs.getRawBits();
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return this->_fixedPointValue >= rhs.getRawBits();
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return this->_fixedPointValue <= rhs.getRawBits();
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return this->_fixedPointValue == rhs.getRawBits();
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return this->_fixedPointValue != rhs.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

Fixed&	Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed&	Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}
