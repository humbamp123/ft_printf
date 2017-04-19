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
	char	*temp;
	char	*temper;
	// printf("_s_S\n");
	// printf("%s\n", fmt);
	
	temp = (va_arg(arg, char *));
	if (temp)
		ERW((ret->fin = ft_appendit(ret, temp)) == 0, -1, "Appending Error");
	else
	{
		temper = ft_strdup("(null)\0");
		ERW((ret->fin = ft_appendit(ret, temper)) == 0, -1, "Appending Error");
	}
	(*fmt)++;
	return (1);
}