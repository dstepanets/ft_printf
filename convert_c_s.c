/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:10:00 by dstepane          #+#    #+#             */
/*   Updated: 2019/01/13 18:10:02 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"















void		convert_procent(t_specs *specs)
{
	unsigned char	res[specs->width + 2];

	if (specs->width)
	{
		res[specs->width] = '\0';
		specs->flags[3] == '0' && !specs->flags[0] ?
			ft_memset(res, '0', specs->width) :
			ft_memset(res, ' ', specs->width);
		if (specs->flags[0] == '-')
			res[0] = '%';
		else
			res[specs->width - 1] = '%';
	}
	else
	{
		res[1] = '\0';
		res[0] = '%';
	}
	specs->res_str = ft_strjoin(specs->res_str, (const char *)res);
}

void		convert_c(t_specs *specs)
{
	unsigned char	res[specs->width + 2];

	if (specs->width)
	{
		res[specs->width] = '\0';
		specs->flags[3] == '0' && !specs->flags[0] ?
			ft_memset(res, '0', specs->width) :
			ft_memset(res, ' ', specs->width);
		if (specs->flags[0] == '-')
			res[0] = va_arg(specs->args, int);
		else
			res[specs->width - 1] = va_arg(specs->args, int);
	}
	else
	{
		res[1] = '\0';
		res[0] = va_arg(specs->args, int);
	}
	specs->res_str = ft_strjoin(specs->res_str, (const char *)res);
}

/*        
		 `0' (zero)   Zero padding.  For all conversions except n, the
                      converted value is padded on the left with zeros
                      rather than blanks.
         `-'          A negative field width flag; the converted value is
                      to be left adjusted on the field boundary.  Except
                      for n conversions, the converted value is padded on
                      the right with blanks, rather than on the left with
                      blanks or zeros.  A - overrides a 0 if both are
                      given.
     o   An optional decimal digit string specifying a minimum field
         width.  If the converted value has fewer characters than the
         field width, it will be padded with spaces on the left (or right,
         if the left-adjustment flag has been given) to fill out the field
         width.
	
	 The following length modifier is valid for the c or s conversion:
         Modifier    c         s
         l (ell)     wint_t    wchar_t *
	
	c       The int argument is converted to an unsigned char, and the
             resulting character is written.
             If the l (ell) modifier is used, the wint_t argument shall be
             converted to a wchar_t, and the (potentially multi-byte)
             sequence representing the single wide character is written,
             including any shift sequences.  If a shift sequence is used,
             the shift state is also restored to the original state after
             the character.

*/
