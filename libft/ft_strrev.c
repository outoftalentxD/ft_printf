/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:58:49 by melaena           #+#    #+#             */
/*   Updated: 2020/11/12 19:01:02 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *ptr)
{
	int		len;
	int		count;
	char	temp;

	count = 0;
	len = ft_strlen(ptr);
	while (count < len / 2)
	{
		temp = ptr[count];
		ptr[count] = ptr[len - count - 1];
		ptr[len - count - 1] = temp;
		count++;
	}
	return ;
}
