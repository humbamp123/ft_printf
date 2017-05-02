/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:11:16 by apineda           #+#    #+#             */
/*   Updated: 2017/04/05 13:29:45 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	ft_x_flags(t_print *ret)
{
	ret->tmp = ret->flags.pound && (int)ret->var != 0 ?
		ft_appender(ft_strdup("0x\0"), ret->tmp) : ret->tmp;
	return (0);
}

static int	ft_x_width(t_print *ret)
{
	int		spacelen;
	char	*temp;

	spacelen = (!ret->flags.in_pres && ret->neg) || ret->flags.plus ||
		ret->flags.space ? ret->flags.width - (int)ft_strlen(ret->tmp) - 1 :
		ret->flags.width - (int)ft_strlen(ret->tmp);
	ERR1(spacelen <= 0, ft_x_flags(ret), 0);
	temp = ft_strnew(spacelen + 1);
	if (!ret->flags.in_pres && !ret->flags.minus && ret->flags.zero)
	{
		ft_memset(temp, '0', spacelen);
		ret->tmp = ft_appender(temp, ret->tmp);
	}
	else
	{
		ft_memset(temp, ' ', spacelen);
		ret->tmp = ret->flags.minus ? ft_appender(ret->tmp, temp) :
			ft_appender(temp, ret->tmp);
	}
	return (0);
}

static int	ft_x_precision(t_print *ret)
{
	char	*temp;
	int		zerolen;

	if (ret->flags.pres > 0 && (int)ft_strlen(ret->tmp) <= ret->flags.pres)
	{
		zerolen = ret->flags.pres - (int)ft_strlen(ret->tmp);
		temp = ft_strnew(zerolen + 1);
		ft_memset(temp, '0', zerolen);
		ret->tmp = ft_appender(temp, ret->tmp);
		ret->flags.pres = ft_strlen(ret->tmp);
	}
	return (0);
}

int			ft_printf_x(t_print *ret, const char **fmt, va_list arg)
{
	ret->flags.cap = **fmt == 'X' ? 1 : 0;
	ft_new_len(ret, arg);
	ERR1(ret->flags.in_pres && (long long)ret->var == 0 && ret->flags.pres
		== 0, (*fmt)++, 0);
	ret->neg = (long long)ret->var < 0 ? 1 : 0;
	ret->tmp = ret->neg ? ft_itoa_base((unsigned)ret->var, 16) :
		ft_itoa_base(ret->var, 16);
	if (ret->flags.in_pres == 1)
		ft_x_precision(ret);
	if (ret->flags.width && ret->flags.width > ret->flags.pres)
		ft_x_width(ret);
	ret->tmp = ret->flags.pound && (int)ret->var != 0 ?
		ft_appender(ft_strdup("0x\0"), ret->tmp) : ret->tmp;
	ret->fin = ret->flags.cap ? ft_appender(ret->fin, ft_to_upper(ret->tmp)) :
		ft_appender(ret->fin, ret->tmp);
	(*fmt)++;
	return (1);
}
