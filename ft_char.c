/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:39:20 by jauplat           #+#    #+#             */
/*   Updated: 2018/04/07 19:42:27 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_char(va_list ap, char *format, char *tmp)
{
	char		*s;
	int			i;
	wchar_t		c;

	i = 0;
	s = ft_strnew(500);
	if ((ft_strchr(tmp, 'l') == NULL) && *format == 'c')
	{
		i = (char)va_arg(ap, int);
		if (i == 0)
			*s = '~';
		else
			*s = i;
	}
	else if (*format == 'C' || (ft_strchr(tmp, 'l') && *format == 'c'))
	{
		c = (wchar_t)va_arg(ap, wint_t);
		i = ft_lenbigc(c, &s, i);
		ft_bigc(c, s, i);
	}
	return (s);
}

int		ft_lenbigc(wchar_t c, char **s, int len)
{
	if (c <= 0x7F && MB_CUR_MAX >= 1)
	{
		len = 0;
		*s[0] = 0x00;
	}
	if (c > 0x7F && c <= 0x7FF && MB_CUR_MAX >= 2)
	{
		len = 1;
		*s[0] = 0xC0;
	}
	else if (c > 0x7FF && c <= 0xFFFF && MB_CUR_MAX >= 3)
	{
		len = 2;
		*s[0] = 0xE0;
	}
	else if (c > 0xFFFF && c <= 0x1FFFFF && MB_CUR_MAX >= 4)
	{
		len = 3;
		*s[0] = 0xF0;
	}
	else
		return (0);
	return (len);
}

void	ft_bigc(wchar_t c, char *s, int len)
{
	int		i;

	i = 0;
	i = len;
	if (len == 0 && c == '\0')
		ft_putchar('\0');
	while (len)
	{
		s[len] = ((c & 0x3F) + 0x80);
		len--;
		c = (c >> 6);
	}
	s[len] = c + s[len];
}

int		ft_printchar(char *str, char *format, char *tmp)
{
	int		i;
	int		k;

	k = ft_atoi(tmp);
	i = 0;
	while (str[i] != '~' && str[i])
		i++;
	if ((*format == 'c' && !(ft_strchr(tmp, 'l'))) || \
		(*format == 'C' && !ft_strlen(str)))
	{
		if (k == 0)
			k = 1;
		if (k > i)
			str[i] = '\0';
		write(1, str, k);
		return (k);
	}
	else
		ft_putstr(str);
	return (i);
}
