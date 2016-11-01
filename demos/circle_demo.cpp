/*
 * File:   circle_demo.cpp
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
    // Here's a default circle.
    Circle circ1;

    // Here's one defined on initialization.
    Circle circ2(10);

    // Print git commit info, if present.
#ifdef COMMIT
    std::cout << "Git commit: " << COMMIT << "\n";
#endif

    // Print git branch info, if present.
#ifdef BRANCH
    std::cout << "Git branch: " << BRANCH << "\n";
#endif

    // Print some details for circ1.
    std::cout << "circ 1:\t"
              << "area = " << circ1.area()
              << ", circumference = " << circ1.circumference() << "\n";

    // And for circ2.
    std::cout << "circ 2:\t"
              << "area = " << circ2.area()
              << ", circumference = " << circ2.circumference() << "\n";

    // Totals.
    std::cout << "Totals:\t"
              << "area = " << circ1.area() + circ2.area()
              << ", circumference = " << circ1.circumference() + circ2.circumference() << "\n";

    return (EXIT_SUCCESS);
}
