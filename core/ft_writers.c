/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:12:52 by melaena           #+#    #+#             */
/*   Updated: 2020/11/21 22:33:17 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_writenum(char *num, t_format *format)
{
	format->precision = ftsign(format->precision);
	while (format->precision--)
		ft_write("0", format);
	ft_putstrf(num, format);
}

int				write_to_out(char *num, t_format *format, char filler)
{
	if (handle_flag('-', format->flags) || format->width < 0)
	{
		format->width = ftabs(format->width);
		ft_writesign(&num, format);
		ft_writenum(num, format);
		while (format->width--)
			ft_write(" ", format);
	}
	else
	{
		if (filler == '0')
			ft_writesign(&num, format);
		while (format->width--)
			ft_write(&filler, format);
		if (filler == ' ')
			ft_writesign(&num, format);
		ft_writenum(num, format);
	}
	return (0);
}

void			ft_writesign(char **num, t_format *format)
{
	if (handle_flag('+', format->flags) && **num != '-')
		ft_write("+", format);
	if (handle_flag(' ', format->flags) && **num != '-')
		ft_write(" ", format);
	if (**num == '-')
		ft_write((*num)++, format);
}

void			ft_write(char *ptr, t_format *format)
{
	format->len++;
	write(1, ptr, 1);
}

void			ft_putstrf(char *ptr, t_format *format)
{
	int		count;
	char	symb;

	count = 0;
	if (!ptr)
	{
		write(1, "(null)", 6);
		format->len += 6;
	}
	else
	{
		while (ptr[count])
		{
			symb = ptr[count++];
			write(1, &symb, 1);
			format->len += 1;
		}
	}
}
