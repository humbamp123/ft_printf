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

#include "libprintf.h"


int		ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;
	int		i;
	char	c;

	i = 0;
	va_start(args, format);
	if (!(format = ft_strchr(format, '%')))
	{
		i = ft_strlen(format);
		write(1, format, i);
	}
	else
	{
		format++;
		while (*format != '\0')
		{
			if (*format == 'd')
			{
				i = va_arg(args, int);
				str = ft_itoa(i);
				write(1, str, ft_strlen(str));
			}
			else if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
			}
			else if (*format == '\n')
			{
				write(1, "\n", 1);
			}
			else
			{
				write(1, "something else\0", 15);
			}
			format++;
		}
		va_end(args);
	}
	return (i);
}
