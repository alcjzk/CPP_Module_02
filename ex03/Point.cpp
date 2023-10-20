#include "Point.hpp"

Point::Point() : _x(Fixed()), _y(Fixed()) {}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point& Point::operator=(const Point &other)
{
    if (this == &other)
        return *this;
    *this = other;
    return *this;
}

Point::~Point() {}

const Fixed &Point::x() const
{
    return _x;
}

const Fixed &Point::y() const
{
    return _y;
}
