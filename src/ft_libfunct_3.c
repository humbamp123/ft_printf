/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libfunct_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:29:36 by apineda           #+#    #+#             */
/*   Updated: 2017/03/09 21:29:55 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	ft_nbrlen(intmax_t num)
{
	int		flag;

	if (num == 0)
		return (1);
	flag = num < 0 ? 1 : 0;
	while (num != 0)
	{
		num = num / 10;
		++flag;
	}
	return (flag);
}

char		*ft_itoa(intmax_t nbr)
{
	char	*str;
	int		len;
	int		flag;

	len = ft_nbrlen(nbr);
	if (!(str = ft_strnew(len)))
		return (NULL);
	flag = nbr < 0 ? 1 : 0;
	nbr = flag ? -nbr : nbr;
	while (--len)
	{
		str[len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	str[len] = flag ? '-' : nbr % 10 + '0';
	return (str);
}

static int	ft_nbrlen_base(uintmax_t num, short base)
{
	int		flag;

	if (num == 0)
		return (1);
	flag = num < 0 ? 1 : 0;
	while (num != 0)
	{
		num = num / 10;
		++flag;
	}
	return (flag);
}

char		*ft_itoa_base(uintmax_t nbr, short base)
{
	char	*str;
	int		len;
	int		flag;
	char	hex[16];

	hex = "0123456789ABCDEF";
	len = ft_nbrlen(nbr);
	if (!(str = ft_strnew(len)))
		return (NULL);
	flag = nbr < 0 ? 1 : 0;
	nbr = flag ? -nbr : nbr;
	while (--len)
	{
		str[len] = hex[nbr % base];
		nbr = nbr / base;
	}
	str[len] = hex[nbr % base];
	return (str);
}
