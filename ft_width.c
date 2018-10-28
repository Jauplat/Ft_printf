/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:40:36 by jauplat           #+#    #+#             */
/*   Updated: 2018/04/05 12:55:16 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_width(char **str, int k[2], char *format, char *tmp)
{
	char	*width;

	if ((k[1] != 0 || *format == 's' || *format == 'S') && *format != 'c' \
		&& *format != 'C')
		k[1] = ft_takepos(str, format, k, tmp);
	width = ft_strnew(k[0] + k[1]);
	if (k[1] < k[0])
	{
		if (ft_check(tmp, format))
			ft_memset(width, '0', (k[0] - (int)ft_strlen(*str)));
		else
			ft_memset(width, ' ', (k[0] - (int)ft_strlen(*str)));
	}
	if (k[0] > k[1])
	{
		if (ft_strchr(tmp, '-') == NULL)
			*str = ft_strjoin(width, *str);
		if (ft_strchr(tmp, '-'))
			*str = ft_strjoin(*str, width);
	}
	if (k[0] <= k[1])
		ft_strdel(&width);
	return (*str);
}

int		ft_check(char *tmp, char *format)
{
	if ((tmp[0] == '0' || (tmp[1] == '0' && tmp[0] != '.' && \
		!ft_isdigit(tmp[0]))) && ((ft_strchr(tmp, '.') == NULL && \
		(*format == 'd' || *format == 'D' || *format == 'U' || \
		*format == 'i' || *format == 'u' || *format == 'x' || \
		*format == 'X' || *format == 'p' || *format == 'O' || \
		*format == 'o')) || ((ft_isalpha(*format) || *format == '%') && \
		(*format != 'd' && *format != 'D' && *format != 'u' && \
		*format != 'U' && *format != 'x' && *format != 'X' && \
		*format != 'i' && *format != 'o' && *format != 'O' && \
		*format != 'p'))) && ft_strchr(tmp, '-') == NULL)
		return (1);
	return (0);
}
