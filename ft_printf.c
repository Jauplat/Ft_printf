/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:14:47 by jauplat           #+#    #+#             */
/*   Updated: 2018/05/21 12:56:30 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_conversion(va_list ap, char **str, char **format)
{
	int		r;
	int		j;
	char	*tmp;

	r = 0;
	j = 0;
	(**format == '%') ? (*format)++ : NULL;
	tmp = ft_strnew(100);
	while ((ft_indic(ap, str, *format, tmp)) == 0 && **format != '\0' && \
		**format != '\n')
	{
		tmp[j] = **format;
		j++;
		(*format)++;
	}
	r += ft_printchar(*str, *format, tmp);
	ft_bzero(*str, ft_strlen(*str));
	ft_strdel(&tmp);
	if (**format)
		(*format)++;
	if (**format == '%' && (*(*format + 1) != '\0' && *(*format + 1) != '\n'))
		r += ft_conversion(ap, str, format);
	return (r);
}

int		ft_formatchr(va_list ap, char **str, char **format)
{
	int		r;

	r = 0;
	r += ft_strlen(*str);
	ft_putstr(*str);
	ft_bzero(*str, ft_strlen(*str));
	if (**format == '%')
		r += ft_conversion(ap, str, format);
	if (**format == '%')
		(*format)++;
	*str = ft_realloc(*str, 500);
	ft_bzero(*str, 499);
	return (r);
}

int		ft_put(int r, char *format, va_list ap)
{
	char		*str;
	int			i;

	i = 0;
	str = ft_strnew(500);
	while (*format)
	{
		if (*format == '%')
		{
			i = 0;
			r += ft_formatchr(ap, &str, &format);
		}
		if (*format == '\0')
			break ;
		str[i] = *format;
		i++;
		format++;
	}
	str[i] = *format;
	r += ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (r);
}

int		ft_printf(char *format, ...)
{
	va_list		ap;
	int			r;

	r = 0;
	va_start(ap, format);
	if (!format)
		return (-1);
	else if ((ft_strchr(format, '%')) == NULL)
	{
		ft_putstr(format);
		return (ft_strlen(format));
	}
	r = ft_put(r, format, ap);
	va_end(ap);
	return (r);
}
