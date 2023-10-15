#include <iostream>
#include "Fixed.hpp"

const int Fixed::_fraction_bits = 8;

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) : _value(fixed._value)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int from) : _value(from << _fraction_bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float from) :
    _value(from * float(1 << _fraction_bits) + (from >= 0.0f ? 0.5f : -0.5f))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &fixed)
        return *this;
    _value = fixed.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed &fixed)
{
    return os << fixed.toFloat();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

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
