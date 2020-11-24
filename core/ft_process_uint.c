/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:28:00 by melaena           #+#    #+#             */
/*   Updated: 2020/11/23 13:02:29 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		calculate_params(t_format *format, char *num)
{
	int		len;
	int		temp;
	int		temp_w;

	temp_w = format->width;
	temp = format->precision;
	len = ft_strlen(num);
	if (*num == '-')
		len--;
	format->width = ftabs(format->width);
	format->precision = ftsign(format->precision - len);
	if ((handle_flag('+', format->flags) && *num != '-') || *num == '-')
		len++;
	if (handle_flag(' ', format->flags) && *num != '-')
		len++;
	format->width = ftsign(format->width - len - format->precision);
	if (temp < 0)
		format->precision = temp;
	if (temp_w < 0)
		format->width = -(format->width);
}

static	char	*process_lentypes(t_format *format, va_list ap)
{
	unsigned char	hhu;
	unsigned short	hu;

	if (!ft_strcmp(format->type, ""))
		return (ft_itoa_base(va_arg(ap, unsigned int), 10, 1));
	else if (!ft_strcmp(format->type, "ll"))
		return (ft_itoa_base(va_arg(ap, unsigned long long), 10, 1));
	else if (!ft_strcmp(format->type, "l"))
		return (ft_itoa_base(va_arg(ap, unsigned long), 10, 1));
	else if (!ft_strcmp(format->type, "hh"))
	{
		hhu = va_arg(ap, unsigned int);
		hhu = (unsigned char)hhu;
		return (ft_itoa_base(hhu, 10, 1));
	}
	else if (!ft_strcmp(format->type, "h"))
	{
		hu = va_arg(ap, unsigned int);
		hu = (unsigned short)hu;
		return (ft_itoa_base(hu, 10, 1));
	}
	else
		return (0);
}

int				process_uint(t_format *format, va_list ap)
{
	char	*num;
	char	filler;

	format->width = handle_param(format->width, ap);
	format->precision = handle_param(format->precision, ap);
	if (handle_flag('0', format->flags) && format->precision < 0)
		filler = '0';
	else
		filler = ' ';
	format->type[ft_strlen(format->type) - 1] = 0;
	num = process_lentypes(format, ap);
	if (!num)
		return (0);
	if (!ft_strcmp(num, "0") && format->precision == 0)
		*num = 0;
	calculate_params(format, num);
	write_to_out(num, format, filler);
	free(num);
	return (0);
}
