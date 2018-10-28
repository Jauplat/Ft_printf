/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:01:17 by jauplat           #+#    #+#             */
/*   Updated: 2018/03/31 15:52:31 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(unsigned long long n)
{
	unsigned long long		tmp;
	unsigned long long		tmpn;
	int						len;
	int						negative;
	char					*str;

	len = 1;
	negative = 0;
	ft_isnegative(&n, &negative);
	tmpn = n;
	tmp = n;
	while (tmpn /= 10)
		len++;
	len += negative;
	str = ft_strnew(len * 2);
	while (len--)
	{
		str[len] = tmp % 10 + '0';
		tmp = tmp / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
