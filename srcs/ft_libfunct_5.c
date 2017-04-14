/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libfunct_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:29:36 by apineda           #+#    #+#             */
/*   Updated: 2017/03/09 21:29:55 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	*ft_memalloc(size_t size)
{
	char	*str;

	str = malloc(size);
	if (str)
		ft_bzero(str, size);
	return (str);
}