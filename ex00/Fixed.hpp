#ifndef FIXED_H
# define FIXED_H

class Fixed {
    public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed& operator=(const Fixed &fixed);
        ~Fixed();
        
        int     getRawBits() const;
        void    setRawBits(int raw);
    private:
        int                 value;
        static const int    fraction_bits;
};

#endif
