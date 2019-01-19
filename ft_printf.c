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

int			print_format(t_pf *pf)
{
	int		i;
	char	*txt;
//	char	*leakfix;

	while (*pf->fmt != '\0')
	{
		i = 0;
		while (pf->fmt[i] && pf->fmt[i] != '%')
			i++;
		txt = ft_strsub(pf->fmt, 0, i);
//		leakfix = pf->res_str;
		pf->res_str = ft_strjoin(pf->res_str, txt, pf);
//		free(leakfix);
		free(txt);
		pf->fmt = &pf->fmt[i];
		if (*pf->fmt == '%' && *(pf->fmt + 1))
		{
			reset_specs(pf);
//			leakfix = pf->res_str;
			pf->fmt++;
			parse_flags(pf);
//			if (*leakfix)
//				free(leakfix);
		}
		pf->fmt++;
	}
//	pf->ret += ft_strlen(pf->res_str);
//	printf("\n++++++++++++++++\npf->ret: %d\n", pf->ret);
	return(pf->ret);
}

void		reset_specs(t_pf *pf)
{
	ft_bzero(pf->flags, 5);
	pf->width = 0;
	pf->prec = -1;
	pf->len = no;
	pf->convers = '\0';
}

t_pf		*init_specs(char *fmt)
{
	t_pf		*pf;

	pf = (t_pf *)malloc(sizeof(t_pf));
	pf->fmt = fmt;
	pf->res_str = ft_strnew(1);
	pf->ret = 0;
	ft_bzero(pf->flags, 5);
	pf->width = 0;
	pf->prec = -1;
	pf->len = no;
	pf->convers = '\0';
	return (pf);
}

int			ft_printf(const char *format, ...)
{
	t_pf		*pf;
	int			ret;

	if (format == NULL)
		return (-1);
	if (!ft_strchr(format, '%'))
	{
		ft_putstr(format);
		return(ft_strlen(format));
	}
	pf = init_specs((char *)format);
	ret = 0;
	va_start(pf->args, format);
	ret = print_format(pf);
	va_end(pf->args);
	ft_putstr(pf->res_str);
	if (*pf->res_str)
		free(pf->res_str);
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