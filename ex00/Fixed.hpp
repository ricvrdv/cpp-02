/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:45:26 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/07/21 10:51:42 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
    private:
		
		int					_storedValue;
        static int const	_fractionalBits;
    
	public:
        
		Fixed( void );
        Fixed( Fixed const &other );
        Fixed&  operator=( Fixed const &rhs );
        ~Fixed( void );
        

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

};

#endif
