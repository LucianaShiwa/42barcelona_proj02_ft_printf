/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lushiwa <lushiwa@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:04:37 by lushiwa           #+#    #+#             */
/*   Updated: 2023/11/21 22:04:44 by lushiwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//== SRC (functions)================================================
#include "ft_printf.h"

int	recursive_hex_low(unsigned int num, int position)
{
	int			aux;
	static char	*base = "0123456789abcdef";

	if (num >= 16)
	{
		aux = (num % 16);
		position = recursive_hex_low(num / 16, position);
		if (position == -1)
			return (-1);
		position += 1;
	}
	else
	{
		aux = num;
		position += 1;
	}
	if (write(1, &base[aux], 1) == -1)
		return (-1);
	return (position);
}

int	ft_print_hex_low(unsigned int num)
{
	int	position;

	position = 0;
	position = recursive_hex_low(num, position);
	return (position);
}

//===============

int	recursive_hex_up(unsigned int num, int position)
{
	int			aux;
	static char	*base = "0123456789ABCDEF";

	if (num >= 16)
	{
		aux = (num % 16);
		position = recursive_hex_up(num / 16, position);
		if (position == -1)
			return (-1);
		position += 1;
	}
	else
	{
		aux = num;
		position += 1;
	}
	if (write(1, &base[aux], 1) == -1)
		return (-1);
	return (position);
}

int	ft_print_hex_up(unsigned int num)
{
	int	position;

	position = 0;
	position = recursive_hex_up(num, position);
	return (position);
}
