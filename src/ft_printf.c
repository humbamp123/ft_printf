/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:41:26 by apineda           #+#    #+#             */
/*   Updated: 2017/03/08 13:11:07 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == 'd')
		{
			int i = va_args(args, int);
			ft_putnbr(i);
		}
		else if (*format == 'c')
		{
			char c = va_args(args, char);
			ft_putchar(c);
		}
		else
		{
			ft_putstr("something else");
		}
		ft_putchar('\n');
	}
}
