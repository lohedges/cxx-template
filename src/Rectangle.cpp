/*
 * File:   Rectangle.cpp
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

#include "Rectangle.h"

Rectangle::Rectangle() : width(5), height(2)
{
}

Rectangle::Rectangle(double width_, double height_) :
    width(width_),
    height(height_)
{
}

void Rectangle::setWidth(double width_)
{
    width = width_;
}

void Rectangle::setHeight(double height_)
{
    height = height_;
}

double Rectangle::getWidth()
{
    return width;
}

double Rectangle::getHeight()
{
    return height;
}

double Rectangle::area()
{
    return width*height;
}

double Rectangle::perimeter()
{
    return (2*width + 2*height);
}
