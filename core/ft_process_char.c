/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:06:04 by melaena           #+#    #+#             */
/*   Updated: 2020/11/23 12:23:39 by melaena          ###   ########.fr       */
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

int				process_char(t_format *format, va_list ap)
{
	int		width;
	char	flag;
	char	c;

	width = handle_width(format->width, ap);
	format->width = width;
	format->precision = handle_width(format->precision, ap);
	width = ftabs(width);
	width = ftmax(1, width);
	c = va_arg(ap, int);
	flag = get_flag(format->flags);
	if (flag == '-' || format->width < 0)
	{
		write(1, &c, 1);
		format->len++;
		while (width-- - 1 && format->len++ != -1)
			write(1, " ", 1);
		return (format->len);
	}
	while (width-- - 1 && format->len++ != -1)
		write(1, &flag, 1);
	write(1, &c, 1);
	format->len++;
	return (format->len);
}
