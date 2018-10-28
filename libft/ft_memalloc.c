/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:54:52 by jauplat           #+#    #+#             */
/*   Updated: 2017/11/13 22:16:03 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *str;

	if (!(str = (unsigned char *)malloc(sizeof(unsigned char) * size)))
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
