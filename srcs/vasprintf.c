

#include "libprintf.h"

static	int	checkthrough(char **ret, const char *fmt, va_list arg)
{
	char	*temp;

	while (*fmt)
	{
		if ((temp = ft_strchr(fmt, '%')))
		{
			*ret = ft_strsub(fmt, 0, -(fmt - temp));
			temp++;
			if (*temp == 0)
				break;
		}
		break;
		fmt++;
	}
	*ret = ft_appendstr(*ret, va_arg(arg, char *));
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
		ERR((*ret = ft_strdup(fmt)) == 0, -1);
		return (ft_strlen(fmt));
	}
	r = checkthrough(ret, fmt, arg);
	return (r);
}
