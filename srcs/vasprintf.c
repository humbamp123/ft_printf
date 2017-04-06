/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vasprintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:08:05 by apineda           #+#    #+#             */
/*   Updated: 2017/04/05 22:04:11 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

#define COUNT 39
#define SIZE 3

static  char	type_ary[COUNT][SIZE] = {
	{'d'}};

static int	(*funct_ptr[COUNT]) (char *ret, char *fmt, va_list arg) = {
	ft_printf_s};

static int	flag_checker(char *ret, const char *fmt, va_list arg)
{
	int			i;
	char		*dumb;

	i = 0;
	dumb = ret;
	dumb = (char *)fmt;
	arg = 0;
	// while (*type_ary)
	// {
	// 	if (ft_strcmp(*type_ary, ))
	// }
	i = funct_ptr[0];
	return (i);
}

static	int		checkthrough(char **ret, const char *fmt, va_list arg)
{
	char			*temp;
	size_t			spot;

	printf("%c\n", type_ary[0][0]);
	spot = 0;
	while (*fmt)
	{
		if ((temp = ft_strchr(fmt, '%')))
		{
			ERR((*ret = ft_strsub(fmt, spot, -(fmt - temp))) == 0, -1);
			temp++;
			if (*temp == 0)
				break;
			fmt = temp;
		}
		break;
		ERR((spot = flag_checker(*ret, fmt, arg)) == 0, -1);
		fmt++;
	}
	ERR((*ret = ft_appendstr(*ret, va_arg(arg, char *))) == 0, -1);
	return(ft_strlen(*ret));
}		

// *ret = ft_appendstr(*ret, va_arg(arg, char *));

int			ft_vasprintf(char **ret, const char *fmt, va_list arg)
{
	int		r;

	if (!*fmt || !fmt || !ret)
		return (0);
	*ret = NULL;
	if (!(ft_strchr(fmt, '%')))
	{
		ERW((*ret = ft_strdup(fmt)) == 0, -1, "Strdup Error");
		return (ft_strlen(fmt));
	}
	r = checkthrough(ret, fmt, arg);
	return (r);
}
