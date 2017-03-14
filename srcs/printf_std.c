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
char		*ft_appendstr(char *ret, char *str)
{
	char		*temp;

	if (str && ret)
	{
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

char		*ft_appendnstr(const char *ret, int len)
{
	char		*str;

	str = NULL;
	if (ret)
	{
		str = ft_strsub(ret, 0, len);
	}
	return (str);
}
