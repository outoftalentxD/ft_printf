/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:28:27 by melaena           #+#    #+#             */
/*   Updated: 2020/11/13 20:58:54 by melaena          ###   ########.fr       */
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

static int		handle_precision(int prec, va_list ap, int opt)
{
	int	n;

	if (prec != -2)
		return (prec);
	n = va_arg(ap, int);
	if (n < 0 && opt == 1)
		n = -1;
	return (n);
}

static void		ft_write_to_out(char *ptr, t_format *format, int len, char flag)
{
	if (flag == '-' || format->width < 0)
	{
		format->width = ftabs(format->width);
		while (len-- && *ptr)
			ft_write(ptr++, format);
		while (format->width--)
			ft_write(" ", format);
		return ;
	}
	while (format->width--)
		ft_write(&flag, format);
	while (len-- && *ptr)
		ft_write(ptr++, format);
	return ;
}

int				process_str(t_format *format, va_list ap)
{
	char	flag;
	int		len;
	char	*ptr;

	flag = get_flag(format->flags);
	format->width = handle_precision(format->width, ap, 0);
	format->precision = handle_precision(format->precision, ap, 1);
	ptr = va_arg(ap, char *);
	if (!ptr)
		ptr = ft_strdup("(null)");
	len = ft_strlen(ptr);
	if (format->precision == -1)
		format->precision = len;
	len = ftmin(len, format->precision);
	if (format->width >= 0)
		format->width = ftmax(len, format->width) - len;
	else
		format->width = -(ftmax(len, ftabs(format->width)) - len);
	ft_write_to_out(ptr, format, len, flag);
	return (0);
}
