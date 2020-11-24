/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:01:17 by melaena           #+#    #+#             */
/*   Updated: 2020/11/10 23:13:12 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		handle_type(int c, t_format *format, va_list ap)
{
	if (c == 'c')
		process_char(format, ap);
	else if (c == 's')
		process_str(format, ap);
	else if (c == 'p')
		process_ptr(format, ap);
	else if (c == 'd' || c == 'i')
		process_int(format, ap);
	else if (c == 'u')
		process_uint(format, ap);
	else if (c == 'x' || c == 'X')
		process_base(format, ap, 16, c / 90);
	else if (c == '%')
		process_perc(format, ap);
	return (0);
}

int				process_arg(va_list ap, t_format *format)
{
	int		iter;
	char	*type;

	if (!format->type)
		return (0);
	iter = ft_strlen(format->type) - 1;
	type = format->type;
	handle_type(type[iter], format, ap);
	return (format->len);
}
