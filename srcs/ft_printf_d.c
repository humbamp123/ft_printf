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

static int	ft_d_flags(t_print *ret)
{
	(void)ret;
	return (0);
}

static int	ft_d_width(t_print *ret)
{
	(void)ret;
	return (0);
}

static int	ft_d_precision(t_print *ret)
{
	char	*temp;

	if (ret->flags.pres > 0 && (int)ft_strlen(ret->tmp) < ret->flags.pres)
	{
		temp = ft_strnew(ret->flags.pres - (int)ft_strlen(ret->tmp));
		if (ret->flags.minus)
			ft_appender(temp, ret->fin);
	}
	return (0);
}

int			ft_printf_d(t_print *ret, const char **fmt, va_list arg)
{
	ret->var = (void *)va_arg(arg, int);
	// ret->tmp = ft_itoa(ret->var);
	if (ret->flags.in_pres == 1)
		ft_d_precision(ret);
	if (ret->flags.width && ret->flags.width > ret->flags.pres)
		ft_d_width(ret);
	if (ret->flags.flgs && ret->flags.in_pres == 0 && ret->flags.width == 0)
		ft_d_flags(ret);
	(*fmt)++;
	return (1);
}