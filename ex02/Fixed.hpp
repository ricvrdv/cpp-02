/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:06:19 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/07/21 11:08:38 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cstdlib>
# include <cmath>

class	Fixed
{
    private:
		
		int					_storedValue;
        static int const	_fractionalBits;
    
	public:
        Fixed( void );
        Fixed( int const n );
        Fixed( float const f );
        Fixed( Fixed const &other );
        Fixed&  operator=( Fixed const &other );
        ~Fixed( void );
        
        int		getRawBits( void ) const;
		void	setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;

        // Comparison operators
        bool    operator>( Fixed const &other ) const;
        bool    operator<( Fixed const &other ) const;
        bool    operator>=( Fixed const &other ) const;
        bool    operator<=( Fixed const &other ) const;
        bool    operator==( Fixed const &other ) const;
        bool    operator!=( Fixed const &other ) const;

        // Arithmetic operators
        Fixed   operator+( Fixed const &other ) const;
        Fixed   operator-( Fixed const &other ) const;
        Fixed   operator*( Fixed const &other ) const;
        Fixed   operator/( Fixed const &other ) const;

        // Increment / Decrement operators
        Fixed&  operator++(); //prefix
        Fixed   operator++( int ); //postfix
        Fixed&  operator--(); // prefix
        Fixed   operator--( int ); //postfix

        static Fixed&       min( Fixed& a, Fixed& b );
        static const Fixed& min( Fixed const &a, Fixed const &b );
        static Fixed&       max( Fixed& a, Fixed& b );
        static const Fixed& max( Fixed const &a, Fixed const &b );
};

std::ostream&	operator<<( std::ostream& out, Fixed const &rhs );

#endif
