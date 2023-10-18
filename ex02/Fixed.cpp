#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::_fraction_bits = 8;

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed &fixed) : _value(fixed._value) {}

Fixed::Fixed(const int from) : _value(from << _fraction_bits) {}

Fixed::Fixed(const float from) :
    _value(roundf(from * float(1 << _fraction_bits)))
{}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    if (this == &fixed)
        return *this;
    _value = fixed.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed &fixed)
{
    return os << fixed.toFloat();
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const
{
    return _value;
}

void Fixed::setRawBits(const int raw)
{
    _value = raw;
}

float Fixed::toFloat() const
{
    return float(_value) / float(1 << _fraction_bits);
}

int Fixed::toInt() const
{
    return _value >> _fraction_bits;
}

bool Fixed::operator==(const Fixed &other) const
{
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return !(*this == other);
}

bool Fixed::operator<(const Fixed &other) const
{
    return _value < other._value;
}

bool Fixed::operator>(const Fixed &other) const
{
    return !(*this == other || *this < other);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return !(*this < other);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return *this < other || *this == other;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed   output(*this);

    output._value += other._value;
    return output;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed   output(*this);

    output._value -= other._value;
    return output;
}

// Subject mandates the underlying type to be an int instead of an exact width
// type, casts below may function as a workaround for overflows on some
// platforms.

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed   output(*this);

    output._value = long(output._value) * long(other._value) >> _fraction_bits;
    return output;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed   output(*this);

    output._value = (long(output._value) << _fraction_bits) / long(other._value);
    return output;
}

// Incorrect behavior of the increment/decrement operators is mandated by the
// subject.

Fixed& Fixed::operator++()
{
    return ++_value, *this;
}

Fixed& Fixed::operator--()
{
    return --_value, *this;
}

Fixed Fixed::operator++(int)
{
    Fixed   output(*this);

    return ++_value, output;
}

Fixed Fixed::operator--(int)
{
    Fixed   output(*this);

    return --_value, output;
}

const Fixed &Fixed::min(const Fixed &lhs, const Fixed& rhs)
{
    return lhs < rhs ? lhs : rhs;
}

const Fixed &Fixed::max(const Fixed &lhs, const Fixed& rhs)
{
    return lhs > rhs ? lhs : rhs;
}

Fixed &Fixed::min(Fixed &lhs, Fixed& rhs)
{
    return const_cast<Fixed &>(Fixed::min(
        const_cast<const Fixed &>(lhs),
        const_cast<const Fixed &>(rhs))
    );
}

Fixed &Fixed::max(Fixed &lhs, Fixed& rhs)
{
    return const_cast<Fixed &>(Fixed::max(
        const_cast<const Fixed &>(lhs),
        const_cast<const Fixed &>(rhs))
    );
}
