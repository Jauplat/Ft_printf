/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 21:36:26 by jauplat           #+#    #+#             */
/*   Updated: 2018/04/07 16:04:32 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_pointer(va_list ap, char *tmp)
{
	char					*s;
	int						len;
	unsigned long long		n;

	n = (unsigned long long)va_arg(ap, unsigned long long);
	len = ft_lenhexa(n, tmp);
	s = ft_hexpoint(n, len);
	return (s);
}
