#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
    private:
		
		int					_value;
        static int const	_fraction;
    
	public:
        Fixed( void );
        ~Fixed( void );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

};

#endif