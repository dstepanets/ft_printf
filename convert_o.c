/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:30:45 by dstepane          #+#    #+#             */
/*   Updated: 2019/02/13 19:30:46 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	oct_length_mod(t_pf *pf)
{
	uintmax_t	num;

	num = 0;
	*pf->fmt == 'O' ? pf->len = l : 0;
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
	return(num);
}

static int			res_len(t_pf *pf, char *str)
{
	int			rlen;

	if (str[0] == '0' && !str[1])
	{
		(pf->flags[4] || pf->prec == 0) ? (str[0] = '\0') : 0;
		str[1] = '\0';
	}
	rlen = ft_strlen(str);
	if (pf->flags[4] == '#' && rlen >= pf->width && rlen >= pf->prec)
		rlen++;
	else if (pf->width > rlen && pf->width > pf->prec)
		rlen = pf->width;
	else if (pf->prec > rlen && pf->prec >= pf->width)
		rlen = pf->prec;
	return (rlen);
}

static void			apply_specs(t_pf *pf, char *str, char *res, int rlen)
{
	int			i;
	int			z;
	int			nlen;

	i = 0;
	z = 0;
	nlen = ft_strlen(str);
	(pf->flags[0] == '-' || pf->prec != -1) ? pf->flags[3] = '\0' : 0;
	(pf->flags[3] == '0') ? ft_memset(res, '0', rlen) : ft_memset(res, ' ', rlen);
	if (pf->flags[4] == '#' && !pf->flags[3])
	{
			pf->flags[0] ? (res[0] = '0') : (res[rlen - nlen - 1] = '0');
			z = 1;
	}
//	if (pf->flags[4] == '#' && nlen >= pf->width && nlen >= pf->prec)
//		res[i++] = '0';
	if (pf->prec <= nlen && nlen)
	{
		(pf->flags[0] == '-') ? (i += z) : (i = (rlen - nlen));
//		(pf->flags[4] && pf->width > nlen && !pf->flags[3] && !pf->flags[0]) ?
//			res[i - 1] = '0' : 0;
//		(pf->flags[4] && pf->width > nlen && !pf->flags[3] && pf->flags[0]) ?
//			res[i++] = '0' : 0;
	}
	else if (pf->prec > nlen)
	{
		(pf->flags[0] == '-') ? (i = 0) : (i = (rlen - pf->prec));
		while (pf->prec-- > nlen)
			res[i++] = '0';
	}
	while (*str)
		res[i++] = *(str++);
}

void				convert_o(t_pf *pf)
{
	uintmax_t	num;
	char		*str;
	char		*res;
	int			rlen;

	num = oct_length_mod(pf);
	str = pf_itoa_base(num , 8, pf);
	rlen = res_len(pf, str);
	if (!(res = (char *)malloc(sizeof(char) * rlen + 1)))
		return ;
	res[rlen] = '\0';
	apply_specs(pf, str, res, rlen);
	pf->print = pf_strjoin(pf, res);
	free(str);
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
     DOU     The long int argument is converted to signed decimal, unsigned octal,
             or unsigned decimal, as if the format had been ld, lo, or lu respec-
             tively.  These conversion characters are deprecated, and will eventu-
             ally disappear.

Converts a unsigned integer into octal representation oooo.
Precision specifies the minimum number of digits to appear. 
The default precision is 1. If both the converted value and 
the precision are ​0​ the conversion results in no characters. 
In the alternative implementation precision is increased if 
necessary, to write one leading zero. In that case if both 
the converted value and the precision are ​0​, single ​0​ is written.


         `#'          The value should be converted to an ``alternate form''.
		 			For o conversions, the precision of the number is
                      increased to force the first character of the output string
                      to a zero.  For x and X conversions, a non-zero result has
                      the string `0x' (or `0X' for X conversions) prepended to it.
         `0' (zero)   Zero padding.  For all conversions except n, the converted
                      value is padded on the left with zeros rather than blanks.
                      If a precision is given with a numeric conversion (d, i, o,
                      u, i, x, and X), the 0 flag is ignored.
         `-'          A negative field width flag; the converted value is to be
                      left adjusted on the field boundary.  Except for n conver-
                      sions, the converted value is padded on the right with
                      blanks, rather than on the left with blanks or zeros.  A -
                      overrides a 0 if both are given.
     o   An optional decimal digit string specifying a minimum field width.  If
         the converted value has fewer characters than the field width, it will be
         padded with spaces on the left (or right, if the left-adjustment flag has
         been given) to fill out the field width.
     o   An optional precision, in the form of a period . followed by an optional
         digit string.  If the digit string is omitted, the precision is taken as
         zero.  This gives the minimum number of digits to appear for d, i, o, u,
         x, and X conversions.

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