#include <iostream>
#include <cstdlib>
#include <cassert>
#include "Fixed.hpp"
#include "Point.hpp"


bool bsp(const Point a, const Point b, const Point c, const Point point);

int main()
{
    Point a(1.2f, 1.2f), b(1.3f, 4.5f), c(5.5f, 0.6f);

    // Point is on vertex
    assert(!bsp(a, b, c, a));
    assert(!bsp(a, b, c, b));
    assert(!bsp(a, b, c, c));

    // Point inside triangle
    assert(bsp(a, b, c, Point(1.4f, 3.3f)));

    // Point outside triangle
    assert(!bsp(a, b, c, Point(1.0f, 3.3f))); // To the left
    assert(!bsp(a, b, c, Point(6.0f, 3.3f))); // To the right
    assert(!bsp(a, b, c, Point(2.0f, 9.0f))); // Above
    assert(!bsp(a, b, c, Point(2.0f, -9.0f))); // Below

    return EXIT_SUCCESS;
}
