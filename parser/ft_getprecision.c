/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprecision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:28:50 by melaena           #+#    #+#             */
/*   Updated: 2020/11/13 21:25:18 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

int				ft_isnumeric(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int		isvalid_precision(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int		get_result_p(char *num)
{
	int	result;

	result = ft_atoi(num);
	free(num);
	return (result);
}

int				get_precision(char **str)
{
	char	*ptr;
	int		len;
	char	*num;

	ptr = *str;
	if (!(len = 0) && !*ptr)
		return (-1);
	if (*ptr++ != '.' && !(len = 0))
		return (-1);
	*str = ptr;
	if (*ptr == '*')
	{
		*str = ++ptr;
		return (-2);
	}
	while (ptr[len] && isvalid_precision(ptr[len]))
		++len;
	if (!(num = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	num[len] = 0;
	len = 0;
	while (*ptr && isvalid_precision(*ptr))
		num[len++] = *ptr++;
	*str = ptr;
	return (get_result_p(num));
}
