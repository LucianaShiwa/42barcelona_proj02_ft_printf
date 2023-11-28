/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lushiwa <lushiwa@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:19:16 by lushiwa           #+#    #+#             */
/*   Updated: 2023/11/13 19:19:32 by lushiwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//== SRC (functions)===
#include "ft_printf.h"

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}
// if write fails, automatically returns -1.