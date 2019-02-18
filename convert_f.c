/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:16:25 by dstepane          #+#    #+#             */
/*   Updated: 2019/02/18 15:16:27 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*get_1part(intmax_t num)
{
	intmax_t	n;
	int			nlen;
	char		*left;
	
	n = num;
	n < 0 ? n = -n : 0;
	nlen = 1;
	while (n /= 10)
		nlen++;
	printf("nlen: %d\n", nlen);	
	if (!(left = (char *)malloc(sizeof(char) * nlen + 1)))
		return (NULL);
	left[nlen] = '\0';
	while (num)
	{
		left[--nlen] = (num % 10) + '0';
		num /= 10;
	}
	printf("left: %s\n", left);	
	return (left);
}

static int			res_len(t_pf *pf, char *left, long double num)
{
	int			rlen;

	rlen = ft_strlen(left);
	pf->prec == -1 ? pf->prec = 6 : 0;
	(num < 0 || pf->flags[2] == ' ' || pf->flags[1] == '+') ? rlen++ : 0;


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
	printf("rlen: %d\n", rlen);
	return (rlen);
}

void				convert_f(t_pf *pf)
{
	long double	num;
//	char		*res;
	char		*left;
	int			rlen;

	(pf->len == L) ? (num = (long double)(va_arg(pf->args, long double))) : 
		(num = (double)(va_arg(pf->args, double)));
	left = get_1part(num);
	rlen = res_len(pf, left, num);
//	if (!(res = (char *)malloc(sizeof(char) * rlen + 1)))
//		return ;
//	res[rlen] = '\0';
//	apply_specs(pf, str, res, rlen);
//	pf->print = pf_strjoin(pf, res);
//	free(res);
}


/*
     fF      The double argument is rounded and converted to decimal notation
             in the style [-]ddd.ddd, where the number of digits after the
             decimal-point character is equal to the precision specification.
             If the precision is missing, it is taken as 6; if the precision
             is explicitly zero, no decimal-point character appears.  If a
             decimal point appears, at least one digit appears before it.

         `#'          For a, A, e, E, f, F, g,
                      and G conversions, the result will always contain a
                      decimal point, even if no digits follow it (normally, a
                      decimal point appears in the results of those conver-
                      sions only if a digit follows).
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
         ` ' (space)  A blank should be left before a positive number pro-
                      duced by a signed conversion (a, A, d, e, E, f, F, g,
                      G, or i).
         `+'          A sign must always be placed before a number produced
                      by a signed conversion.  A + overrides a space if both
                      are used.
     o   An optional decimal digit string specifying a minimum field width.
         If the converted value has fewer characters than the field width, it
         will be padded with spaces on the left (or right, if the left-
         adjustment flag has been given) to fill out the field width.
     o   An optional precision, in the form of a period . followed by an
         optional digit string.  If the digit string is omitted, the preci-
         sion is taken as zero.  This gives the number of digits to
         appear after the decimal-point for a, A, e, E, f, and F conversions...
        
The following length modifier is valid for the a, A, e, E, f, F, g,
         or G conversion:
         Modifier    a, A, e, E, f, F, g, G
         l (ell)     double (ignored, same behavior as without it)
         L           long double



*/