/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:15:28 by jauplat           #+#    #+#             */
/*   Updated: 2018/04/07 19:42:22 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_indic(va_list ap, char **str, char *format, char *tmp)
{
	int		r;
	int		i;

	i = 0;
	r = 0;
	if ((*(format + 1) == '\0' || *format == '%' || ft_isalpha(*format)) && \
		*format != 'h' && *format != 'l' && *format != 'j' && \
		*format != 'z' && *format != ' ')
	{
		r = 1;
		str = ft_decimal(ap, str, tmp, format);
		if (*format == 'p' || (ft_strchr(tmp, '#') && (*format == 'x' || \
			*format == 'X')))
			*str = ft_sharpe(*str, format, tmp);
		else if ((ft_strchr(tmp, '+') || ft_strchr(*str, '-') \
			|| ft_strchr(tmp, ' ')))
			*str = ft_less(*str, tmp, format);
	}
	return (r);
}
