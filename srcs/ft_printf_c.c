/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:11:16 by apineda           #+#    #+#             */
/*   Updated: 2017/04/05 13:29:45 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_printf_c(t_print *ret, const char **fmt, va_list arg)
{
	char	*temp;

	temp = ft_strnew(2);
	temp[0] = va_arg(arg, int);
	temp[1] = 0;
	ERW((ret->fin = ft_appender(ret->fin, temp)) == 0, -1, "Appending Error");
	(*fmt)++;
	return (1);
}
