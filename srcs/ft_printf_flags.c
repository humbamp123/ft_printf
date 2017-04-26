/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:11:16 by apineda           #+#    #+#             */
/*   Updated: 2017/04/05 13:29:45 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_printf_flags(t_print *ret, const char **fmt, va_list arg)
{
	while (**fmt && (**fmt == ' ' || **fmt == '-' || **fmt == '+' ||
		**fmt == '#' || **fmt == '0'))
	{
		ret->flags.minus = **fmt == '-' ? 1 : ret->flags.minus;
		ret->flags.space = **fmt == ' ' ? 1 : ret->flags.space;
		ret->flags.plus = **fmt == '+' ? 1 : ret->flags.plus;
		ret->flags.pound = **fmt == '#' ? 1 : ret->flags.pound;
		ret->flags.zero = **fmt == '0' ? 1 : ret->flags.zero;
		ret->flags.flgs = 1;
		++(*fmt);
	}
	return (0);
	(void)arg;
}
