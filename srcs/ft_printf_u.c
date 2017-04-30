/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:11:16 by apineda           #+#    #+#             */
/*   Updated: 2017/04/05 13:29:45 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	ft_u_flags(t_print *ret)
{
	return (0);
	(void)ret;
}

static int	ft_u_width(t_print *ret)
{
	int		spacelen;
	char	*temp;

	spacelen = (!ret->flags.in_pres && ret->neg) || ret->flags.plus || 
		ret->flags.space ? ret->flags.width - (int)ft_strlen(ret->tmp) - 1 :
		ret->flags.width - (int)ft_strlen(ret->tmp);
	ERR1(spacelen <= 0, ft_u_flags(ret), 0);
	temp = ft_strnew(spacelen + 1);
	if (!ret->flags.in_pres && !ret->flags.minus && ret->flags.zero)
	{
		ft_memset(temp, '0', spacelen);
		ret->tmp = ft_appender(temp, ret->tmp);
		ft_u_flags(ret);
	}
	else
	{
		ft_memset(temp, ' ', spacelen);
		ft_u_flags(ret);
		ret->tmp = ret->flags.minus ? ft_appender(ret->tmp, temp) :
			ft_appender(temp, ret->tmp);
	}
	return (0);
}

static int	ft_u_precision(t_print *ret)
{
	char	*temp;
	int		zerolen;

	if (ret->flags.pres > 0 && (int)ft_strlen(ret->tmp) <= ret->flags.pres)
	{
		zerolen = ret->flags.pres - (int)ft_strlen(ret->tmp);
		ERR1(zerolen <= 0, ft_u_flags(ret), 0);
		temp = ft_strnew(zerolen + 1);
		ft_memset(temp, '0', zerolen);
		if (ret->flags.zero && !ret->neg)
			ret->tmp = ft_appender(temp, ret->tmp);
		ret->flags.pres = ft_strlen(ret->tmp);
	}
	else if (ret->flags.pres != 0)
		ft_u_flags(ret);
	return (0);
}

// (unsigned long long)ret->var + ULLONG_MAX + 1
int			ft_printf_u(t_print *ret, const char **fmt, va_list arg)
{
	ret->flags.ln_mod = **fmt == 'U' ? 3 : ret->flags.ln_mod;
	if (ret->flags.ln_mod)
		ft_new_len(ret, arg);
	else
		ret->var = va_arg(arg, int);
	ERR1(ret->flags.in_pres && (long long)ret->var == 0 && ret->flags.pres
		== 0, ft_skip(fmt), 1);
	ret->tmp = ft_itoa_base(ret->var, 10);
	if (ret->flags.in_pres == 1)
		ft_u_precision(ret);
	if (ret->flags.width && ret->flags.width > ret->flags.pres)
		ft_u_width(ret);
	if ((ret->flags.flgs || ret->neg) && ret->flags.pres == 0 &&
			ret->flags.width == 0)
		ft_u_flags(ret);
	ret->fin = ft_appender(ret->fin, ret->tmp);
	(*fmt)++;
	return (1);
}
