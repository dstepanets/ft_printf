/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:01:49 by dstepane          #+#    #+#             */
/*   Updated: 2019/02/15 15:01:50 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			res_len(t_pf *pf, char *str)
{
	int			rlen;
	int 		nlen;

	nlen = ft_strlen(str);
	rlen = nlen;
	if (pf->flags[4] == '#' && !(str[0] == '0' && !str[1]))
		rlen = nlen + 2;
	if (pf->prec > nlen)
		rlen += (pf->prec - nlen);
	if (pf->width > rlen)
		rlen = pf->width;
	if (str[0] == '0' && !str[1] && pf->prec == 0)
	{
		(str[0] = '\0');
		if (!pf->width)
			return (0);
		else
			return(rlen);
	}
	return (rlen);
}

static void			apply_zerox(t_pf *pf, char *res, int i , int nlen)
{
	int			rlen;

	rlen = ft_strlen(res);
	if (nlen == 0)
		return ;
	if (!pf->flags[0] && pf->prec > nlen)
		i = (rlen - pf->prec - 2);
	else if (!pf->flags[0] && !pf->flags[3] && rlen > (nlen + 2))
		i = (rlen - nlen - 2);
	else 
		i = 0;
	res[(i++)] = '0';
	(*pf->fmt == 'X') ? (res[(i)] = 'X') : (res[(i)] = 'x');
}

static void			apply_specs(t_pf *pf, char *str, char *res, int rlen)
{
	int			i;
	int 		z;
	int			nlen;

	i = 0;
	z = 0;
	nlen = ft_strlen(str);
	(pf->flags[0] == '-' || pf->prec != -1) ? pf->flags[3] = '\0' : 0;
	(pf->flags[3] == '0') ? ft_memset(res, '0', rlen) : ft_memset(res, ' ', rlen);
	if (pf->flags[4] == '#' && !(str[0] == '0' && !str[1]))
	{
		apply_zerox(pf, res, i, nlen);
		z = 2;
	}
	if (pf->prec <= nlen && nlen)
		(pf->flags[0] == '-') ? (i += z) : (i = (rlen - nlen));
	else if (pf->prec > nlen)
	{
		(pf->flags[0] == '-') ? i += z : (i = (rlen - pf->prec));
		while (pf->prec-- > nlen)
			res[i++] = '0';
	}
	while (*str)
		res[i++] = *(str++);
}

void				convert_x(t_pf *pf)
{
	uintmax_t	num;
	char		*str;
	char		*res;
	int			rlen;

	num = uint_length_mod(pf);
	str = pf_itoa_base(num , 16, pf);
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
     diouxX  The int (or appropriate variant) argument is converted to signed
             decimal (d and i), unsigned octal (o), unsigned decimal (u), or
             unsigned hexadecimal (x and X) notation.  The letters ``abcdef''
             are used for x conversions; the letters ``ABCDEF'' are used for X
             conversions.  The precision, if any, gives the minimum number of
             digits that must appear; if the converted value requires fewer
             digits, it is padded on the left with zeros.

         `#'          The value should be converted to an ``alternate form''.
            	  For x and X conversions, a
                      non-zero result has the string `0x' (or `0X' for X con-
                      versions) prepended to it. 
         `0' (zero)   Zero padding.  For all conversions except n, the con-
                      verted value is padded on the left with zeros rather
                      than blanks.  If a precision is given with a numeric
                      conversion (d, i, o, u, i, x, and X), the 0 flag is
                      ignored.
         `-'          A negative field width flag; the converted value is to
                      be left adjusted on the field boundary.  Except for n
                      conversions, the converted value is padded on the right
                      with blanks, rather than on the left with blanks or
                      zeros.  A - overrides a 0 if both are given.
     o   An optional decimal digit string specifying a minimum field width.
         If the converted value has fewer characters than the field width, it
         will be padded with spaces on the left (or right, if the left-adjust-
         ment flag has been given) to fill out the field width.
     o   An optional precision, in the form of a period . followed by an
         optional digit string.  If the digit string is omitted, the precision
         is taken as zero.  This gives the minimum number of digits to appear
         for d, i, o, u, x, and X conversions...
	o   An optional length modifier, that specifies the size of the argument.
         The following length modifiers are valid for the d, i, n, o, u, x, or
         X conversion:

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
