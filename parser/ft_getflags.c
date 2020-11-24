/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfuncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:45:36 by melaena           #+#    #+#             */
/*   Updated: 2020/11/23 12:23:20 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

static char		*process_flag_behaviour(char *str, char **s)
{
	char	*ptr;
	int		pflag;
	int		mflag;
	int		len;

	ptr = str;
	while (*ptr)
	{
		if (*ptr == '+')
			pflag = 1;
		if (*ptr == '-')
			mflag = 1;
		ptr++;
	}
	if (check_prec(s) == 1)
		mflag = 1;
	if (check_type(s) == 1)
		mflag = 0;
	ptr = str - 1;
	len = -1;
	while (*(++ptr) && ++len != -1)
		if ((*ptr == ' ' && pflag == 1) || (*ptr == '0' && mflag == 1))
			*ptr = 'N';
	ptr = str;
	return (str);
}

char			*get_flags(char **str)
{
	char	*ptr;
	int		len;
	char	*flags;

	len = 0;
	ptr = *str;
	while (ptr[len] && ptr[len] != '%' && ft_isflag(ptr[len]))
		len++;
	flags = (char *)malloc(sizeof(char) * (len + 1));
	if (!flags)
		return (0);
	flags[len] = 0;
	ptr = *str;
	*str += len;
	while (--len != -1)
		flags[len] = ptr[len];
	flags = process_flag_behaviour(flags, str);
	return (flags);
}
