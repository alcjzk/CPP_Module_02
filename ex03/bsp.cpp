#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point p)
{
    Fixed   w1, w2;

    w1 = (a.x() *
        (c.y() - a.y()) + (p.y() - a.y()) *
        (c.x() - a.x()) - p.x() *
        (c.y() - a.y())) /
        ((b.y() - a.y()) *
        (c.x() - a.x()) -
        (b.x() - a.x()) *
        (c.y() - a.y()));
    w2 = (p.y() - a.y() - w1 * (b.y() - a.y())) / (c.y() - a.y());
    if (w1 > Fixed(0) && w1 < Fixed(1) &&
        w2 > Fixed(0) && w2 < Fixed(1) &&
        w1 + w2 < Fixed(1) && w1 + w2 > Fixed(0))
    {
        return true;
    }
    return false;
}
