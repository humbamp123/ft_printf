/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:11:16 by apineda           #+#    #+#             */
/*   Updated: 2017/04/05 13:29:45 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	ft_s_width(t_print *ret)
{
	int		spacelen;
	char	*temp;

	spacelen = ret->flags.width - (int)ft_strlen(ret->tmp);
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

static int	ft_s_precision(t_print *ret)
{
	char	*temp;

	if ((int)ft_strlen(ret->tmp) > ret->flags.pres && ret->flags.pres > 0)
	{
		temp = ft_strsub(ret->tmp, 0, ret->flags.pres);
		ft_strdel(&ret->tmp);
		ret->tmp = temp;
	}
	return (0);
}

int		ft_printf_s(t_print *ret, const char **fmt, va_list arg)
{
	char	*temper;

	ret->tmp = **fmt == S ? va_arg(arg, long) : va_arg(arg, char *);
	ret->tmp = ret->tmp ? ft_strdup(ret->tmp) : NULL;
	if (ret->tmp)
	{
		if (ret->flags.in_pres == 1)
		{
			ERR2(ret->flags.pres == 0, ft_strdel(&ret->tmp), (*fmt)++, 1);
			ft_s_precision(ret);
		}
		if (ret->flags.width && ret->flags.width > (int)ft_strlen(ret->tmp))
			ft_s_width(ret);
		ERW((ret->fin = ft_appendit(ret, ret->tmp)) == 0, -1, "Appending Error");
	}
	else
	{
		ret->tmp = ft_strdup("(null)\0");
		ERR((ret->fin = ft_appender(ret->fin, ret->tmp)) == 0, -1);
	}
	(*fmt)++;
	return (1);
}
