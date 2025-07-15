#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
    private:
		
		int					_value;
        static int const	_fraction;
    
	public:
        Fixed( void );
        Fixed(int const n);
        Fixed( float const f );
        Fixed(Fixed const & src );
        Fixed&  operator=( Fixed const & rhs );
        ~Fixed( void );
        
        int		getRawBits( void ) const;
		void	setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
};

std::ostream&	operator<<( std::ostream& out, Fixed const & rhs );

#endif