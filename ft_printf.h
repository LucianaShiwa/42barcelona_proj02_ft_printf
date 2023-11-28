/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lushiwa <lushiwa@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:44:47 by lushiwa           #+#    #+#             */
/*   Updated: 2023/11/21 22:44:52 by lushiwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

/* inserir o prototipo da funcao */

//file ft_printf.c
int	ft_printf(char const *pointer, ...);
int	ft_transform(char letter, va_list inputlist, int position);

//file ft_printchar.c
int	ft_printchar(char c);

//file ft_printstring.c
int	ft_printstring(char *pointer);

//file ft_printnum.c
int	ft_printnum(int n);
int	ft_printnum_unsign(unsigned int n);
int	ft_printpointer(unsigned long num);

//file ft_printnum_hex.c
int	ft_print_hex_low(unsigned int num);
int	ft_print_hex_up(unsigned int num);

#endif
/*
https://learn.microsoft.com/es-es/cpp/c-language/cpp-integer-limits?view=msvc-170
*/
