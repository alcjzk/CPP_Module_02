#ifndef FIXED_H
# define FIXED_H

# include <ostream>

class Fixed {
    public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed(const int from);
        Fixed(const float from);
        Fixed& operator=(const Fixed &fixed);
        ~Fixed();
        
        bool    operator==(const Fixed &other) const;
        bool    operator!=(const Fixed &other) const;
        bool    operator<(const Fixed &other) const;
        bool    operator>(const Fixed &other) const;
        bool    operator>=(const Fixed &other) const;
        bool    operator<=(const Fixed &other) const;

        Fixed   operator+(const Fixed &other) const;
        Fixed   operator-(const Fixed &other) const;
        Fixed   operator/(const Fixed &other) const;
        Fixed   operator*(const Fixed &other) const;

        Fixed&  operator++();
        Fixed&  operator--();
        Fixed   operator++(int);
        Fixed   operator--(int);

        int     getRawBits() const;
        void    setRawBits(const int raw);
        float   toFloat() const;
        int     toInt() const;

        static const Fixed &min(const Fixed &lhs, const Fixed& rhs);
        static const Fixed &max(const Fixed &lhs, const Fixed& rhs);
        static Fixed &min(Fixed &lhs, Fixed& rhs);
        static Fixed &max(Fixed &lhs, Fixed& rhs);

    private:
        int                 _value;
        static const int    _fraction_bits;
};

std::ostream&   operator<<(std::ostream& os, const Fixed &fixed);

#endif
