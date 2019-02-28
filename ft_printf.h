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

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

/*
** char flags[5] = {-, +, space, 0, #};
*/

typedef struct			s_pf
{
	va_list				args;
	char				*fmt;
	char				*print;
	int					ret;
	char				flags[5];
	int					width;
	int					prec;
	enum {no, hh, h, l,
		ll, L, j, z}	len;
}						t_pf;

/*
** For handling float conversion.
*/

typedef struct			s_fl
{
	char				*res;
	long double			num;
	long double			roun;
	char				*left;
	char				*right;
	int					nlen;
	int					rlen;
}						t_fl;

int						ft_printf(const char *format, ...);
t_pf					*init_specs(char *fmt);
void					reset_specs(t_pf *pf);
int						parse_format(t_pf *pf);

void					style(t_pf *pf);
void					text_colors(t_pf *pf);
void					background_colors(t_pf *pf);

void					parse_flags(t_pf *pf);
void					parse_fwid_prec(t_pf *pf);
void					parse_length(t_pf *pf);
void					parse_convers(t_pf *pf);

void					convert_c(t_pf *pf);
void					convert_percent(t_pf *pf);
void					convert_s(t_pf *pf);
void					convert_di(t_pf *pf);
intmax_t				int_length_mod(t_pf *pf);
int						di_num_len(intmax_t num);
uintmax_t				uint_length_mod(t_pf *pf);
void					convert_u(t_pf *pf);
void					convert_o(t_pf *pf);
void					convert_x(t_pf *pf);
void					convert_p(t_pf *pf);
void					convert_f(t_pf *pf);
long double				fl_round_num(intmax_t i, long double num);
void					fl_res_len(t_pf *pf, t_fl *fl);
int						infnan(t_pf *pf, t_fl *fl);
void					convert_b(t_pf *pf);

char					*pf_strjoin(t_pf *pf, char *s2);
char					*pf_itoa_base(uintmax_t num, int base, t_pf *pf);

/*
** libft functions
*/

void					ft_bzero(void *s, size_t n);
int						ft_isdigit(int c);
void					*ft_memset(void *b, int c, size_t len);
void					ft_putstr(char const *s);
char					*ft_strchr(const char *s, int c);
size_t					ft_strlen(const char *s);
char					*ft_strnew(size_t size);
char					*ft_strsub(char const *s,
							unsigned int start, size_t len);
char					*ft_strncpy(char *dst, const char *src, size_t len);
void					*ft_memmove(void *dest, const void *src, size_t n);
char					*ft_strdup(const char *s1);
int						ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
