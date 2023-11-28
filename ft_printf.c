/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lushiwa <lushiwa@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:16:13 by lushiwa           #+#    #+#             */
/*   Updated: 2023/10/31 16:16:20 by lushiwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Escribe una librería que contenga la función ft_printf(), 
// que imite el printf() original
//Deberás implementar las siguientes conversiones: c s p d i u x X %
// autorizadas: malloc, free, write, va_start, va_arg, va_copy, va_end
// funcion variádica "...":

//== SRC (functions) are in 5 different files ".c" ====================
//== Include (library): ===============================================

int	ft_transform(char letter, va_list inputlist, int position)
{
	if (letter == 'c')
		position = ft_printchar(va_arg(inputlist, int));
	else if (letter == 's')
		position = ft_printstring(va_arg(inputlist, char *));
	else if (letter == 'd' || letter == 'i')
		position = ft_printnum(va_arg(inputlist, int));
	else if (letter == 'u')
		position = ft_printnum_unsign(va_arg(inputlist, unsigned int));
	else if (letter == 'p')
		position = ft_printpointer(va_arg(inputlist, unsigned long));
	else if (letter == 'x')
		position = ft_print_hex_low(va_arg(inputlist, unsigned int));
	else if (letter == 'X')
		position = ft_print_hex_up(va_arg(inputlist, unsigned int));
	else if (letter == '%')
		position = ft_printchar('%');
	return (position);
}

int	ft_printf(char const *pointer, ...)
{
	int		i;
	int		position;
	int		t_ret;
	va_list	inputlist;

	va_start (inputlist, pointer);
	i = 0;
	position = 0;
	while (pointer[i] != '\0')
	{
		if (pointer[i] == '%' && pointer[i + 1] != '\0')
		{
			t_ret = ft_transform(pointer[i + 1], inputlist, position);
			i++;
		}
		else
			t_ret = write(1, &pointer[i], 1);
		if (t_ret == -1)
			return (-1);
		position += t_ret;
		i++;
	}
	va_end (inputlist);
	return (position);
}
// conversiones:
// • %c Imprime un solo carácter.
// • %s Imprime una string (como se define por defecto en C).
// • %p El puntero void * dado como argumento se imprime en formato hexadecimal.
// • %d Imprime un número decimal (base 10).
// • %i Imprime un entero en base 10.
// • %u Imprime un número decimal (base 10) sin signo.
// • %x Imprime un número hexadecimal (base 16) en minúsculas.
// • %X Imprime un número hexadecimal (base 16) en mayúsculas.
// • % % para imprimir el símbolo del porcentaje.
//
// Las macros: va_start, va_arg, va_copy, va_end
		// va_arg devuelve el argumento actual. 
		// va_copy  y  va_start  va_end no devuelven valores.
// Esta biblioteca contiene varias macros p/ trabajar con argumentos variádicos:
// 		va_list: Es un puntero al último argumento fijo en la función variádica.
// 		va_start: Inicializa va_list para su uso.
// 		va_arg: Recupera el siguiente argumento de la lista.
// 		va_end: Limpia va_list.
// 		va_copy: Copia un va_list
//====================================
/*
#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int original;
	int original_c;
	int original_s;
	int original_d;
	int original_i;
	int original_u;
	int original_p;
	int original_hp;
	int original_hl;
	int original_hu;
	int mine;
	int mine_c;
	int mine_s;
	int mine_d;
	int mine_i;
	int mine_u;
	int mine_p;
	int mine_hp;
	int mine_hl;
	int mine_hu;

//test %
printf("\ntest %%:\n");
	original = printf("%% %% %%\n");
	mine = ft_printf("%% %% %%\n\n");

//test c (char)
printf("\ntest c:\n");
char c = 'h';
	original_c = printf("character using %%c is = %c\n", c);
	mine_c = ft_printf("character using %%c is = %c\n\n", c);

//test s (string)
printf("\ntest s:\n");
char str3[] = "hola";
	original_s = printf("string using %%s is = %s\n", str3);
	mine_s = ft_printf("string using %%s is = %s\n\n", str3);

// test d i (d = decimal, i = integer // i can be printed with d too)
printf("\ntest d and i:\n");
int num4 = 10;
int num5 = 9;

	original_i = printf("num using %%i is = %i\n", num4);
	mine_i = ft_printf("num using %%i is = %i\n\n", num4);

	original_d = printf("num using %%d is = %d\n", num5);
	mine_d = ft_printf("num using %%d is = %d\n\n", num5);

//test u (unsigned int)
printf("\ntest u:\n");
int var6 = 99;
	original_u = printf("unsigned int %%u is = %u\n", var6);
	mine_u = ft_printf("unsigned int %%u is = %u\n\n", var6);

//test p (hex pointer)
printf("\ntest p:\n");
int address = 255;
void *hex_p = &address;
	original_hp = printf("hexadecimal pointer address %%p is = %p\n", hex_p);
	mine_hp = ft_printf("hexadecimal pointer address %%p is = %p\n\n", hex_p);

//test x X (hex lower and upper case)
printf("\ntest x:\n");
unsigned int hex_low = 067321;
	original_hl = printf("hexadecimal lowercase %%x is = %x\n", hex_low);
	mine_hl = ft_printf("hexadecimal lowercase %%x is = %x\n\n", hex_low);

printf("\ntest X:\n");
unsigned int hex_up = 067321;
	original_hu = printf("hexadecimal uppercase %%X is = %X\n", hex_up);
	mine_hu = ft_printf("hexadecimal uppercase %%X is = %X\n\n", hex_up);

return (0);
}
*/