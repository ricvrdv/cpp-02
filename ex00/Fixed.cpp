/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:45:16 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/07/21 10:53:32 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const   Fixed::_fractionalBits = 8;

Fixed::Fixed( void ) : _storedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &other )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=( Fixed const &rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_storedValue = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_storedValue);
}

void	Fixed::setRawBits( int const raw )
{
	this->_storedValue = raw;
}
