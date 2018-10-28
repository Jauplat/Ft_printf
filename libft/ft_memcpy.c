/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <jauplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:25:39 by jauplat           #+#    #+#             */
/*   Updated: 2018/04/03 16:33:32 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int			i;
	char		*destb;
	const char	*srcb;

	i = 0;
	destb = (char *)dest;
	srcb = (const char *)src;
	while (n != 0 && srcb[i] != '\0')
	{
		destb[i] = srcb[i];
		n--;
		i++;
	}
	destb[i] = '\0';
	return (destb);
}
