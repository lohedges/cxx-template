/*
 * File:   Circle.cpp
 * Author: lester
 */

/*
    Copyright (c) 2014, 2015 Lester Hedges <lester.hedges@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>

#include "Circle.h"

Circle::Circle() : radius(5)
{
}

Circle::Circle(double radius_) : radius(radius_)
{
}

void Circle::setRadius(double radius_)
{
    radius = radius_;
}

double Circle::getRadius()
{
    return radius;
}

double Circle::area()
{
    return M_PI*radius*radius;
}

double Circle::circumference()
{
    return 2*M_PI*radius;
}
