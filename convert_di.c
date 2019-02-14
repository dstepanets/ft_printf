/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:13:57 by dstepane          #+#    #+#             */
/*   Updated: 2019/02/10 17:14:01 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t		int_length_mod(t_pf *pf)
{
	intmax_t	num;

	num = 0;
	*pf->fmt == 'D' ? pf->len = l : 0;
	if (pf->len == no)
		num = (int)(va_arg(pf->args, int));
	else if (pf->len == hh)
		num = (signed char)(va_arg(pf->args, int));
	else if (pf->len == h)
		num = (short)(va_arg(pf->args, int));
	else if (pf->len == l)
		num = (long)(va_arg(pf->args, long int));
	else if (pf->len == ll)
		num = (long long)(va_arg(pf->args, long long int));
	else if (pf->len == j)
		num = (intmax_t)(va_arg(pf->args, intmax_t));
	else if (pf->len == z)
		num = (size_t)(va_arg(pf->args, size_t));
	return(num);
}

static int			num_len(intmax_t num)
{
	int			nlen;

	nlen = 1;
	while (num /= 10)
		nlen++;
	return (nlen);
}

static int			res_len(t_pf *pf, intmax_t num)
{
	int			rlen;

	(num == 0 && pf->prec == 0) ? (rlen = 0) : (rlen = num_len(num));
	if (pf->width || pf->prec > -1)
	{
		if (pf->width > rlen && pf->width > pf->prec)
			rlen = pf->width;
		else if (pf->prec > rlen && pf->prec >= pf->width)
		{
			rlen = pf->prec;
			(num < 0 || pf->flags[2] == ' ' || pf->flags[1] == '+') ? rlen++ : 0;
		}
		else
			(num < 0 || pf->flags[2] == ' ' || pf->flags[1] == '+') ? rlen++ : 0;
	}
	else
		(num < 0 || pf->flags[2] == ' ' || pf->flags[1] == '+') ? rlen++ : 0;
	return (rlen);
}

static void			write_num(char *res, intmax_t num, int nlen, int i)
{
	num < 0 ? num *= -1 : 0;
	while (nlen--)
	{
		res[i + nlen] = (num % 10) + '0';
		num /= 10;
	}
}

static void			apply_sign(t_pf *pf, char *res, intmax_t num, int rlen)
{
	int			nlen;
	int i;

	nlen = num_len(num);
	if (pf->flags[0] || (pf->flags[3] && pf->prec <= nlen))
		i = 0;
	else if (!pf->flags[0] && pf->prec <= nlen)
		i = rlen - nlen - 1;
	else if (!pf->flags[0] && pf->prec > nlen)
		i = rlen - pf->prec - 1;
	if (num < 0)
		res[i] = '-';
	else if (pf->flags[2] == ' ' && !pf->flags[1])
		res[i] = ' ';
	else if (pf->flags[1] == '+')
		res[i] = '+';
}

static void			apply_specs(t_pf *pf, intmax_t num, char *res, int rlen)
{
	int			nlen;
	int			i;
	int			s;

	(num == 0 && pf->prec == 0) ? (nlen = 0) : (nlen = num_len(num));
	i = 0;
	s = 0;
	(pf->flags[3] == '0' && !pf->flags[0] && pf->prec == -1) ?
		ft_memset(res, '0', rlen) : ft_memset(res, ' ', rlen);
	if (num < 0 || pf->flags[2] == ' ' || pf->flags[1] == '+')
	{
		apply_sign(pf, res, num, rlen);
		s++;
	}
	if (pf->prec <= nlen)
		(pf->flags[0] == '-') ? (i += s) : (i = (rlen - nlen));
	else if (pf->prec > nlen)
	{
		(pf->flags[0] == '-') ? (i += s) : (i = (rlen - pf->prec));
		while (pf->prec-- > nlen)
			res[i++] = '0';
	}
	write_num(res, num, nlen, i);
}

void				convert_di(t_pf *pf)
{
	intmax_t	num;
	char		*res;
	int			rlen;

	num = int_length_mod(pf);
	if (num == LONG_MIN)
	{
		pf->print = pf_strjoin(pf, ft_strdup("-9223372036854775808"));
		return ;
	}
	rlen = res_len(pf, num);
	if (!(res = (char *)malloc(sizeof(char) * rlen + 1)))
		return ;
	res[rlen] = '\0';
	apply_specs(pf, num, res, rlen);
	pf->print = pf_strjoin(pf, res);
	free(res);
}



/*
		 `0' (zero)   Zero padding.  For all conversions except n, the con-
					  verted value is padded on the left with zeros rather
					  than blanks.  If a precision is given with a numeric
					  conversion (d, i, o, u, i, x, and X), the 0 flag is
					  ignored.
		 `-'		  A negative field width flag; the converted value is to
					  be left adjusted on the field boundary.  Except for n
					  conversions, the converted value is padded on the right
					  with blanks, rather than on the left with blanks or
					  zeros.  A - overrides a 0 if both are given.
		 ` ' (space)  A blank should be left before a positive number pro-
					  duced by a signed conversion (a, A, d, e, E, f, F, g,
					  G, or i).
		 `+'		  A sign must always be placed before a number produced
					  by a signed conversion.  A + overrides a space if both
					  are used.

	 o   An optional decimal digit string specifying a minimum field width.
		 If the converted value has fewer characters than the field width, it
		 will be padded with spaces on the left (or right, if the left-
		 adjustment flag has been given) to fill out the field width.
	 o   An optional precision, in the form of a period . followed by an
		 optional digit string.  If the digit string is omitted, the preci-
		 sion is taken as zero.  This gives the minimum number of digits to
		 appear for d, i, o, u, x, and X conversions, the number of digits to
		 appear after the decimal-point for a, A, e, E, f, and F conversions,
		 the maximum number of significant digits for g and G conversions, or
		 the maximum number of characters to be printed from a string for s
		 conversions.
	 o   An optional length modifier, that specifies the size of the argu-
		 ment.  The following length modifiers are valid for the d, i, n, o,
		 u, x, or X conversion:

		 Modifier		  d, i		   o, u, x, X			n
		 hh				signed char	unsigned char		 signed char *
		 h				 short		  unsigned short		short *
		 l (ell)		   long		   unsigned long		 long *
		 ll (ell ell)	  long long	  unsigned long long	long long *
		 j				 intmax_t	   uintmax_t			 intmax_t *
		 t				 ptrdiff_t	  (see note)			ptrdiff_t *
		 z				 (see note)	 size_t				(see note)
		 q (deprecated)	quad_t		 u_quad_t			  quad_t *

		 Note: the t modifier, when applied to a o, u, x, or X conversion,
		 indicates that the argument is of an unsigned type equivalent in
		 size to a ptrdiff_t.  The z modifier, when applied to a d or i con-
		 version, indicates that the argument is of a signed type equivalent
		 in size to a size_t.  Similarly, when applied to an n conversion, it
		 indicates that the argument is a pointer to a signed type equivalent
		 in size to a size_t.
*/
