/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:24:14 by melaena           #+#    #+#             */
/*   Updated: 2020/11/13 20:50:52 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	emancipate_format(t_format *format)
{
	free(format->type);
	free(format->flags);
	free(format);
	return (0);
}

int			ft_printf(const char *str, ...)
{
	t_format	*format;
	char		*ptr;
	va_list		ap;
	int			len;

	va_start(ap, str);
	ptr = (char *)str;
	len = 0;
	while (*ptr)
	{
		format = format_parse(&ptr);
		if (format->type)
			len += process_arg(ap, format);
		if (!format->type)
		{
			len += format->len;
			emancipate_format(format);
			break ;
		}
		emancipate_format(format);
	}
	va_end(ap);
	return (len);
}
