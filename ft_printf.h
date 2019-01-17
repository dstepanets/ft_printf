/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:01:58 by dstepane          #+#    #+#             */
/*   Updated: 2018/12/25 16:02:00 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include <stdio.h>   ///TO DELETE!!!!!!!!!!!

/*
** char flags[5] = {-, +, space, 0, #};
*/

typedef struct					s_specs
{
	va_list						args;
	char						*res_str;
	char						flags[5];
	int							width;
	int							prec;
	enum {no, hh, h, l, ll, L}	len;
	char						convers;	//maybe no need in it?
}								t_specs;

int						ft_printf(const char *format, ...);
t_specs					*init_specs(void);
void					reset_specs(t_specs *specs);
int						print_format(char *fmt, t_specs *specs);

void					parse_flags(char *fmt, t_specs *specs);
void					parse_fwidth(char *fmt, t_specs *specs);
void					parse_precision(char *fmt, t_specs *specs);
void					parse_length(char *fmt, t_specs *specs);
void					parse_convers(char *fmt, t_specs *specs);

void					convert_c(t_specs *specs);
void					convert_procent(t_specs *specs);

#endif
