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

int		ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;
	int		i;

	ERR(format == 0 || *format == 0, 0);
	va_start(args, format);
	ERW((i = ft_vasprintf(&str, format, args)) == -1, -1, "Vasprintf Error");
	ERW2(write(1, str, i) == -1, va_end(args), ft_strdel(&str), -1, "Write Error");
	ft_strdel(&str);
	va_end(args);
	return (i);
}
