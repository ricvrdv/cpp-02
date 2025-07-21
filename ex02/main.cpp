/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:06:27 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/07/21 11:06:29 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
    {
		std::cout << "[ Subject tests ]" << std::endl;
		Fixed		a;
    	Fixed const	b( Fixed(5.05f) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		std::cout << std::endl << "[ My tests ]" << std::endl;
		Fixed a(2.5f);
		Fixed b(5.0f);
		Fixed c(2.5f);
		Fixed d;

		std::cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
		std::cout << "------ Comparison ------" << std::endl;
		std::cout << "a < b: " << (a < b) << std::endl;
		std::cout << "a > b: " << (a > b) << std::endl;
		std::cout << "a <= c: " << (a <= c) << std::endl;
		std::cout << "a >= c: " << (a >= c) << std::endl;
		std::cout << "a == c: " << (a == c) << std::endl;
		std::cout << "a != b: " << (a != b) << std::endl;

		std::cout << "\n------ Arithmetic ------" << std::endl;
		std::cout << "a + b = " << (a + b) << std::endl;
		std::cout << "b - a = " << (b - a) << std::endl;
		std::cout << "a * b = " << (a * b) << std::endl;
		std::cout << "b / a = " << (b / a) << std::endl;

		std::cout << "\n- Increment/Decrement --" << std::endl;
		std::cout << "d = " << d << std::endl;
		std::cout << "++d = " << ++d << std::endl;
		std::cout << "d = " << d << std::endl;
		std::cout << "d++ = " << d++ << std::endl;
		std::cout << "d = " << d << std::endl;
		std::cout << "--d = " << --d << std::endl;
		std::cout << "d = " << d << std::endl;
		std::cout << "d-- = " << d-- << std::endl;
		std::cout << "d = " << d << std::endl;

		std::cout << "\n-------- Min/Max -------" << std::endl;
		Fixed& minRef = Fixed::min(a, b);
		Fixed& maxRef = Fixed::max(a, b);
		const Fixed ca(4.2f);
		const Fixed cb(6.9f);
		const Fixed& cmin = Fixed::min(ca, cb);
		const Fixed& cmax = Fixed::max(ca, cb);

		std::cout << "min(a, b)= " << minRef << std::endl;
		std::cout << "max(a, b)= " << maxRef << std::endl;
		std::cout << "ca = " << ca << ", cb = " << cb << std::endl;
		std::cout << "const min(ca, cb)= " << cmin << std::endl;
		std::cout << "const max(ca, cb)= " << cmax << std::endl;
	}
    return (0);
}
