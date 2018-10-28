/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:39:33 by jauplat           #+#    #+#             */
/*   Updated: 2018/04/02 16:38:24 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_takepos(char **str, char *format, int k[2], char *tmp)
{
	char	*prec;

	if ((int)ft_strlen(*str) < k[1] && *format != 'S' && *format != 's' && \
		k[1] != 0)
	{
		prec = ft_strnew(k[1] + k[0]);
		if (*format == 'd' || *format == 'i' || *format == 'x' || \
			*format == 'X' || *format == 'o' || *format == 'u' || \
			*format == 'p' || *format == 'O' || *format == 'U' || \
			*format == 'D' || (*format == '%' && k[0] > k[1] && tmp[0] == '0'))
			ft_memset(prec, '0', (k[1] - (int)ft_strlen(*str)));
		else if (*format == 'C' || *format == 'c')
			ft_memset(prec, ' ', (k[1] - (int)ft_strlen(*str)));
		*str = ft_strjoin(prec, *str);
	}
	if ((*format == 's' || *format == 'S') && (int)ft_strlen(*str) > k[1])
		ft_bzero(*str + k[1], (int)ft_strlen(*str) - k[1]);
	return (k[1]);
}

int		ft_precbigs(char *str, int p)
{
	int			i;
	wchar_t		c;

	i = 0;
	c = (str[p - i] & 0xFF);
	if (c <= 0x7F || c > 0xC0)
		str[p - i] = '\0';
	else
	{
		while (i != p + 1)
		{
			c = (str[p - i] & 0xFF);
			if (c >= 0xC0 || c <= 0x7F)
			{
				str[p - i] = '\0';
				break ;
			}
			i++;
		}
	}
	return (p - i);
}

int		ft_precision(char *tmp, char *str, int k, char *format)
{
	int		i;
	int		p;

	i = 0;
	p = 0;
	while (tmp[i])
	{
		if (tmp[i] == '.')
			p = ft_atoi(tmp + i + 1);
		i++;
	}
	if (*format == 'p')
		p += 2;
	else if ((ft_strchr(str, '-') || ft_strchr(tmp, '+') || \
		ft_strchr(tmp, ' ')) && (p >= k || p >= (int)ft_strlen(str)) \
		&& *format != 's')
		p += 1;
	if ((*format != 'S' && *format != 's' && (int)ft_strlen(str) > p) || \
		ft_strchr(tmp, '.') == NULL || ((int)ft_strlen(str) < p && \
		(*format == 'S' || *format == 's')))
		p = (int)ft_strlen(str);
	if (*format == 'S' || (*format == 's' && ft_strchr(tmp, 'l')))
		p = ft_precbigs(str, p);
	return (p);
}
