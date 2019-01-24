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

# include <stdio.h>   ///TO DELETE!!!!!!!!!!!

/*
** char flags[5] = {-, +, space, 0, #};
*/

typedef struct					s_pf
{
	va_list						args;
	char						*fmt;
	char						*res_str;
	int							ret;
	char						flags[5];
	int							width;
	int							prec;
	enum {no, hh, h, l, ll, L}	len;
	char						convers;	//maybe no need in it?
}								t_pf;

int						ft_printf(const char *format, ...);
t_pf					*init_specs(char *fmt);
void					reset_specs(t_pf *pf);
int						parse_format(t_pf *pf);

void					parse_flags(t_pf *pf);
void					parse_fwidth(t_pf *pf);
void					parse_precision(t_pf *pf);
void					parse_length(t_pf *pf);
void					parse_convers(t_pf *pf);

void					convert_c(t_pf *pf);
void					null_char_helper(t_pf *pf);
void					convert_procent(t_pf *pf);
void					convert_s(t_pf *pf);
/*
** libft functions
*/

void	ft_bzero(void *s, size_t n);
int		ft_isdigit(int c);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putstr(char const *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2, t_pf *pf);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
char	*ft_strsub(char const *s, unsigned int start, size_t len);

/*
** TEMP
*/
void	ft_putstr_fd(char const *s, int fd);
void	ft_memdel(void **ap);

#endif
