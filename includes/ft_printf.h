/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:11:19 by melaena           #+#    #+#             */
/*   Updated: 2020/11/21 16:39:54 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"
# include "ft_parser.h"
# include "ft_struct.h"

int		ft_printf(const char *str, ...);
int		ftmin(int a, int b);
int		ftmax(int a, int b);
int		ftsign(int a);
int		ftabs(int a);
int		ft_isnumeric(int c);
int		handle_param(int p, va_list ap);
int		handle_flag(int flag, char *flags);
int		process_arg(va_list ap, t_format *format);
int		process_char(t_format *format, va_list ap);
int		process_str(t_format *format, va_list ap);
int		process_int(t_format *format, va_list ap);
int		process_base(t_format *format, va_list ap, int base, int reg);
int		process_ptr(t_format *format, va_list ap);
int		process_perc(t_format *format, va_list ap);
int		process_uint(t_format *format, va_list ap);

void	ft_write(char *ptr, t_format *format);
void	ft_putstrf(char *ptr, t_format *format);
void	ft_writenum(char *num, t_format *format);
void	ft_writesign(char **num, t_format *format);
int		write_to_out(char *num, t_format *format, char filler);
char	*ft_itoa_base(unsigned long long n, int base, int reg);

#endif
