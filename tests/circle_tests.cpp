/*
 * File:   circle_tests.cpp
 * Author: lester
 */

#include "shapes.h"

int testArea()
{
    double area = M_PI*2*2;

    Circle circ(2);
    check(std::abs(circ.area() - area) < 1e-9, "Circle area is incorrect!");

    return 0;

error:
    return 1;
}

int testCircumference()
{
    double circumference = 2*M_PI*2;

    Circle circ(2);
    check(std::abs(circ.circumference() - circumference) < 1e-9, "Circle circumference is incorrect!");

    return 0;

error:
    return 1;
}

int all_tests()
{
    mu_suite_start();

    mu_run_test(testArea);
    mu_run_test(testCircumference);

    return 0;
}

RUN_TESTS(all_tests);
