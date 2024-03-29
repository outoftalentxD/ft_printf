/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:03:22 by melaena           #+#    #+#             */
/*   Updated: 2020/11/12 18:39:07 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	res;
	size_t	dlen;

	dlen = ft_strlen(dest);
	if (destsize <= dlen)
		return (destsize + ft_strlen(src));
	else
	{
		res = dlen + ft_strlen(src);
		dest += dlen;
		while (*src && destsize-- - dlen > 1)
			*dest++ = *src++;
		*dest = 0;
		return (res);
	}
}
