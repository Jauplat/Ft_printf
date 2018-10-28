/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 14:37:56 by jauplat           #+#    #+#             */
/*   Updated: 2018/04/07 16:02:23 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_len(va_list ap, char *tmp, char *format)
{
	char			*s;

	if (*format == 's' || *format == 'S')
		s = ft_string(ap, format, tmp);
	else if (*format == 'p')
		s = ft_pointer(ap, tmp);
	else if (*format == 'x' || *format == 'X')
		s = ft_hex(ap, tmp, format);
	else if (*format == 'o' || *format == 'O')
		s = ft_octal(ap, tmp, format);
	else if (*format == 'u' || *format == 'U')
		s = ft_uitoa(ft_udeci(ap, tmp, format), tmp);
	else if (*format == 'd' || *format == 'i' || *format == 'D')
		s = ft_itoa(ft_deci(ap, tmp, format));
	else if (*format == 'c' || *format == 'C')
		s = ft_char(ap, format, tmp);
	else
	{
		s = ft_strnew(20);
		s[0] = *format;
	}
	if ((s[0] == '0' && s[1] == '\0' && ft_strchr(tmp, '.')) && \
		(*format == 'i' || *format == 'D' || *format == 'd'))
		s[0] = '\0';
	return (s);
}

intmax_t		ft_deci(va_list ap, char *tmp, char *format)
{
	char			*s;
	intmax_t		i;

	i = 0;
	if (ft_strchr(tmp, 'j'))
		i = va_arg(ap, intmax_t);
	else if (((s = ft_strchr(tmp, 'l')) && s[1] == 'l') || ((*format == 'D' \
		|| (*format == 'O' && ft_strchr(tmp, 'l'))) && ft_strchr(tmp, 'l')))
		i = va_arg(ap, long long);
	else if (ft_strchr(tmp, 'z'))
		i = va_arg(ap, size_t);
	else if (ft_strchr(tmp, 'l') || *format == 'D' || *format == 'O')
		i = va_arg(ap, long);
	else if ((s = ft_strchr(tmp, 'h')) && s[1] != 'h')
		i = (short)va_arg(ap, int);
	else if ((s = ft_strchr(tmp, 'h')) && s[1] == 'h')
		i = (char)va_arg(ap, int);
	else
		i = va_arg(ap, int);
	return (i);
}

uintmax_t		ft_udeci(va_list ap, char *tmp, char *format)
{
	char				*s;
	uintmax_t			i;

	if (ft_strchr(tmp, 'j') || *format == 'O')
		i = va_arg(ap, uintmax_t);
	else if (ft_strchr(tmp, 'l') || (*format == 'U' || *format == 'O'))
		i = va_arg(ap, unsigned long long);
	else if (ft_strchr(tmp, 'z'))
		i = va_arg(ap, size_t);
	else if ((s = ft_strchr(tmp, 'h')) && s[1] != 'h')
		i = (unsigned short)va_arg(ap, unsigned int);
	else if ((s = ft_strchr(tmp, 'h')) && s[1] == 'h')
		i = (unsigned char)va_arg(ap, unsigned int);
	else
		i = va_arg(ap, unsigned int);
	return (i);
}
