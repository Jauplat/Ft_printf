/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:55:33 by jauplat           #+#    #+#             */
/*   Updated: 2018/03/31 17:36:12 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_octal(va_list ap, char *tmp, char *format)
{
	char				*s;
	int					i;
	uintmax_t			nb;

	nb = ft_udeci(ap, tmp, format);
	i = ft_lenoctal(nb, tmp);
	s = ft_octalpos(nb, i, tmp);
	return (s);
}

int		ft_lenoctal(uintmax_t nbr, char *tmp)
{
	int				i;
	uintmax_t		octal;

	i = 0;
	if ((intmax_t)nbr == LONG_MIN)
		i = 1;
	octal = 8;
	while (nbr > octal)
	{
		nbr /= octal;
		i++;
	}
	if (i == 15 && (ft_strchr(tmp, 'l') || ft_strchr(tmp, 'j') \
		|| ft_strchr(tmp, 'z')))
		i = 16;
	return (i);
}

char	*ft_octalpos(uintmax_t nbr, int i, char *tmp)
{
	char	*s;

	if (ft_strchr(tmp, '#'))
		i++;
	s = ft_strnew(i + 1);
	if (ft_strchr(tmp, '#'))
		s[0] = '0';
	while ((!ft_strchr(tmp, '#') && i != -1) || (ft_strchr(tmp, '#') && i != 0))
	{
		s[i] = nbr % 8 + '0';
		nbr = nbr / 8;
		i--;
	}
	i = 0;
	if ((s[i] == '0' || s[i] == '\0') && s[i + 1] == '0' && s[i + 2] == '\0')
		s[i + 1] = '\0';
	else if (s[i] == '0' && s[i + 1] == '\0' && ft_strchr(tmp, '.'))
		s[i] = '\0';
	return (s);
}
