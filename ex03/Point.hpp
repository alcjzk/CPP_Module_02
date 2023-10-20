#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point {
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point &other);
        Point&  operator=(const Point &other);
        ~Point();

    private:
        const Fixed _x;
        const Fixed _y;
};

#endif
