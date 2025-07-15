#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
    private:
		
		int					_value;
        static int const	_fraction;
    
	public:
        Fixed( void );
        Fixed(Fixed const & src );
        Fixed&  operator=( Fixed const & rhs );
        ~Fixed( void );
        

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

};

#endif