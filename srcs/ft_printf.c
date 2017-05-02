/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:41:26 by apineda           #+#    #+#             */
/*   Updated: 2017/04/05 21:06:39 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_queenies_crazy_write_function(char *str, int len)
{
	char null;

	null = '\0';
	while (len--)
	{
		if (*str == 7)
			write(1, &null, 1);
		else
			ERR(write(1, &*str, 1) == -1, -1);
		str++;
	}
	return (1);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;
	int		len;

	ERR(format == 0 || *format == 0, 0);
	va_start(args, format);
	ERR((len = ft_vasprintf(&str, format, args)) == -1, -1);
	ERR2(ft_queenies_crazy_write_function(str, len) == -1, va_end(args),
		ft_strdel(&str), -1);
	ft_strdel(&str);
	va_end(args);
	return (len);
}
