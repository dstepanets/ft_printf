/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:00:01 by dstepane          #+#    #+#             */
/*   Updated: 2018/12/25 16:00:09 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_format(t_pf *pf)
{
	int		i;
	char	*txt;
	int		t = 1;

	while (*pf->fmt != '\0')
	{
		i = 0;
		while (pf->fmt[i] && pf->fmt[i] != '%')
		{
			if (pf->fmt[i] == '{' && t == 1)
				break ;
			i++;
		}
		txt = ft_strsub(pf->fmt, 0, i);
		pf->print = pf_strjoin(pf, txt);
		free(txt);
		pf->fmt = &pf->fmt[i];
		if (*pf->fmt == '{' && *(pf->fmt + 1))
		{
			style(pf);
			(pf->fmt == &pf->fmt[i]) ? (t = 0) : (t = 1);
		}
		if (*pf->fmt == '%' && *(pf->fmt + 1))
		{
			reset_specs(pf);
			pf->fmt++;
			parse_flags(pf);
		}
		if (*pf->fmt != '\0' && t != 0)
			pf->fmt++;
	}
	return(pf->ret);
}

void		reset_specs(t_pf *pf)
{
	ft_bzero(pf->flags, 5);
	pf->width = 0;
	pf->prec = -1;
	pf->len = no;
}

t_pf		*init_specs(char *fmt)
{
	t_pf		*pf;

	pf = (t_pf *)malloc(sizeof(t_pf));
	pf->fmt = fmt;
	pf->print = ft_strnew(1);
	pf->ret = 0;
	ft_bzero(pf->flags, 5);
	pf->width = 0;
	pf->prec = -1;
	pf->len = no;
	return (pf);
}

int			ft_printf(const char *format, ...)
{
	t_pf		*pf;
	int			ret;

	if (format == NULL)
		return (-1);
	if (!ft_strchr(format, '%') && !ft_strchr(format, '{'))
	{
		ft_putstr(format);
		return(ft_strlen(format));
	}
	pf = init_specs((char *)format);
	ret = 0;
	va_start(pf->args, format);
	ret = parse_format(pf);
	va_end(pf->args);
	ft_putstr(pf->print);
	free(pf->print);
	free(pf);
	return(ret); 
}

/*
	printf("++++++++SPECS++++++++++\nflags: ");
	for (int z = 0; z < 5; z++)
		printf("%c", pf->flags[z]);
	printf("\nwidth: %d\n", pf->width);
	printf("precision: %d\n", pf->prec);
	printf("length: %d\n", pf->len);
	printf("conversion: %c\n+++++++++++++++++++++++\n\n", pf->convers);
*/







/*
	char	*symbols;
	symbols = "cspdiouxXfhlL#0-+. %";
*/