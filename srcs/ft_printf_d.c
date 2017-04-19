/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:11:16 by apineda           #+#    #+#             */
/*   Updated: 2017/04/05 13:29:45 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_printf_d(t_print *ret, const char **fmt, va_list arg)
{
	// printf("_d_i\n");
	if (**fmt == 'i' || **fmt == 'd')
		ERW((ret->fin = ft_appendit(ret, ft_itoa(va_arg(arg, int)))) == 0, -1, "Appending Error");
	else if (**fmt == 'u')
		ERW((ret->fin = ft_appendit(ret, ft_itoa(va_arg(arg, unsigned int)))) == 0, -1, "Appending Error");
	(*fmt)++;
	return (1);
}