/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:19:51 by apineda           #+#    #+#             */
/*   Updated: 2017/04/05 20:24:29 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# ifndef ERRS
#  define ERR(a, b) do{if(a){return(b);}}while(0)
#  define ERR1(a, b, c) do{if(a){b;return(c);}}while(0)
#  define ERR2(a, b, c, d) do{if(a){b;c;return(d);}}while(0)
#  define ERR3(a, b, c, d, e) do{if(a){b;c;d;return(e);}}while(0)
#  define ERR4(a, b, c, d, e, f) do{if(a){b;c;d;e;return(f);}}while(0)
#  define ERR5(a, b, c, d, e, f, g) do{if(a){b;c;d;e;f;return(g);}}while(0)
# endif

# ifndef ERWS
#  define ERW(a,b,c) do{if(a){pl(c); return(b);}}while(0)
#  define ERW1(a,b,c,d) do{if(a){b;pl(d);return(c);}}while(0)
#  define ERW2(a,b,c,d,e) do{if(a){b;c;pl(e);return(d);}}while(0)
#  define ERW3(a,b,c,d,e,f) do{if(a){b;c;d;pl(f);return(e);}}while(0)
#  define ERW4(a,b,c,d,e,f,g) do{if(a){b;c;d;e;pl(g);return(f);}}while(0)
#  define ERW5(a,b,c,d,e,f,g,h) do{if(a){b;c;d;e;f;pl(h);return(g);}}while(0)
# endif

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# define hex "0123456789ABCDEF"

typedef struct		s_print {
char				*fin;
int					save;
char				*temp;
}					t_print;


void				pl(char const *s);
int					ft_printf(const char *format, ...);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s1);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
char				*ft_itoa(intmax_t nbr);
char				*ft_itoa_base(uintmax_t n, short base);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_appendstr(t_print ret, char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcat(char *dst, const char *src);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_vasprintf(char **ret, const char *fmt, va_list arg);

int					ft_printf_s(t_print ret, const char *fmt, va_list arg);
int					ft_printf_d(t_print ret, const char *fmt, va_list arg);

#endif
