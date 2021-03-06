/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 00:40:56 by ydang             #+#    #+#             */
/*   Updated: 2016/09/24 00:40:57 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;
	char	*d;

	i = 0;
	d = dst;
	while (*(src + i) != '\0')
	{
		*(d + i) = *(src + i);
		i++;
	}
	*(d + i) = '\0';
	return (dst);
}
