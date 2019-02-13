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

void				convert_o(t_pf *pf)
{

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