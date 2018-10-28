/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:43:52 by jauplat           #+#    #+#             */
/*   Updated: 2018/04/07 19:19:04 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_string(va_list ap, char *format, char *tmp)
{
	char		*str;
	char		*s1;
	wchar_t		*s2;

	if ((ft_strchr(tmp, 'l') == NULL) && *format == 's')
	{
		s2 = NULL;
		s1 = va_arg(ap, char *);
		str = ft_strdup(s1);
	}
	if (*format == 'S' || (*format == 's' && ft_strchr(tmp, 'l')))
	{
		s1 = NULL;
		s2 = (wchar_t *)va_arg(ap, wchar_t *);
		if (s2)
			str = ft_bigs(s2);
		else
			str = NULL;
	}
	if (!str)
		str = ft_strdup("(null)");
	return (str);
}

char	*ft_bigs(wchar_t *s2)
{
	int		i;
	int		len;
	char	*str;
	wchar_t	c;

	i = 0;
	len = 0;
	len = ft_lenbigs(s2, len, &i);
	str = ft_beginbigs(s2, len, i);
	while (--i != -1)
	{
		c = s2[i];
		if (s2[i] > 0x7F)
		{
			while (str[len] == '\0')
			{
				str[len] = ((c & 0x3F) + 0x80);
				c = (c >> 6);
				len--;
			}
			str[len] += c;
		}
		len--;
	}
	return (str);
}

char	*ft_beginbigs(wchar_t *s2, int len, int i)
{
	char	*str;

	str = ft_strnew(len + 1);
	len = 0;
	i = 0;
	while (s2 && s2[i])
	{
		if (s2[i] > 0x7F && s2[i] <= 0x7FF)
			str[len - 1] = ft_simplechr(&len, s2[i], i);
		else if (s2[i] > 0x7FF && s2[i] <= 0xFFFF)
			str[len - 2] = ft_simplechr(&len, s2[i], i);
		else if (s2[i] > 0xFFFF && s2[i] <= 0x1FFFFF)
			str[len - 3] = ft_simplechr(&len, s2[i], i);
		else if (s2[i] <= 0x7F)
			str[len] = ft_simplechr(&len, s2[i], i);
		i++;
	}
	return (str);
}

char	ft_simplechr(int *len, wchar_t c, int i)
{
	if (c > 0x7F && c <= 0x7FF)
	{
		((*len || i) ? (*len += 2) : (*len += 1));
		c = 0xC0;
	}
	else if (c > 0x7FF && c <= 0xFFFF)
	{
		((*len || i) ? (*len += 3) : (*len += 2));
		c = 0xE0;
	}
	else if (c > 0xFFFF && c <= 0x1FFFFF)
	{
		((*len || i) ? (*len += 4) : (*len += 3));
		c = 0xF0;
	}
	else if (c <= 0x7F)
		((*len || i) ? (*len = *len + 1) : (*len));
	return (c);
}

int		ft_lenbigs(wchar_t *s2, int len, int *k)
{
	int		i;

	i = 0;
	while (s2 && s2[i])
	{
		if (s2[i] > 0x7F && s2[i] <= 0x7FF)
			((len || i) ? (len += 2) : (len += 1));
		else if (s2[i] > 0x7FF && s2[i] <= 0xFFFF)
			((len || i) ? (len += 3) : (len += 2));
		else if (s2[i] > 0xFFFF && s2[i] <= 0x1FFFFF)
			((len || i) ? (len += 4) : (len += 3));
		else if (s2[i] <= 0x7F)
			((len || i) ? (len++) : (len += 0));
		i++;
	}
	k[0] = i;
	return (len);
}
