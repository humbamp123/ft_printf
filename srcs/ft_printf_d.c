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
	int		spacelen;
	char	*temp;
	char	chr;

	spacelen = (!ret->flags.in_pres && ret->neg) || ret->flags.plus ?
		ret->flags.width - (int)ft_strlen(ret->fin) -1 : ret->flags.width -
		(int)ft_strlen(ret->fin);
	temp = ft_strnew(spacelen + 1);
	chr = 
	if (ret->flags.in_pres)
	{
		ft_memset(temp, ' ', spacelen);
		ret->tmp = ft_appender(temp, ret->tmp);
	}	
	(void)ret;
	return (0);
}

static int	ft_d_precision(t_print *ret)
{
	char	*temp;
	int		zerolen;

	if (ret->flags.pres > 0 && (int)ft_strlen(ret->tmp) < ret->flags.pres)
	{
		zerolen = ret->flags.pres - (int)ft_strlen(ret->tmp);
		temp = ft_strnew(zerolen + 1);
		ft_memset(temp, '0', zerolen);
		if (ret->flags.zero && !ret->neg)
			ret->tmp = ft_appender(temp, ret->tmp);
		else 
		{
			if (ret->flags.plus || ret->neg)
				ret->tmp = ret->neg ? ft_appender(ft_strdup("-\0"), temp) :
					ft_appender(ft_strdup("+\0"), temp);
			else if (ret->flags.space)
				ret->tmp = ft_appender(ft_strdup(" \0"), temp);
			ret->tmp = ft_appender(temp, ret->tmp);
		}
		ret->flags.pres = ft_strlen(ret->tmp);
	}
	return (0);
}

int			ft_printf_d(t_print *ret, const char **fmt, va_list arg)
{
	ret->var = va_arg(arg, int);
	ret->neg = (int)ret->var < 0 ? 1 : 0;
	ret->tmp = ret->neg == 1 ? ft_itoa(-(int)ret->var) : ft_itoa((int)ret->var);
	if (ret->flags.in_pres == 1)
		ft_d_precision(ret);
	if (ret->flags.width && ret->flags.width > ret->flags.pres &&
		ret->flags.width > (int)ft_strlen(ret->fin))
		ft_d_width(ret);
	if (ret->flags.flgs && ret->flags.in_pres == 0 && ret->flags.width == 0)
		ft_d_flags(ret);
	ret->fin = ft_appender(ret->fin, ret->tmp);
	(*fmt)++;
	return (1);
}
