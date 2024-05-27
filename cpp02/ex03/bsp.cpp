/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:14:02 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/03 13:06:08 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

static Fixed abs(Fixed const & n)
{
	return (n < 0 ? (n * -1) : n);
}

static Fixed calculate_area(Point const pointA, Point const pointB, Point const pointC) {
	Fixed x1 = pointA.getX();
	Fixed y1 = pointA.getY();
	Fixed x2 = pointB.getX();
	Fixed y2 = pointB.getY();
	Fixed x3 = pointC.getX();
	Fixed y3 = pointC.getY();

	return (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed ABC = abs(calculate_area(a, b, c));
	Fixed PAB = abs(calculate_area(point, a, b));
	Fixed PBC = abs(calculate_area(point, b, c));
	Fixed PCA = abs(calculate_area(point, c, a));

	return (ABC == PAB + PBC + PCA);
}
