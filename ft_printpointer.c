/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lushiwa <lushiwa@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:43:32 by lushiwa           #+#    #+#             */
/*   Updated: 2023/11/21 22:43:39 by lushiwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//== SRC (functions)================================================
#include "ft_printf.h"

static int	recursive_pointer(unsigned long num, int position)
{
	int			aux;
	static char	*base = "0123456789abcdef";

	if (num >= 16)
	{
		aux = (num % 16);
		position = recursive_pointer(num / 16, position);
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
//"0123456789abcdef" -- since it's an unsigned long, there's no negative num.

//pointer always begin with a "0x" to indicate that is a pointer address.
int	ft_printpointer(unsigned long num)
{
	int	position;
	int	r_ret;

	position = 0;
	position = write(1, "0x", 2);
	if (position == -1)
		return (-1);
	r_ret = recursive_pointer(num, position);
	if (r_ret == -1)
		return (-1);
	position = r_ret;
	return (position);
}
