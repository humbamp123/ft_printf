/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_std.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:42:08 by apineda           #+#    #+#             */
/*   Updated: 2017/03/13 15:42:29 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
char		*ft_appendit(t_print *ret, char *str)
{
	char		*temp;

	if (str && ret->save)
	{
		// printf("###%s###\n", ret);
		temp = ft_strjoin(ret->fin, str);
		free(ret->fin);
		ret->fin = temp;
	}
	else if (str && !(ret->save))
	{
		ret->fin = ft_strdup(str);
		free(str);
	}
	return (ret->fin);
}

char		*ft_appender(char *ret, char *str)
{
	char	*temp;

	if (str && ret)
	{
		// printf("###%s###\n", ret);
		temp = ft_strjoin(ret, str);
		free(ret);
		ret = temp;
	}
	else if (str && !(ret))
	{
		ret = ft_strdup(str);
		free(str);
	}
	return (ret);
}