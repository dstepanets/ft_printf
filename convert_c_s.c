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

void		convert_procent(t_pf *pf)
{
	unsigned char	res[pf->width + 2];

	if (pf->width)
	{
		res[pf->width] = '\0';
		pf->flags[3] == '0' && !pf->flags[0] ?
			ft_memset(res, '0', pf->width) :
			ft_memset(res, ' ', pf->width);
		if (pf->flags[0] == '-')
			res[0] = '%';
		else
			res[pf->width - 1] = '%';
	}
	else
	{
		res[1] = '\0';
		res[0] = '%';
	}
	pf->res_str = ft_strjoin(pf->res_str, (const char *)res, pf);
}

void		null_char_helper(t_pf *pf)
{
//	char	*leakfix;

//	leakfix = pf->res_str;
	ft_putstr(pf->res_str);
	pf->ret += ft_strlen(pf->res_str);
//	ft_memdel((void *)leakfix);
//	if (*pf->res_str)
//		free(pf->res_str);
	pf->res_str = ft_strnew(1);
	write(1, "\0", 1);
	pf->ret++;
}

void		convert_c(t_pf *pf)
{
	unsigned char	res[pf->width + 2];

	if (pf->width)
	{
		res[pf->width] = '\0';
		pf->flags[3] == '0' && !pf->flags[0] ?
			ft_memset(res, '0', pf->width) :
			ft_memset(res, ' ', pf->width);
		if (pf->flags[0] == '-')
			res[0] = va_arg(pf->args, int);
		else
		{
			res[pf->width - 1] = va_arg(pf->args, int);
			if (res[pf->width - 1] == 0)
			{
				null_char_helper(pf);
				return ;
			}
		}
	}
	else
	{
		res[1] = '\0';
		res[0] = va_arg(pf->args, int);
	}
	if (res[0] == 0)
	{
		null_char_helper(pf);
		return ;
	}
	pf->res_str = ft_strjoin(pf->res_str, (const char *)res, pf);
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
