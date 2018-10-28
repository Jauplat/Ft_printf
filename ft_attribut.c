/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attribut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:53:48 by jauplat           #+#    #+#             */
/*   Updated: 2018/04/07 19:41:22 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	**ft_decimal(va_list ap, char **str, char *tmp, char *format)
{
	int			k[2];
	char		*s;

	k[0] = ft_atoi(tmp);
	s = ft_len(ap, tmp, format);
	if (!ft_strchr(s, '-'))
		*str[0] = ft_addop(tmp, format, k[0], &s);
	*str = ft_strjoin(*str, s);
	k[1] = ft_precision(tmp, *str, k[0], format);
	if ((ft_strchr(tmp, '#') && *str[0] != '0' && *str[0] != '\0' && \
		(*format == 'x' || *format == 'X')))
		k[1] += 2;
	if (k[0] + k[1] > (int)ft_strlen(*str))
		*str = ft_realloc(*str, (k[0] + k[1]));
	if (k[0] > (int)ft_strlen(*str) || k[1] > (int)ft_strlen(*str) || \
		*format == 's' || *format == 'S')
		*str = ft_width(str, k, format, tmp);
	return (str);
}

char	ft_addop(char *tmp, char *format, int k, char **s)
{
	char	c;

	c = '\0';
	if (*format == 'd' || *format == 'i' || *format == 'D')
	{
		if (ft_strchr(tmp, '+'))
			c = '+';
		if (ft_strchr(tmp, ' ') && ft_strchr(tmp, '+') == NULL && k == 0)
			c = ' ';
	}
	if (*s[0] == '\n')
	{
		c = '\n';
		*s[0] = '\0';
	}
	return (c);
}

char	*ft_less(char *str, char *tmp, char *format)
{
	int		i;
	char	c;

	i = 0;
	c = '+';
	if (*format != 'd' && *format != 'i' && *format != 'D')
		return (str);
	while (ft_isdigit(str[i]) == 0 && (int)ft_strlen(str) > i + 1)
		i++;
	while (str[i])
	{
		if (ft_strchr(str, '-'))
			c = '-';
		if (str[0] == '0')
			str[0] = c;
		if (str[i] == '0' && str[i - 1] == ' ' && str[i + 1])
			str[i] = c;
		if (str[i])
			i++;
		if ((str[i] == c) && (ft_isdigit(str[i - 1]) || str[i - 1] == c))
			str[i] = '0';
	}
	return (ft_space(str, tmp));
}

char	*ft_space(char *str, char *tmp)
{
	int		i;

	i = 0;
	if (ft_strchr(tmp, ' ') && ft_strchr(tmp, '+') == NULL && \
		ft_strchr(str, '-') == NULL)
	{
		while (str[i] != '+' && str[i])
			i++;
		if (str[i] == '+')
			str[i] = ' ';
	}
	return (str);
}

char	*ft_sharpe(char *str, char *format, char *tmp)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while ((str[j] == '0' || str[j] == ' '))
		j++;
	if (str[j] == '\0' && (*format == 'x' || *format == 'X'))
		return (str);
	else if (str[j] == 'x')
		str[j] = '0';
	while (str[i] != '0')
		i++;
	i++;
	if (*format == 'x' || *format == 'p')
		str[i] = 'x';
	if (*format == 'X')
		str[i] = 'X';
	if (*format == 'p' && ft_strchr(tmp, '.') && ft_strlen(str) == 3)
		str[2] = '\0';
	return (str);
}
