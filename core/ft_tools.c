/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:55:14 by melaena           #+#    #+#             */
/*   Updated: 2020/11/23 12:39:52 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_isflag(int c)
{
	if (c == '-' ||
		c == '+' ||
		c == ' ' ||
		c == '#' ||
		c == '0')
		return (1);
	else
		return (0);
}

int		ftmin(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int		ftmax(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int		ftsign(int a)
{
	if (a < 0)
		a = 0;
	return (a);
}

int		ftabs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
