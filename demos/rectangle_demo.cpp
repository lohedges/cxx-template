/*
 * File:   rectangle_demo.cpp
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

#include "shapes.h"

int main(int argc, char** argv)
{
    // Here's a default rectangle.
    Rectangle rec1;

    // Here's one defined on initialization.
    Rectangle rec2(10, 4);

    // Print git commit info, if present.
#ifdef COMMIT
    std::cout << "Git commit: " <<  COMMIT << "\n";
#endif

    // Print some details for rec1.
    std::cout << "Rec 1:\t"
              << "area = " << rec1.area()
              << ", perimeter = " << rec1.perimeter() << "\n";

    // And for rec2.
    std::cout << "Rec 2:\t"
              << "area = " << rec2.area()
              << ", perimeter = " << rec2.perimeter() << "\n";

    // Totals
    std::cout << "Totals:\t"
              << "area = " << rec1.area() + rec2.area()
              << ", perimeter = " << rec1.perimeter() + rec2.perimeter() << "\n";

    return (EXIT_SUCCESS);
}
