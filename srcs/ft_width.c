/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:11:16 by apineda           #+#    #+#             */
/*   Updated: 2017/04/05 13:29:45 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int			ft_new_len(t_print *ret, va_list arg)
{
	ret->var = 0;
	ERR((ret->var = ret->flags.ln_mod == 1 ? va_arg(arg, intmax_t) : ret->var) != 0, 0);
	ERR((ret->var = ret->flags.ln_mod == 2 ? va_arg(arg, size_t) : (unsigned)ret->var ) != 0, 0);
	ERR((ret->var = ret->flags.ln_mod == 3 ? va_arg(arg, long) : ret->var) != 0, 0);
	ERR((ret->var = ret->flags.ln_mod == 4 ? va_arg(arg, long long) : ret->var) != 0, 0);
	ERR((ret->var = ret->flags.ln_mod == 5 ? (short)va_arg(arg, int) : ret->var) != 0, 0);
	ERR((ret->var = ret->flags.ln_mod == 6 ? (char)va_arg(arg, int) : ret->var) != 0, 0);
	
	// ERW((ret->var = ret->flags.ln_mod == 1 ? va_arg(arg, intmax_t) : ret->var) != 0, 0, "intmax_t");
	// ERW((ret->var = ret->flags.ln_mod == 2 ? va_arg(arg, size_t) : (unsigned)ret->var ) != 0, 0, "size_t");
	// ERW((ret->var = ret->flags.ln_mod == 3 ? va_arg(arg, long) : ret->var) != 0, 0, "long");
	// ERW((ret->var = ret->flags.ln_mod == 4 ? va_arg(arg, long long) : ret->var) != 0, 0, "long long");
	// ERW((ret->var = ret->flags.ln_mod == 5 ? (short)va_arg(arg, int) : ret->var) != 0, 0, "short");
	// ERW((ret->var = ret->flags.ln_mod == 6 ? (char)va_arg(arg, int) : ret->var) != 0, 0, "char");
	return (0);
}

int			ft_len_mod(t_print *ret, const char **fmt, va_list arg)
{
	ret->flags.ln_mod = ft_strnstr(*fmt, "j", 1) ? 1 : ret->flags.ln_mod;
	ret->flags.ln_mod = ft_strnstr(*fmt, "z", 1) ? 2 : ret->flags.ln_mod;
	ret->flags.ln_mod = ft_strnstr(*fmt, "l", 1) ? 3 : ret->flags.ln_mod;
	ret->flags.ln_mod = ft_strnstr(*fmt, "ll", 2) ? 4 : ret->flags.ln_mod;
	ret->flags.ln_mod = ft_strnstr(*fmt, "h", 1) ? 5 : ret->flags.ln_mod;
	ret->flags.ln_mod = ft_strnstr(*fmt, "hh", 2) ? 6 : ret->flags.ln_mod;
	while (**fmt == 'j'|| **fmt == 'z' || **fmt == 'l' || **fmt == 'h')
		(*fmt)++;
	return (0);
	(void)arg;
}

int			ft_skip(const char **fmt)
{
	while (**fmt != '%' || *((*fmt) + 1) != 0)
		(*fmt)++;
	return (1);
}

int			ft_width(t_print *ret, const char **fmt, va_list arg)
{
	if (**fmt == '*')
	{
		ret->flags.width = va_arg(arg, int);
		if (ret->flags.width < 0)
		{
			ret->flags.flgs = 1;
			ret->flags.minus = 1;
			ret->flags.width = -ret->flags.width;
		}
		(*fmt)++;
	}
	else
	{
		ret->flags.width = ft_atoi(*fmt);
		(*fmt) += ft_nbrlen(ret->flags.width);
	}
	return (0);
}

int			ft_precision(t_print *ret, const char **fmt, va_list arg)
{
	if (**fmt == '.' && *((*fmt) + 1) == '*')
	{
		ret->flags.pres = va_arg(arg, int);
		(*fmt) += 2;
	}
	else if (**fmt == '.' && ft_isdigit(*((*fmt) + 1)))
	{
		(*fmt)++;
		ret->flags.pres = ft_atoi(*fmt);
		(*fmt) += ft_nbrlen(ret->flags.pres);
	}
	else
		(*fmt)++;
	ret->flags.in_pres = 1;
	return (0);
}
