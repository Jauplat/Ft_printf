/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:55:33 by jauplat           #+#    #+#             */
/*   Updated: 2018/04/02 16:38:18 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_hex(va_list ap, char *tmp, char *format)
{
	char			*s;
	int				i;
	uintmax_t		nb;

	nb = ft_udeci(ap, tmp, format);
	i = ft_lenhexa(nb, tmp);
	i -= 1;
	s = ft_hexpos(nb, i, tmp);
	i = -1;
	while (*format == 'X' && i++ != (int)ft_strlen(s))
		s[i] = ft_toupper(s[i]);
	return (s);
}

int		ft_lenhexa(uintmax_t nbr, char *tmp)
{
	int				i;
	uintmax_t		hexa;

	i = 0;
	hexa = 16;
	while (nbr > 0)
	{
		nbr /= hexa;
		i++;
	}
	if (i == 0)
		i = 1;
	if (i == 15 && (ft_strchr(tmp, 'l') || ft_strchr(tmp, 'j') \
		|| ft_strchr(tmp, 'z')))
		i = 16;
	return (i);
}

char	*ft_hexpos(uintmax_t nbr, int i, char *tmp)
{
	char		*s;
	int			x;

	x = i + 1;
	s = ft_strnew(i + 1);
	if (nbr == 0)
		s[0] = '0';
	while (nbr > 0)
	{
		if (nbr % 16 <= 9)
			s[i] = nbr % 16 + '0';
		else
			s[i] = nbr % 16 + 'W';
		nbr = nbr / 16;
		i--;
	}
	if (s[0] == '0' && s[1] == '\0' && ft_strchr(tmp, '.'))
		s[0] = '\0';
	return (s);
}

char	*ft_hexpoint(uintmax_t nbr, int i)
{
	char		*s;
	int			x;

	x = i + 1;
	s = ft_strnew(x + 1);
	if (nbr == 0)
		s[2] = '0';
	while (nbr > 0)
	{
		if (nbr % 16 <= 9)
			s[x] = nbr % 16 + '0';
		else
			s[x] = nbr % 16 + 'W';
		nbr = nbr / 16;
		x--;
	}
	s[1] = 'x';
	s[0] = '0';
	return (s);
}
