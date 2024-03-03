/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:52:46 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/01 10:53:07 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
}

Point::Point(Point const & src) : _x(src._x), _y(src._y)
{
}

Point::~Point()
{
}

Point & Point::operator=(Point const & src)
{
	_x = src._x;
	_y = src._y;
	return *this;
}

float Point::getX() const
{
	return _x;
}

float Point::getY() const
{
	return _y;
}
