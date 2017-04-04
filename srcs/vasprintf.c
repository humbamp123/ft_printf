/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vasprintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:08:05 by apineda           #+#    #+#             */
/*   Updated: 2017/04/03 17:52:38 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

#define COUNT 39
#define SIZE 3

static  char	type_ary[COUNT][SIZE] = {
	{'d'}};

static int8_t (*funct_ptr[COUNT]) (char *ret, char *fmt, va_list arg) = {
	ft_printf_s};

// static int	flag_checker(char *ret, char **fmt, va_list arg)
// {
// 	while (*type_ary)
// 	{
// 		if (**fmt == **type_ary && )
// 	}
// }

static	int		checkthrough(char **ret, const char *fmt, va_list arg)
{
	char			*temp;

	printf("%c\n", type_ary[0][0]);
	while (*fmt)
	{
		if ((temp = ft_strchr(fmt, '%')))
		{
			ERR((*ret = ft_strsub(fmt, 0, -(fmt - temp))) == 0, -1);
			temp++;
			if (*temp == 0)
				break;
			fmt = temp;
		}
		break;
		// flag_checker(*ret, &fmt, arg);
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
