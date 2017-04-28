/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 13:02:38 by apineda           #+#    #+#             */
/*   Updated: 2017/04/05 21:13:34 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libprintf.h"

int		main(void)
{
	int		i_int;
	long	i_long;
	long long	i_ll;
	long long	i;
	unsigned int	i_uint;
	// unsigned long	i_ulong;
	unsigned long long	i_ull;
	char	c;
	char	c_str[50] = "testing\0";
	char	*c_ret;
	unsigned char	c_uchr;
	// unsigned char	*c_ustr;
	short	i_short;
	// unsigned short i_ushort;
	float	f_float;
	double	d_double;
	long double	ld_ldouble;
	uint8_t	temp;

	i_int = +3;
	i_uint = 2147483650;
	i_long = 2147483650;
	i_ll = 0;
	i_ull = 1446744073709551615;
	c = 65;
	// c_str = "test\0";
	c_ret = NULL;
	c_uchr = 192;
	// c_ustr = "test";
	i_short = 32766;
	// i_ushort = 65.534;
	f_float = 2.2;
	d_double = 2.12345678901234;
	ld_ldouble = 2.123456789012345678901;
	
	i = 1;

	// ft_printf("ft_printf %06.5d\n", -11);

	// Zeros
	// printf("printf %0.5d-\n", -11);
	// ft_printf("ft_printf %0.5d-\n", -11);
	// printf("printf %07d-\n", -11);
	// printf("printf %07.5d-\n", -11);

	// // 


	// printf("printf   : %-5d|\n", -42);
	// ft_printf("ft_printf: %-5d|\n", -42);
	// 	ft_printf("\n");

	// printf("printf   : %.10d|\n", -123);
	// ft_printf("ft_printf: %.10d|\n", -123);
	// 	ft_printf("\n");

	// printf("printf   : %.3d|\n", -123);
	// ft_printf("ft_printf: %.3d|\n", -123);
	// 	ft_printf("\n");

	// printf("printf   : %.*d|\n", 3, 0);
	// ft_printf("ft_printf: %.*d|\n", 3, 0);
	// 	ft_printf("\n");

	// printf("printf   : %.*d|\n", 10, 0);
	// ft_printf("ft_printf: %.*d|\n", 10, 0);
	// 	ft_printf("\n");

	// printf("printf   : %.*d|\n", -15, 0);
	// ft_printf("ft_printf: %.*d|\n", -15, 0);
	// 	ft_printf("\n");

	// printf("printf   : %d|\n", -11);
	// ft_printf("ft_printf: %d|\n", -11);
	// 	ft_printf("\n");

	// printf("printf   : % +7d|\n", -11);
	// ft_printf("ft_printf: % +7d|\n", -11);
	// 	ft_printf("\n");
	// printf("printf   : % +7d|\n", 11);
	// ft_printf("ft_printf: % +7d|\n", 11);
	// 	ft_printf("\n");
	// printf("printf   : %0+7d|\n", -11);
	// ft_printf("ft_printf: %0+7d|\n", -11);
	// 	ft_printf("\n");
	// printf("printf   : %0+7d|\n", 11);
	// ft_printf("ft_printf: %0+7d|\n", 11);
	// 	ft_printf("\n");

	// printf("printf   : % 07d|\n", 11);
	// ft_printf("ft_printf: % 07d|\n", 11);
	// 	ft_printf("\n");
	// printf("printf   : %-07d|\n", 11);
	// ft_printf("ft_printf: %-07d|\n", 11);
	// 	ft_printf("\n");
	// printf("printf   : %-07.5d|\n", 11);
	// ft_printf("ft_printf: %-07.5d|\n", 11);	
	// 	ft_printf("\n");
	// printf("printf   : %-+07d|\n", 11);
	// ft_printf("ft_printf: %-+07d|\n", 11);
	// 	ft_printf("\n");
	// printf("printf   : %-+07.5d|\n", 11);
	// ft_printf("ft_printf: %-+07.5d|\n", 11);
	// 	ft_printf("\n");
	// printf("printf   : %#7d|\n", 11);
	// ft_printf("ft_printf: %#7d|\n", 11);
	// 	ft_printf("\n");
	// printf("printf   : %#7.5d|\n", 11);
	// ft_printf("ft_printf: %#7.5d|\n", 11);	

	// printf("%d\n",printf("%.d", i_int));
	// printf("\n");
	// printf("%0 5d", -3);
	// printf("\n");
	// Precision trumps width
	// IF PRECISION IS ZERO and ZERO is the value no character is written
	// printf("append test\n");
	// while (i < i_ll)
	// {
		// ft_printf("% ");
		
		// ft_printf("ft_printf \"%d\"\n", i_int);
		// printf("printf \"%d\"\n", i_int);
		
		// ft_printf("ft_printf \"%s\"\n", c_str);
		// printf("printf \"%s\"\n", c_str);
		
		// ft_printf("ft_printf \"%p\"\n", c_str);
		// printf("printf \"%p\"\n", c_str);
		
		// ft_printf("ft_printf \"%%\"\n");
		// printf("printf \"%%\"\n");
		// temp &= ~0x10;
		// printf("%d\n", temp);
		// temp |= 0x1;
		// ft_printf("%d\n", ft_atoi("2147483647"));
		// printf("%d\n", i);
		// printf("%d",printf("%*d\n", 015, i_int));
		// ft_printf("%\n");
		// printf("%\n");

		// ft_printf("%Z");
		// printf("\n");
		// printf("%-d", i_int);
		// printf("\n");

		// printf("%i\n", ft_printf("pits %s", c_str));
	// 	i++;
	// }


	// printf("Int\n");
	// ft_printf("%d\n", i_ll);
	// printf("%lld\n", i_ll);
	
	/*
	printf("Long\n");
	ft_printf("%lu\n", i_long);
	printf("%lu\n", i_long);
	
	printf("Long Long\n");
	ft_printf("%lld\n", i_ll);
	printf("%lld\n", i_ll);
	
	printf("Unsigned Int\n");
	ft_printf("%u\n", i_uint);
	printf("%u\n", i_uint);
	
	printf("Unsigned Long\n");
	ft_printf("%lu\n", i_ulong);
	printf("%lu\n", i_ulong);
	
	printf("Unsigned Long Long\n");
	ft_printf("%lu\n", i_ulong);
	printf("%lu\n", i_ulong);
	
	printf("Char\n");
	ft_printf("%c\n", c);
	printf("%c\n", c);
	
	printf("Unsigned Char\n");
	ft_printf("%c\n", c_uchr);
	printf("%c\n", c_uchr);
	
	printf("Char *\n");
	ft_printf("%s\n", c_str);
	printf("%s\n", c_str);
	
	printf("Unsigned Char *\n");
	ft_printf("%s\n", c_ustr);
	printf("%s\n", c_ustr);
	
	printf("Short\n");
	ft_printf("%hd\n", i_short);
	printf("%hd\n", i_short);
	
	printf("Unsigned Short\n");
	ft_printf("%d\n", i_ushort);
	printf("%d\n", i_ushort);
	
	printf("Float\n");
	ft_printf("%f\n", f_float);
	printf("%f\n", f_float);
	
	printf("Double\n");
	ft_printf("%f\n", d_double);
	printf("%f\n", d_double);
	
	printf("Long Double\n");
	ft_printf("%Lf\n", ld_ldouble);
	printf("%Lf\n", ld_ldouble);*/
}

