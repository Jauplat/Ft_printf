/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnegative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:35:46 by jauplat           #+#    #+#             */
/*   Updated: 2018/03/11 17:14:31 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_isnegative(unsigned long long *n, int *negative)
{
	if ((long long)*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}
