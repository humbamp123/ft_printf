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

int		ft_printf_s(t_print *ret, const char **fmt, va_list arg)
{
	printf("_c\n");
	// printf("%s\n", fmt);
	ERW((ret->fin = ft_appendit(ret, va_arg(arg, char *))) == 0, -1, "Appending Error");
	if (**fmt != 0)
		ft_strlen(*fmt);
	return (1);
}