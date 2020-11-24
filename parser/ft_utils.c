/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:54:03 by melaena           #+#    #+#             */
/*   Updated: 2020/11/23 13:00:16 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

int			check_type(char **str)
{
	char *ptr;

	ptr = *str;
	while (*ptr)
	{
		if (is_primetype(*ptr))
			if (*ptr == 's' || *ptr == 'c' || *ptr == '%')
				return (1);
		ptr++;
	}
	return (0);
}

int			check_prec(char **str)
{
	char	*ptr;

	ptr = *str;
	while (*ptr && *ptr != '%')
	{
		if (*ptr == '.')
		{
			ptr++;
			if (*ptr == '*')
				return (0);
			else
				return (1);
		}
		ptr++;
	}
	return (0);
}

int			handle_flag(int flag, char *flags)
{
	while (*flags)
		if (flag == *flags++)
			return (1);
	return (0);
}

static char	*fill_num(char *num, unsigned long long n,
			unsigned long long pow, int base)
{
	char	sym;
	int		count;

	count = 0;
	while (pow >= 1)
	{
		sym = n / pow + '0';
		if (sym > '9')
			sym += 7;
		num[count++] = sym;
		n -= n / pow * pow;
		pow /= base;
	}
	return (num);
}

char		*ft_itoa_base(unsigned long long n, int base, int reg)
{
	char						*num;
	unsigned long long			pow;
	int							len;

	len = 1;
	pow = 1;
	if (reg == 1)
		reg = 32;
	while (pow <= n / base && ++len != 1)
		pow *= base;
	if (!(num = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	num[len] = 0;
	num = fill_num(num, n, pow, base);
	while (--len != -1)
	{
		if (num[len] > '9')
			num[len] += reg;
	}
	return (num);
}
