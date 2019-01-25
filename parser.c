/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:59:07 by dstepane          #+#    #+#             */
/*   Updated: 2019/01/13 18:59:09 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_convers(t_pf *pf)
{
	char c[2];

    c[1] = '\0';
	if (*pf->fmt == '%')
		convert_percent(pf);
	else if (*pf->fmt == 'c')
		convert_c(pf);
	else if (*pf->fmt == 's')
		convert_s(pf);
	else if (*pf->fmt)
	{
		c[0] = *pf->fmt;
		pf->res_str = pf_strjoin(pf, c);
	}

//	if (*pf->fmt != '\0' && *(pf->fmt + 1) != '\0')
//		pf->fmt++;
}

void		parse_length(t_pf *pf)
{
	if (*pf->fmt == 'h' || *pf->fmt == 'l' || *pf->fmt == 'L')
	{
		if (*pf->fmt == 'h' && *(pf->fmt + 1) == 'h')
		{
			pf->len = hh;
			pf->fmt++;
		}
		else if (*pf->fmt == 'h' && *(pf->fmt + 1) != 'h')
			pf->len = h;
		if (*pf->fmt == 'l' && *(pf->fmt + 1) == 'l')
		{
			pf->len = ll;
			pf->fmt++;
		}
		else if (*pf->fmt == 'l' && *(pf->fmt + 1) != 'l')
			pf->len = l;
		if (*pf->fmt == 'L')
			pf->len = L;
		pf->fmt++;
	}
	parse_convers(pf);
}

void		parse_precision(t_pf *pf)
{
	if (*pf->fmt == '.')
	{
		pf->fmt++;
		pf->prec = 0;
		while (ft_isdigit(*pf->fmt))
			pf->prec = pf->prec * 10 + (*pf->fmt++ - '0');
	}
	parse_length(pf);
}

void		parse_fwidth(t_pf *pf)
{
	while (ft_isdigit(*pf->fmt))
		pf->width = pf->width * 10 + (*pf->fmt++ - '0');
	parse_precision(pf);
}

void		parse_flags(t_pf *pf)
{
	while (pf->fmt && (*pf->fmt == '-' || *pf->fmt == '+' || *pf->fmt == ' ' ||
		*pf->fmt == '0' || *pf->fmt == '#'))
	{
		if (*pf->fmt == '-')
			pf->flags[0] = '-';
		else if (*pf->fmt == '+')
			pf->flags[1] = '+';
		else if (*pf->fmt == ' ')
			pf->flags[2] = 's';
		else if (*pf->fmt == '0')
			pf->flags[3] = '0';
		else if (*pf->fmt == '#')
			pf->flags[4] = '#';
		pf->fmt++;
	}
	parse_fwidth(pf);
}
