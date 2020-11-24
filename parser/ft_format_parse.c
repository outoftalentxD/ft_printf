/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:17:04 by melaena           #+#    #+#             */
/*   Updated: 2020/11/21 15:57:06 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

static int			ft_writestr(char **str, int fd)
{
	char	*ptr;
	int		len;

	len = 0;
	ptr = *str;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			break ;
		}
		write(fd, ptr, 1);
		ptr++;
		len++;
	}
	*str = ptr;
	return (len);
}

static void			format_init(t_format *format)
{
	format->flags = 0;
	format->width = -1;
	format->precision = -1;
	format->type = 0;
}

static t_format		*get_format(char **str)
{
	t_format	*format;
	char		*ptr;

	ptr = *str;
	format = (t_format *)malloc(sizeof(t_format) * 1);
	if (!format)
		return (0);
	format_init(format);
	format->flags = get_flags(str);
	format->width = get_width(str);
	format->precision = get_precision(str);
	format->type = get_type(str);
	return (format);
}

t_format			*format_parse(char **str)
{
	char		*ptr;
	t_format	*format;
	int			len;

	len = 0;
	ptr = *str;
	len = ft_writestr(&ptr, 1);
	format = get_format(&ptr);
	format->len = len;
	*str = ptr;
	return (format);
}
