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
	{"s"}, {"d"}};

static int	(*funct_ptr[COUNT]) (char **ret, const char *fmt, va_list arg) = {
	ft_printf_s, ft_printf_d};

static int	flag_checker(char **ret, const char *fmt, va_list arg)
{
	int			i;
	char		*dumb;

	i = 0;
	dumb = (char *)fmt;
	while (*type_ary)
	{
		if ((ft_strcmp(*type_ary, type_ary[i])) == 0)
		{
			(*funct_ptr[i])(ret, fmt, arg);
			break;
		}
		i++;
	}
	return (1);
}

static	int		checkthrough(char **ret, const char *fmt, va_list arg)
{
	char			*temp;
	size_t			spot;

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
			spot = 
		}
		ERR((spot = flag_checker(ret, fmt, arg)) == 0, -1);
		break;
		fmt++;
	}
	// ERR((*ret = ft_appendstr(*ret, va_arg(arg, char *))) == 0, -1);
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
	printf("%d\n", r);
	return (r);
}
