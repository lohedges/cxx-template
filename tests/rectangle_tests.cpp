/*
 * File:   rectangle_tests.cpp
 * Author: lester
 */

#include "shapes.h"

int testArea()
{
    Rectangle rec(2, 4);
    check(rec.area() == 8, "Rectangle area is incorrect!");

    return 0;

error:
    return 1;
}

int testPerimeter()
{
    Rectangle rec(2, 4);
    check(rec.perimeter() == 12, "Rectangle perimeter is incorrect!");

    return 0;

error:
    return 1;
}

int all_tests()
{
    mu_suite_start();

    mu_run_test(testArea);
    mu_run_test(testPerimeter);

    return 0;
}

RUN_TESTS(all_tests);
