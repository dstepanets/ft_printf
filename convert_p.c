/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:05:56 by dstepane          #+#    #+#             */
/*   Updated: 2019/02/16 13:05:58 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			res_len(t_pf *pf, char *str)
{
	int			rlen;

	rlen = ft_strlen(str);

	rlen += 2;
	if (pf->width > rlen && pf->width > pf->prec)
		rlen = pf->width;
	else if (pf->prec > rlen && pf->prec >= pf->width)
		rlen = pf->prec + 2;
	if (str[0] == '0' && !str[1] && pf->prec == 0)
	{
		if (!pf->width)
			return (2);
		else
			return(rlen);
	}
	return (rlen);
}

static void			apply_zerox(t_pf *pf, char *res, int *i , char *str)
{
	int			rlen;
	int			nlen;

	rlen = ft_strlen(res);
	nlen = ft_strlen(str);
	if (nlen == 0)
		return ;

	if (!pf->flags[0] && pf->prec > nlen)
		*i = (rlen - pf->prec - 2);
	else if (!pf->flags[0] && !pf->flags[3] && rlen > (nlen + 2))
		*i = (rlen - nlen - 2);
/*	if ((pf->prec <= nlen && !pf->flags[0] && !(str[0] == '0' && !str[1])))
		*i = (rlen - nlen - 2);
	else if (pf->prec > nlen && pf->prec < pf->width && !pf->flags[0])
		*i = (rlen - pf->prec - 2);
	else if (pf->width > nlen && !pf->flags[0] && !pf->flags[3])
		*i = (rlen - nlen - 2);
*/	else 
		*i = 0;
	res[(*i)++] = '0';
	(*pf->fmt == 'X') ? (res[(*i)++] = 'X') : (res[(*i)++] = 'x');
}

static void			apply_specs(t_pf *pf, char *str, char *res, int rlen)
{
	int			i;
	int			nlen;

	i = 0;
	nlen = ft_strlen(str);
	(pf->flags[3] == '0' && !pf->flags[0] && pf->prec == -1) ?
		ft_memset(res, '0', rlen) : ft_memset(res, ' ', rlen);
	apply_zerox(pf, res, &i, str);
	if (!pf->prec && str[0] == '0' && !str[1])
		return ; 
	if (pf->prec <= nlen && nlen)
		(pf->flags[0] == '-') ? 0 : (i = (rlen - nlen));
	else if (pf->prec > nlen)
	{
		(pf->flags[0] == '-') ? 0 : (i = (rlen - pf->prec));
		while (pf->prec-- > nlen)
			res[i++] = '0';
	}
	while (*str)
		res[i++] = *(str++);
}

void					convert_p(t_pf *pf)
{
	uintmax_t	num;
	char		*str;
	char		*res;
	int			rlen;

	num = (unsigned long)(va_arg(pf->args, unsigned long int));
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
     p       The void * pointer argument is printed in hexadecimal (as if by
             `%#x' or `%#lx').

        `0' (zero)   Zero padding.   [UNDEFINED BEHAVIOR] 
					For all conversions except n, the con-
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
         will be padded with spaces on the left (or right, if the left-
         adjustment flag has been given) to fill out the field width.
     o  [UNDEFINED BEHAVIOR] 
	 		An optional precision, in the form of a period . followed by an
         optional digit string.  If the digit string is omitted, the preci-
         sion is taken as zero.  This gives the minimum number of digits to
         appear for d, i, o, u, x, and X conversions, the number of digits to
         appear after the decimal-point for a, A, e, E, f, and F conversions,
         the maximum number of significant digits for g and G conversions, or
         the maximum number of characters to be printed from a string for s
         conversions.


*/