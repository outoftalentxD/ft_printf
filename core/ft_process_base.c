/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 23:44:06 by melaena           #+#    #+#             */
/*   Updated: 2020/11/23 13:05:18 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				handle_param(int p, va_list ap)
{
	if (p == -2)
		return (va_arg(ap, int));
	else
		return (p);
}

static void		calculate_params(t_format *format, char *num)
{
	int		len;
	int		temp;
	int		temp_w;

	temp_w = format->width;
	temp = format->precision;
	len = ft_strlen(num);
	format->width = ftabs(format->width);
	format->precision = ftsign(format->precision - len);
	format->width = ftsign(format->width - len - format->precision);
	if (temp < 0)
		format->precision = temp;
	if (temp_w < 0)
		format->width = -(format->width);
}

static	char	*process_lentypes(t_format *format, va_list ap,
				int base, int reg)
{
	unsigned char	hhx;
	unsigned int	hx;

	if ((!ft_strcmp(format->type, "x")) || !ft_strcmp(format->type, "X"))
		return (ft_itoa_base(va_arg(ap, unsigned int), base, reg));
	else if (!ft_strcmp(format->type, "llx") || !ft_strcmp(format->type, "llX"))
		return (ft_itoa_base(va_arg(ap, unsigned long long), base, reg));
	else if (!ft_strcmp(format->type, "lx") || !ft_strcmp(format->type, "lX"))
		return (ft_itoa_base(va_arg(ap, unsigned long), base, reg));
	else if (!ft_strcmp(format->type, "hhx") || !ft_strcmp(format->type, "hhX"))
	{
		hhx = va_arg(ap, unsigned int);
		hhx = (unsigned char)hhx;
		return (ft_itoa_base(hhx, base, reg));
	}
	else if (!ft_strcmp(format->type, "hx") || !ft_strcmp(format->type, "hX"))
	{
		hx = va_arg(ap, unsigned int);
		hx = (unsigned short)hx;
		return (ft_itoa_base(hx, base, reg));
	}
	else
		return (0);
}

static void		ft_write_out_base(t_format *format, char *num, char filler)
{
	if (handle_flag('-', format->flags) || format->width < 0)
	{
		format->width = ftabs(format->width);
		ft_writenum(num, format);
		while (format->width--)
			ft_write(" ", format);
	}
	else
	{
		while (format->width--)
			ft_write(&filler, format);
		ft_writenum(num, format);
	}
}

int				process_base(t_format *format, va_list ap, int base, int reg)
{
	char	*num;
	char	filler;

	filler = ' ';
	format->width = handle_param(format->width, ap);
	format->precision = handle_param(format->precision, ap);
	if (handle_flag('0', format->flags) && format->precision < 0)
		filler = '0';
	num = process_lentypes(format, ap, base, reg);
	if (!num)
		return (0);
	if (!ft_strcmp(num, "0") && format->precision == 0)
		*num = 0;
	calculate_params(format, num);
	ft_write_out_base(format, num, filler);
	free(num);
	return (0);
}
