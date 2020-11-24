/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_prec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:17:05 by melaena           #+#    #+#             */
/*   Updated: 2020/11/23 12:23:08 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		get_flag(char *flags)
{
	char	res;

	res = ' ';
	while (*flags)
	{
		if (*flags == '-')
			return (res = '-');
		if (*flags == '0')
			res = '0';
		flags++;
	}
	return (res);
}

static int		handle_width(int w, va_list ap)
{
	int	n;

	if (w == -2)
		return (n = va_arg(ap, int));
	else
		return (w);
}

int				process_perc(t_format *format, va_list ap)
{
	int		width;
	char	flag;
	char	c;

	width = handle_width(format->width, ap);
	format->width = width;
	width = ftabs(width);
	format->precision = handle_width(format->precision, ap);
	width = ftmax(1, width);
	c = '%';
	flag = get_flag(format->flags);
	if (flag == '-' || format->width < 0)
	{
		ft_write(&c, format);
		while (width-- - 1)
			ft_write(" ", format);
		return (0);
	}
	while (width-- - 1)
		ft_write(&flag, format);
	ft_write(&c, format);
	return (0);
}
