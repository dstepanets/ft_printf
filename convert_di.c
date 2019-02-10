/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:37:13 by dstepane          #+#    #+#             */
/*   Updated: 2019/01/26 19:37:15 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
char            *apply_width(char *str)
{

}
*/
intmax_t		length_mod(t_pf *pf)
{
	intmax_t	num;

	num = 0;
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

void			convert_di(t_pf *pf)
{
	intmax_t	num;
    char        *res;

	num = length_mod(pf);
    res = pf_itoa(num, pf);


    pf->print = pf_strjoin(pf, res);

}



/*
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
         sion is taken as zero.  This gives the minimum number of digits to
         appear for d, i, o, u, x, and X conversions, the number of digits to
         appear after the decimal-point for a, A, e, E, f, and F conversions,
         the maximum number of significant digits for g and G conversions, or
         the maximum number of characters to be printed from a string for s
         conversions.
     o   An optional length modifier, that specifies the size of the argu-
         ment.  The following length modifiers are valid for the d, i, n, o,
         u, x, or X conversion:

         Modifier          d, i           o, u, x, X            n
         hh                signed char    unsigned char         signed char *
         h                 short          unsigned short        short *
         l (ell)           long           unsigned long         long *
         ll (ell ell)      long long      unsigned long long    long long *
         j                 intmax_t       uintmax_t             intmax_t *
         t                 ptrdiff_t      (see note)            ptrdiff_t *
         z                 (see note)     size_t                (see note)
         q (deprecated)    quad_t         u_quad_t              quad_t *

         Note: the t modifier, when applied to a o, u, x, or X conversion,
         indicates that the argument is of an unsigned type equivalent in
         size to a ptrdiff_t.  The z modifier, when applied to a d or i con-
         version, indicates that the argument is of a signed type equivalent
         in size to a size_t.  Similarly, when applied to an n conversion, it
         indicates that the argument is a pointer to a signed type equivalent
         in size to a size_t.
*/
