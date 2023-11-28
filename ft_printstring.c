/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lushiwa <lushiwa@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:20:23 by lushiwa           #+#    #+#             */
/*   Updated: 2023/11/13 18:20:27 by lushiwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//== SRC (functions)======
#include "ft_printf.h"

int	ft_printstring(char *pointer)
{
	int	i;

	i = 0;
	if (!pointer)
		pointer = "(null)";
	while (pointer[i] != '\0')
	{
		if (ft_printchar(pointer[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}
//pointer = "(null)" / OR /
//do a else inside the while: return (write(1, "(NULL)", 6));