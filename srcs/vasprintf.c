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

static size_t	flag_checker(char **ret, const char *fmt, va_list arg)
{
	int			i;

	i = 0;
	while (i < COUNT)
	{
		if (*fmt && (ft_strncmp(fmt, type_ary[i], 1)) == 0)
		{
			fmt += i;
			(*funct_ptr[i])(ret, fmt, arg);
			return(ft_strlen(type_ary[i]));
		}
		i++;
	}
	return (0);
}

static	int		checkthrough(char **ret, const char *fmt, va_list arg)
{
	int				save;
	int				i;
	char			*temp;

	save = 0;
	while (*fmt)
	{
		i = 0;
		while (fmt[i] != '\0' && fmt[i] != '%')
			i++;
		temp = ft_strsub(fmt, 0, i);
		ERR((*ret = ft_appendstr(*ret, temp)) == NULL, -1);
		if (save != 0)
			free(temp);
		else
			save = 1;
		fmt += i;
		if (*fmt == '%')
		{
			if (*(++fmt) == 0)
				break;
			ERW((i += flag_checker(ret, fmt, arg)) == -1, -1, "Flag Error");
		}
	}
	return(ft_strlen(*ret));
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
	// printf("%d\n", r);
	return (r);
}


