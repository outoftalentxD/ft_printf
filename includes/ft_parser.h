/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:49:44 by melaena           #+#    #+#             */
/*   Updated: 2020/11/21 16:40:40 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include <stdlib.h>
# include "ft_printf.h"
# include "ft_struct.h"

int				is_primetype(int c);
int				is_doublelentypes(char *str, int c);
int				ft_isflag(int c);
int				check_prec(char **str);
int				check_type(char **str);
char			*get_flags(char **str);
int				get_width(char **str);
int				get_precision(char **str);
char			*get_type(char **str);
t_format		*format_parse(char **str);

#endif
