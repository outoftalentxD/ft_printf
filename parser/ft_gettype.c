/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:46:40 by melaena           #+#    #+#             */
/*   Updated: 2020/11/23 12:24:12 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

static int		is_lentypes(int c)
{
	if (c == 'l')
		return (1);
	if (c == 'h')
		return (1);
	return (0);
}

static int		valid_type(char *type)
{
	int		len;

	len = ft_strlen(type);
	if (len == 1 && is_primetype(*type))
		return (1);
	else if (len == 2 && is_primetype(type[1]) &&
			is_lentypes(type[0]))
		return (1);
	else if (len == 3 && is_primetype(type[2]) &&
			is_doublelentypes(type, type[2]))
		return (1);
	else
		return (0);
}

char			*get_type(char **str)
{
	int		len;
	char	*ptr;
	char	*type;

	ptr = *str;
	if (!*ptr)
		return (0);
	len = 0;
	while (ptr[len] && !is_primetype(ptr[len]))
		len++;
	if (len > 2)
		return (0);
	if (!(type = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	type[len] = ptr[len];
	type[++len] = 0;
	*str = ptr + len;
	while (--len + 1)
		type[len] = ptr[len];
	if (!valid_type(type))
		return (0);
	return (type);
}
