/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:45:48 by melaena           #+#    #+#             */
/*   Updated: 2020/10/31 23:31:24 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memset(void *dest, int c, size_t n)
{
	int count;

	count = 0;
	while (n--)
		((unsigned char *)dest)[count++] = c;
	return (dest);
}
