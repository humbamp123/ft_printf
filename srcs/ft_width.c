/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:11:16 by apineda           #+#    #+#             */
/*   Updated: 2017/04/05 13:29:45 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_width(t_print *ret, const char **fmt, va_list arg)
{
	if (**fmt == '*')
	{
		ret->flags.width = va_arg(arg, int);
		(*fmt)++;
	}
	else
	{
		ret->flags.width = ft_atoi(*fmt);
		(*fmt) += ft_nbrlen(ret->flags.width);
	}
	return (0);
}