/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:55:13 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/07/21 11:01:22 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const   Fixed::_fractionalBits = 8;

// Default constructor
Fixed::Fixed( void ) : _storedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed( Fixed const &other )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed&	Fixed::operator=( Fixed const &other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_storedValue = other.getRawBits();
	return (*this);
}

// Destructor
Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

// Parametric constructors
Fixed::Fixed( int const n )
{
	std::cout << "Int constructor called" << std::endl;
	this->_storedValue = n << _fractionalBits;
}

Fixed::Fixed( float const f )
{
	std::cout << "Float constructor called" << std::endl;
	this->_storedValue = roundf(f * (1 << _fractionalBits));
}

// Member functions
int Fixed::getRawBits( void ) const
{
	return (this->_storedValue);
}

void	Fixed::setRawBits( int const raw )
{
	this->_storedValue = raw;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_storedValue) / (1 << this->_fractionalBits));
}

int		Fixed::toInt( void ) const
{
	return (this->_storedValue >> this->_fractionalBits);
}

// Operator << overload
std::ostream&	operator<<( std::ostream &out, Fixed const &rhs )
{
	out << rhs.toFloat();
	return (out);
}
