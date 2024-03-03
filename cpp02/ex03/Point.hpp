/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:52:30 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/01 11:16:38 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

class Point
{
	private:
		float _x;
		float _y;
	public:
		Point();
		Point(float const x, float const y);
		Point(Point const & src);
		~Point();
		Point & operator=(Point const & src);
		float getX() const;
		float getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif