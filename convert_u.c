/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:51:30 by dstepane          #+#    #+#             */
/*   Updated: 2019/02/13 16:51:31 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	uint_length_mod(t_pf *pf)
{
	uintmax_t	num;

	num = 0;
	*pf->fmt == 'U' ? pf->len = l : 0;
	if (pf->len == no)
		num = (unsigned int)(va_arg(pf->args, unsigned int));
	else if (pf->len == hh)
		num = (unsigned char)(va_arg(pf->args, unsigned int));
	else if (pf->len == h)
		num = (unsigned short)(va_arg(pf->args, unsigned int));
	else if (pf->len == l)
		num = (unsigned long)(va_arg(pf->args, unsigned long int));
	else if (pf->len == ll)
		num = (unsigned long long)(va_arg(pf->args, unsigned long long int));
	else if (pf->len == j)
		num = (uintmax_t)(va_arg(pf->args, uintmax_t));
	else if (pf->len == z)
		num = (size_t)(va_arg(pf->args, size_t));
	return((uintmax_t)num);
}

static int			num_len(uintmax_t num)
{
	int			nlen;

	nlen = 1;
	while (num /= 10)
		nlen++;
	return (nlen);
}

static int			res_len(t_pf *pf, uintmax_t num)
{
	int			rlen;

	rlen = num_len(num);
	if (pf->width > rlen && pf->width > pf->prec)
		rlen = pf->width;
	else if (pf->prec > rlen && pf->prec >= pf->width)
		rlen = pf->prec;
	return (rlen);
}

static void			apply_specs(t_pf *pf, uintmax_t num, char *res, int rlen)
{
	int			nlen;
	int			i;

	nlen = num_len(num);
	i = 0;
	(pf->flags[3] == '0' && !pf->flags[0] && pf->prec == -1) ?
		ft_memset(res, '0', rlen) : ft_memset(res, ' ', rlen);
	if (pf->prec <= nlen)
		(pf->flags[0] == '-') ? (i = 0) : (i = (rlen - nlen));
	else if (pf->prec > nlen)
	{
		(pf->flags[0] == '-') ? (i = 0) : (i = (rlen - pf->prec));
		while (pf->prec-- > nlen)
			res[i++] = '0';
	}
	while (nlen--)
	{
		res[i + nlen] = (num % 10) + '0';
		num /= 10;
	}
}

void				convert_u(t_pf *pf)
{
	uintmax_t	num;
	char		*res;
	int			rlen;

	num = uint_length_mod(pf);
	rlen = res_len(pf, num);
	if (!(res = (char *)malloc(sizeof(char) * rlen + 1)))
		return ;
	res[rlen] = '\0';
	apply_specs(pf, num, res, rlen);
	pf->print = pf_strjoin(pf, res);
	free(res);
}

/*
      diouxX  The int (or appropriate variant) argument is converted to signed dec-
             imal (d and i), unsigned octal (o), unsigned decimal (u), or unsigned
             hexadecimal (x and X) notation.  The letters ``abcdef'' are used for
             x conversions; the letters ``ABCDEF'' are used for X conversions.
             The precision, if any, gives the minimum number of digits that must
             appear; if the converted value requires fewer digits, it is padded on
             the left with zeros.
 
         `0' (zero)   Zero padding.  For all conversions except n, the converted
                      value is padded on the left with zeros rather than blanks.
                      If a precision is given with a numeric conversion (d, i, o,
                      u, i, x, and X), the 0 flag is ignored.

         `-'          A negative field width flag; the converted value is to be
                      left adjusted on the field boundary.  Except for n conver-
                      sions, the converted value is padded on the right with
                      blanks, rather than on the left with blanks or zeros.  A -
                      overrides a 0 if both are given.

     o   An optional precision, in the form of a period . followed by an optional
         digit string.  If the digit string is omitted, the precision is taken as
         zero.  This gives the minimum number of digits to appear for d, i, o, u,
         x, and X conversions...

     o   An optional length modifier, that specifies the size of the argument.
         The following length modifiers are valid for the d, i, n, o, u, x, or X
         conversion:

         Modifier          d, i           o, u, x, X            n
         hh                signed char    unsigned char         signed char *
         h                 short          unsigned short        short *
         l (ell)           long           unsigned long         long *
         ll (ell ell)      long long      unsigned long long    long long *
         j                 intmax_t       uintmax_t             intmax_t *
         t                 ptrdiff_t      (see note)            ptrdiff_t *
         z                 (see note)     size_t                (see note)
         q (deprecated)    quad_t         u_quad_t              quad_t *

*/