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

#define COUNT 25
#define SIZE 3

static  char	ary[COUNT][SIZE] = {
	{"-"}, {"+"}, {" "}, {"#"},
	{"0"}, {"*"}, {"1"}, {"2"},
	{"3"}, {"4"}, {"5"}, {"6"},
	{"7"}, {"8"}, {"9"}, {"."},
	{"s"}, {"d"}, {"i"}, {"u"},
	{"o"}, {"x"}, {"c"}, {"p"},
	{"%"}};

static int	(*funct_ptr[COUNT]) (t_print *ret, const char **fmt, va_list arg) =
 		{ft_printf_flags, ft_printf_flags, ft_printf_flags, ft_printf_flags,
 		ft_printf_flags, ft_width, ft_width, ft_width,
 		ft_width, ft_width, ft_width, ft_width,
 		ft_width, ft_width, ft_width, ft_precision,
 		ft_printf_s, ft_printf_d, ft_printf_d, ft_printf_u,
 		ft_printf_o, ft_printf_x, ft_printf_c, ft_printf_p,
 		ft_printf_p};


static size_t	flag_checker(t_print *ret, const char **fmt, va_list arg)
{
	int			i;
	int			rtn;

	i = 0;
	ft_bzero(&ret->flags, sizeof(ret->flags));
	while (i < COUNT)
	{
		if (**fmt && (ft_strnstr(*fmt, ary[i], ft_strlen(ary[i]))) != NULL)
		{
			ERR((rtn = (*funct_ptr[i])(ret, fmt, arg)) == -1, -1);
			if (rtn > 0)
				return(1);
		}
		i++;
	}
	ERR(**fmt == 0, 0);
	return (0);
}

static	int		checkthrough(char **ret, const char *fmt, va_list arg)
{
	t_print		list;
	int			i;

	list.save = 0;
	while (*fmt)
	{
		i = 0;
		while (fmt[i] != '\0' && fmt[i] != '%')
			i++;
		ERR((list.temp = ft_strsub(fmt, 0, i)) == NULL, -1);
		ERR((list.fin = ft_appendit(&list, list.temp)) == NULL, -1);
		if (list.save != 0)
			free(list.temp);
		else
			list.save = 1;
		fmt += i;
		if (*fmt == '%')
		{
			if (*(++fmt) == 0)
				break;
			ERW((i = flag_checker(&list, &fmt, arg)) == -1, -1, "Flag Error");
		}
	}
	*ret = list.fin;
	return(ft_strlen(list.fin));
}		


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


