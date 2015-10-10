/*
 * File:   Rectangle.h
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

#ifndef _RECTANGLE_H
#define _RECTANGLE_H

/*! \file Rectangle.h
*/

//! A class for rectangular shapes.
class Rectangle
{
public:
    //! Default constructor.
    Rectangle();

    //! Constructor.
    /*! \param width_
            The width of the rectangle.

        \param height_
            The height of the rectangle.
    */
    Rectangle(double, double);

    //! Set the width of the rectangle.
    //! \param width_ The rectangle's new width.
    void setWidth(double);

    //! Set the height of the rectangle.
    //! \param height_ The rectangle's new height.
    void setHeight(double);

    //! Get the width of the rectangle.
    //! \return width The rectangle's width.
    double getWidth();

    //! Get the height of the rectangle.
    //! \return height The rectangle's height.
    double getHeight();

    //! Compute and return the rectangle's area.
    //! \return area The area of the rectangle.
    double area();

    //! Compute and return the rectangle's perimeter.
    //! \return perimeter The perimeter of the rectangle.
    double perimeter();

private:
    double width;   //!< The width of the rectangle.
    double height;  //!< The height of the rectangle.
};

#endif  /* _RECTANGLE_H */
