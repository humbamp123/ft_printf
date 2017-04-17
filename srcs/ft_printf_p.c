/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:11:16 by apineda           #+#    #+#             */
/*   Updated: 2017/04/05 13:29:45 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int				ft_printf_p(t_print *ret, const char **fmt, va_list arg)
{
	char	*temp;
	void	*temper;

	temp = ft_strdup("0x\0");
	temper = va_arg(arg, void *);
	ERW((temp = ft_appender(temp, ft_itoa_base((uintmax_t)temper, 16))) == 0, -1, "Appending Error");
	ERW((ret->fin = ft_appendit(ret, temp)) == 0, -1, "Appending Error");
	if (**fmt != 0)
		ft_strlen(*fmt);
	return (1);
}