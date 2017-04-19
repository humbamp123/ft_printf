/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:11:16 by apineda           #+#    #+#             */
/*   Updated: 2017/04/05 13:29:45 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_printf_o(t_print *ret, const char **fmt, va_list arg)
{
	// printf("_d_i\n");
	ERW((ret->fin = ft_appendit(ret, ft_itoa_base(va_arg(arg, int), 16))) == 0, -1, "Appending Error");
	(*fmt)++;
	return (1);
}