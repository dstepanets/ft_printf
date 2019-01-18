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

int			print_format(char *fmt, t_specs *specs)
{
	int		i;
	char	*txt;
	char	*leakfix;

	i = 0;
	while (fmt[i] && fmt[i] != '%')
		i++;
	txt = ft_strsub(fmt, 0, i);
	leakfix = specs->res_str;
	specs->res_str = ft_strjoin(specs->res_str, txt);
	free(leakfix);
	free(txt);
	if (fmt[i] == '%' && fmt[i + 1])
	{
		reset_specs(specs);
		leakfix = specs->res_str;
		parse_flags(&fmt[++i], specs);
		if (*leakfix)
			free(leakfix);
	}
	specs->ret += specs->ret + ft_strlen(specs->res_str);
	return(specs->ret);
}

void		reset_specs(t_specs *specs)
{
	ft_bzero(specs->flags, 5);
	specs->width = 0;
	specs->prec = -1;
	specs->len = no;
	specs->convers = '\0';
}

t_specs		*init_specs(void)
{
	t_specs		*specs;

	specs = (t_specs *)malloc(sizeof(t_specs));
	specs->res_str = ft_strnew(1);
	specs->ret = 0;
	ft_bzero(specs->flags, 5);
	specs->width = 0;
	specs->prec = -1;
	specs->len = no;
	specs->convers = '\0';
	return (specs);
}

int			ft_printf(const char *format, ...)
{
	t_specs		*specs;
	int			ret;

	if (format == NULL)
		return (-1);
	if (!ft_strchr(format, '%'))
	{
		ft_putstr(format);
		return(ft_strlen(format));
	}
	specs = init_specs();
	ret = 0;
	va_start(specs->args, format);
	ret = print_format((char *)format, specs);
	va_end(specs->args);
	ft_putstr(specs->res_str);
	if (*specs->res_str)
		free(specs->res_str);
	free(specs);
	return(ret); 
}

/*
	printf("++++++++SPECS++++++++++\nflags: ");
	for (int z = 0; z < 5; z++)
		printf("%c", specs->flags[z]);
	printf("\nwidth: %d\n", specs->width);
	printf("precision: %d\n", specs->prec);
	printf("length: %d\n", specs->len);
	printf("conversion: %c\n+++++++++++++++++++++++\n\n", specs->convers);
*/







/*
	char	*symbols;
	symbols = "cspdiouxXfhlL#0-+. %";
*/