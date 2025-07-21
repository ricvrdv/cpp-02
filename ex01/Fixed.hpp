/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:55:22 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/07/21 10:57:15 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
    private:
		
		int					_storedValue;
        static int const	_fractionalBits;
    
	public:
        
		Fixed( void );
        Fixed(int const n);
        Fixed( float const f );
        Fixed( Fixed const &other );
        Fixed&  operator=( Fixed const &other );
        ~Fixed( void );
        
        int		getRawBits( void ) const;
		void	setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
};

std::ostream&	operator<<( std::ostream &out, Fixed const &rhs );

#endif
