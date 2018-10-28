/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:01:17 by jauplat           #+#    #+#             */
/*   Updated: 2018/04/03 17:33:07 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_uitoa(uintmax_t n, char *tmp)
{
	uintmax_t				tmpn;
	int						len;
	char					*str;

	len = 1;
	tmpn = n;
	while (tmpn /= 10)
		len++;
	str = ft_strnew(len * 2);
	if (n == 0 && ft_strchr(tmp, '.'))
	{
		str[0] = '\0';
		len = 0;
	}
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
