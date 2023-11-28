/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lushiwa <lushiwa@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:19:57 by lushiwa           #+#    #+#             */
/*   Updated: 2023/11/13 18:20:03 by lushiwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//== SRC (functions)===

#include "ft_printf.h"

//function does the conversion by recursively dividing the integer by 10 
//and converting each digit to an ASCII character
//8976
//'6' -> 897
//       '7' -> 89
//	            '9' -> 8 
//			          '8'
//
//8976

int	recursivenum_b10(int num, int position)
{
	char	aux;

	if (num >= 10)
	{
		aux = (num % 10) + 48;
		position = recursivenum_b10(num / 10, position);
		if (position == -1)
			return (-1);
		position += 1;
	}
	else
	{
		aux = num + 48;
		position += 1;
	}
	if (write(1, &aux, 1) == -1)
		return (-1);
	return (position);
}
//aux = num + 48; // transform to ASCII.
//convert an integer (base 10) to a string and write to a file descriptor

int	ft_printnum(int n)
{
	int	position;

	position = 0;
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	if (n < 0)
	{
		n = n * (-1);
		if (write(1, "-", 1) == -1)
			return (-1);
		position += 1;
	}
	position = recursivenum_b10(n, position);
	return (position);
}
// "d" or "i" == int	ft_printnum(int n)
//if (n == -2147483648) //if INT_MIN
//n = n * (-1);  //tranform the negative num to a positive number.
//================================

//function is a recursive function that converts an unsigned integer into
//its corresponding ASCII representation and writes it to a file descriptor
int	recursive_unsign(unsigned int num, int position)
{
	char	aux;

	if (num >= 10)
	{
		aux = (num % 10) + 48;
		position = recursive_unsign(num / 10, position);
		if (position == -1)
			return (-1);
		position += 1;
	}
	else
	{
		aux = num + 48;
		position += 1;
	}
	if (write(1, &aux, 1) == -1)
		return (-1);
	return (position);
}

//convert an integer (base10) to string and write to a file descriptor
int	ft_printnum_unsign(unsigned int n)
{
	int	position;

	position = 0;
	position = recursive_unsign(n, position);
	return (position);
}
//"u" = int	ft_printnum_unsign(unsigned int n)
// <limits.h>
// INT_MIN = Valor mínimo var tipo int. -2147483648 (MEANING: -2147483647 - 1) 
// INT_MAX = Valor máximo var tipo int. 2147483647