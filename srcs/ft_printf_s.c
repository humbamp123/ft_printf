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

// static int	ft_s_flags(t_print *ret)
// {
// 	return (0);
// 	(void)ret;
// }

static int	ft_s_width(t_print *ret)
{
	int		spacelen;
	char	*temp;

	spacelen = ret->flags.width - (int)ft_strlen(ret->tmp);
	// ERR1(spacelen <= 0, ft_s_flags(ret), 0);
	temp = ft_strnew(spacelen + 1);
	if (!ret->flags.in_pres && !ret->flags.minus && ret->flags.zero)
	{
		ft_memset(temp, '0', spacelen);
		ret->tmp = ft_appender(temp, ret->tmp);
		ft_s_flags(ret);
	}
	else
	{
		ft_memset(temp, ' ', spacelen);
		ft_s_flags(ret);
		ret->tmp = ret->flags.minus ? ft_appender(ret->tmp, temp) :
			ft_appender(temp, ret->tmp);
	}
	return (0);
}

// HAVE WIDTH LEF ADJUST IF NO

	// if (ret->flags.in_pres > 0 && (int)ft_strlen(ret->tmp) <= ret->flags.pres)
	// {
	// 	zerolen = ret->flags.pres - (int)ft_strlen(ret->tmp);
	// 	ERR1(zerolen <= 0, , 0);
	// 	temp = ft_strnew(zerolen + 1);
	// 	ft_memset(temp, '0', zerolen);
	// 	ret->tmp = ret->flags.minus ? ft_appender(ret->tmp, temp) :
	// 		ft_appender(temp, ret->tmp);
	// 	ret->flags.pres = ft_strlen(ret->tmp);
	// }
	// else 

static int	ft_s_precision(t_print *ret)
{
	char	*temp;

	if ((int)ft_strlen(ret->tmp) > ret->flags.pres && ret->flags.pres > 0)
	{
		temp = ft_strsub(ret->tmp, 0, ret->flags.pres);
		ft_strdel(&ret->tmp);
		ret->tmp = temp;
	}
	else if (ret->flags.pres != 0)
		ft_s_flags(ret);
	return (0);
}

int		ft_printf_s(t_print *ret, const char **fmt, va_list arg)
{
	char	*temper;

	ret->tmp = va_arg(arg, char *);
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
		if (ret->flags.flgs && ret->flags.pres == 0 &&
				ret->flags.width == 0)
			ft_s_flags(ret);
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

// int			ft_printf_s(t_print *ret, const char **fmt, va_list arg)
// {
// 	ret->flags.ln_mod = **fmt == 'U' ? 3 : 0; 
// 	ret->var = ret->flags.ln_mod ? ft_new_len(ret, arg) : va_arg(arg, int);
// 	ret->uvar = ret->var < 0 ? (unsigned)ret->var + UINT_MAX + 1 : (unsigned)ret->var;
// 	ERR1(ret->flags.in_pres && (long long)ret->uvar == 0 && ret->flags.pres
// 		== 0, ft_skip(fmt), 1);
// 	ret->tmp = ret->neg ? ft_itoa(-ret->uvar) : ft_itoa(ret->uvar);
// 	if (ret->flags.in_pres == 1)
// 		ft_u_precision(ret);
// 	if (ret->flags.width && ret->flags.width > ret->flags.pres)
// 		ft_u_width(ret);
// 	if ((ret->flags.flgs || ret->neg) && ret->flags.pres == 0 &&
// 			ret->flags.width == 0)
// 		ft_u_flags(ret);
// 	ret->fin = ft_appender(ret->fin, ret->tmp);
// 	(*fmt)++;
// 	return (1);
// }
