/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:49:20 by jauplat           #+#    #+#             */
/*   Updated: 2018/03/13 14:26:28 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		lens1;
	int		lens2;
	char	*str;

	lens1 = ft_strlen((char *)s1);
	lens2 = ft_strlen((char *)s2);
	if (!(str = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	if (s1)
		ft_strdel(&s1);
	if (s2)
		ft_strdel(&s2);
	return (str);
}
