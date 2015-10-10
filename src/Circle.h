/*
 * File:   Circle.h
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

#ifndef _CIRCLE_H
#define _CIRCLE_H

#include <cmath>

#ifndef M_PI
    #define M_PI 3.1415926535897932384626433832795
#endif

/*! \file Circle.h
*/

//! A class for cirular shapes.
class Circle
{
public:
    //! Default constructor.
    Circle();

    //! Constructor.
    /*! \param radius_
            The radius of the circle.
    */
    Circle(double);

    //! Set the radius of the circle.
    //! \param radius_ The circle's new radius.
    void setRadius(double);

    //! Get the radius of the circle.
    //! \return radius The circle's radius.
    double getRadius();

    //! Compute and return the circle's area.
    //! \return area The area of the circle.
    double area();

    //! Compute and return the circle's circumference.
    //! \return circumference The circumference of the circle.
    double circumference();

private:
    double radius;  //!< The radius of the circle.
};

#endif  /* _CIRCLE_H */
