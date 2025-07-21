/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:06:11 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/07/21 11:19:52 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const   Fixed::_fractionalBits = 8;

// Default constructor
Fixed::Fixed( void ) : _storedValue(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed( Fixed const &other )
{
	*this = other;
}

// Copy assignment operator
Fixed&	Fixed::operator=( Fixed const &other )
{
	if (this != &other)
		this->_storedValue = other.getRawBits();
	return (*this);
}

// Destructor
Fixed::~Fixed( void )
{
	//std::cout << "Destructor called" << std::endl;
}

// Parametric constructors
Fixed::Fixed( int const n )
{
	//std::cout << "Int constructor called" << std::endl;
	this->_storedValue = n << _fractionalBits;
}

Fixed::Fixed( float const f )
{
	//std::cout << "Float constructor called" << std::endl;
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

// Comparison operators
bool    Fixed::operator>( Fixed const &other ) const
{
	return (this->_storedValue > other._storedValue);
}

bool    Fixed::operator<( Fixed const &other ) const
{
	return (this->_storedValue < other._storedValue);
}

bool    Fixed::operator>=( Fixed const &other ) const
{
	return (this->_storedValue >= other._storedValue);
}

bool    Fixed::operator<=( Fixed const &other ) const
{
	return (this->_storedValue <= other._storedValue);
}

bool    Fixed::operator==( Fixed const &other ) const
{
	return (this->_storedValue == other._storedValue);
}

bool    Fixed::operator!=( Fixed const &other ) const
{
	return (this->_storedValue != other._storedValue);
}

// Arithmetic operators
Fixed   Fixed::operator+( Fixed const &other ) const
{
	Fixed	temp;

	temp.setRawBits(this->_storedValue + other._storedValue);
	return (temp);
}

Fixed   Fixed::operator-( Fixed const &other ) const
{
	Fixed	temp;

	temp.setRawBits(this->_storedValue - other._storedValue);
	return (temp);
}

Fixed   Fixed::operator*( Fixed const &other ) const
{
	Fixed		temp;
	long long	res;

	res = static_cast<long long>(this->_storedValue * other._storedValue);
	temp.setRawBits(res >> _fractionalBits);
	return (temp);
}

Fixed   Fixed::operator/( Fixed const &other ) const
{
	if (other._storedValue == 0)
	{
		std::cerr << "Division by zero!" << std::endl;
		std::exit(1);
	}
	Fixed		temp;
	long long	num;

	num = static_cast<long long>(this->_storedValue) << this->_fractionalBits;
	temp.setRawBits(num / other._storedValue);
	return (temp);
}

// Increment and Decrement operators
Fixed&  Fixed::operator++()
{
	this->_storedValue++;
	return (*this);
}

Fixed   Fixed::operator++( int )
{
	Fixed	temp(*this);

	this->_storedValue++;
	return (temp);
}

Fixed&  Fixed::operator--()
{
	this->_storedValue--;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	temp(*this);

	this->_storedValue--;
	return (temp);
}

// Min and Max overloads
Fixed&	Fixed::min( Fixed& a, Fixed& b )
{
	return (a < b) ? a : b;
}

const Fixed&	Fixed::min( Fixed const &a, Fixed const &b )
{
	return (a < b) ? a : b;
}

Fixed&	Fixed::max( Fixed& a, Fixed& b )
{
	return (a > b) ? a : b;
}

const Fixed&	Fixed::max( Fixed const &a, Fixed const &b )
{
	return (a > b) ? a : b;
}

// Operator << overload
std::ostream&	operator<<( std::ostream& out, Fixed const & rhs )
{
	out << rhs.toFloat();
	return (out);
}
