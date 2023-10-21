#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point p)
{
    Fixed expr1(c.y() - a.y());
    Fixed expr2(p.y() - a.y());
    Fixed expr3(c.x() - a.x());
    Fixed expr4(b.y() - a.y());
    Fixed w1 = (a.x() * expr1 + expr2 * expr3 - p.x() * expr1)
        / (expr4 * expr3 - (b.x() - a.x()) * expr1);
    Fixed w2 = (expr2 - w1 * expr4) / expr1;

    return (w1 > Fixed(0) && w1 < Fixed(1) &&
        w2 > Fixed(0) && w2 < Fixed(1) &&
        w1 + w2 < Fixed(1));
}
