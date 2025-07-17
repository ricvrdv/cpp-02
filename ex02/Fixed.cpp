#include "Fixed.hpp"

int const   Fixed::_fraction = 8;

// CANONICAL FORM
Fixed::Fixed( void ) : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &other )
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=( Fixed const &other )
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed( void )
{
	//std::cout << "Destructor called" << std::endl;
}

// PARAMETRIC CONTRUCTORS
Fixed::Fixed( int const n )
{
	//std::cout << "Int constructor called" << std::endl;
	this->_value = n << _fraction;
}

Fixed::Fixed( float const f )
{
	//std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(f * (1 << _fraction));
}

// MEMBER FUNCTIONS

int Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_value) / (1 << this->_fraction));
}

int		Fixed::toInt( void ) const
{
	return (this->_value >> this->_fraction);
}

// COMPARISON OPERATORS
bool    Fixed::operator>(Fixed const &other) const
{
	return (this->_value > other._value);
}

bool    Fixed::operator<(Fixed const &other) const
{
	return (this->_value < other._value);
}

bool    Fixed::operator>=(Fixed const &other) const
{
	return (this->_value >= other._value);
}

bool    Fixed::operator<=(Fixed const &other) const
{
	return (this->_value <= other._value);
}

bool    Fixed::operator==(Fixed const &other) const
{
	return (this->_value == other._value);
}

bool    Fixed::operator!=(Fixed const &other) const
{
	return (this->_value != other._value);
}

// ARITHMETIC OPERATORS
Fixed   Fixed::operator+(Fixed const &other) const
{
	Fixed	temp;

	temp.setRawBits(this->_value + other._value);
	return (temp);
}

Fixed   Fixed::operator-(Fixed const &other) const
{
	Fixed	temp;

	temp.setRawBits(this->_value - other._value);
	return (temp);
}

Fixed   Fixed::operator*(Fixed const &other) const
{
	Fixed		temp;
	long long	res;

	res = static_cast<long long>(this->_value * other._value);
	temp.setRawBits(res >> _fraction);
	return (temp);
}

Fixed   Fixed::operator/(Fixed const &other) const
{
	if (other._value == 0)
	{
		std::cerr << "Division by zero!" << std::endl;
		exit(1);
	}
	Fixed		temp;
	long long	num;

	num = static_cast<long long>(this->_value) << this->_fraction;
	temp.setRawBits(num / other._value);
	return (temp);
}

// INCREMENT / DECREMENT
Fixed&  Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed   Fixed::operator++(int)
{
	Fixed	temp(*this);

	this->_value++;
	return (temp);
}

Fixed&  Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	this->_value--;
	return (temp);
}

// MIN / MAX
Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed&	Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b) ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed&	Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b) ? a : b;
}

// OPERATOR << OVERLOAD
std::ostream&	operator<<( std::ostream& out, Fixed const & rhs )
{
	out << rhs.toFloat();
	return (out);
}