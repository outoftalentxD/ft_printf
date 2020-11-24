/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:38:23 by melaena           #+#    #+#             */
/*   Updated: 2020/11/13 21:24:43 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

static int		isvalid_width(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int		get_result_w(char *num)
{
	int result;

	result = ft_atoi(num);
	free(num);
	return (result);
}

static void		process_zeros_case(char **str)
{
	char	*ptr;

	ptr = *str;
	while (*(--ptr) == '0')
		;
	ptr++;
	*str = ptr;
}

int				get_width(char **str)
{
	char	*ptr;
	int		len;
	char	*num;
	int		iter;

	len = 0;
	ptr = *str;
	if (!*ptr)
		return (0);
	if (*ptr == '*')
	{
		*str = ptr + 1;
		return (-2);
	}
	process_zeros_case(&ptr);
	while (ptr[len] && isvalid_width(ptr[len]))
		len++;
	if (!(num = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	num[len] = 0;
	iter = -1;
	while (*ptr && isvalid_width(*ptr))
		num[++iter] = *ptr++;
	*str = ptr;
	return (get_result_w(num));
}
