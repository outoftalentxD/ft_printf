/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:46:46 by melaena           #+#    #+#             */
/*   Updated: 2020/11/21 22:29:43 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		calculate_params(t_format *format, char *num)
{
	int		len;
	int		temp_w;

	temp_w = format->width;
	format->width = ftabs(format->width);
	len = ft_strlen(num);
	format->precision = ftsign(format->precision - len);
	format->width = ftsign(format->width - len - format->precision - 2);
	if (temp_w < 0)
		format->width = -(format->width);
}

static void		write_ptr(t_format *format, char *num)
{
	if (handle_flag('-', format->flags) || format->width < 0)
	{
		format->width = ftabs(format->width);
		ft_putstrf("0x", format);
		if (format->precision > 0)
			while (format->precision--)
				ft_write("0", format);
		ft_writenum(num, format);
		while (format->width--)
			ft_write(" ", format);
	}
	else
	{
		while (format->width--)
			ft_write(" ", format);
		ft_putstrf("0x", format);
		if (format->precision > 0)
			while (format->precision--)
				ft_write("0", format);
		ft_writenum(num, format);
	}
}

int				process_ptr(t_format *format, va_list ap)
{
	char	*num;

	format->width = handle_param(format->width, ap);
	format->precision = handle_param(format->precision, ap);
	num = ft_itoa_base((va_arg(ap, long long)), 16, 1);
	if (!ft_strcmp(num, "0") && format->precision == 0)
		*num = 0;
	calculate_params(format, num);
	write_ptr(format, num);
	free(num);
	return (0);
}
