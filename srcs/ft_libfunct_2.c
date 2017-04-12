/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libfunct_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:42:22 by apineda           #+#    #+#             */
/*   Updated: 2017/03/09 21:42:24 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

size_t		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*cpy;

	cpy = b;
	while (len--)
	{
		*cpy = c;
		cpy++;
	}
	return (b);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		j;
	char	*dest;
	char	*source;

	j = len;
	dest = (char *)dst;
	source = (char *)src;
	if (source == dest)
		return (dst);
	else if (source > dest)
	{
		while (len--)
			*dest++ = *source++;
	}
	else
	{
		dest = dest + j - 1;
		source = source + j - 1;
		while (j--)
			*dest-- = *source--;
	}
	return (dst);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while (s2[i] != '\0' || s1[i] != '\0')
	{
		if (s1[i] != s2[i] && i < n)
		{
			a = s2[i];
			b = s1[i];
			return (b - a);
		}
		else
			i++;
	}
	return (0);
}