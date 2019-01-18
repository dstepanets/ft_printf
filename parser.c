/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:59:07 by dstepane          #+#    #+#             */
/*   Updated: 2019/01/13 18:59:09 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_convers(char *fmt, t_specs *specs)
{
	char c[2];

    c[1] = '\0';
	if (*fmt == '%')
	{
		specs->convers = '%';
		convert_procent(specs);
	}
	else if (*fmt == 'c')
	{
		specs->convers = 'c';
		convert_c(specs);
	}
	else
	{
		c[0] = *fmt;
		specs->res_str = ft_strjoin(specs->res_str, c);
	}
	if (*(fmt + 1) != '\0')
		print_format(++fmt, specs);
}

void		parse_length(char *fmt, t_specs *specs)
{
	if (*fmt == 'h' || *fmt == 'l' || *fmt == 'L')
	{
		if (*fmt == 'h' && *(fmt + 1) == 'h')
		{
			specs->len = hh;
			fmt++;
		}
		else if (*fmt == 'h' && *(fmt + 1) != 'h')
			specs->len = h;
		if (*fmt == 'l' && *(fmt + 1) == 'l')
		{
			specs->len = ll;
			fmt++;
		}
		else if (*fmt == 'l' && *(fmt + 1) != 'l')
			specs->len = l;
		if (*fmt == 'L')
			specs->len = L;
		fmt++;
	}
	parse_convers(fmt, specs);
}

void		parse_precision(char *fmt, t_specs *specs)
{
	if (*fmt == '.')
	{
		fmt++;
		specs->prec = 0;
		while (ft_isdigit(*fmt))
			specs->prec = specs->prec * 10 + (*fmt++ - '0');
	}
	parse_length(fmt, specs);
}

void		parse_fwidth(char *fmt, t_specs *specs)
{
	while (ft_isdigit(*fmt))
		specs->width = specs->width * 10 + (*fmt++ - '0');
	parse_precision(fmt, specs);
}

void		parse_flags(char *fmt, t_specs *specs)
{
	while (fmt && (*fmt == '-' || *fmt == '+' || *fmt == ' ' || *fmt == '0' || *fmt == '#'))
	{
		if (*fmt == '-')
			specs->flags[0] = '-';
		else if (*fmt == '+')
			specs->flags[1] = '+';
		else if (*fmt == ' ')
			specs->flags[2] = 's';
		else if (*fmt == '0')
			specs->flags[3] = '0';
		else if (*fmt == '#')
			specs->flags[4] = '#';
		fmt++;
	}
	parse_fwidth(fmt, specs);
}
