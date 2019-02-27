/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:09:30 by dstepane          #+#    #+#             */
/*   Updated: 2019/02/13 20:09:34 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		lowercase(uintmax_t num, int base, int len, char *str)
{
	uintmax_t 	n;

	n = num;
	while (num > 0)
	{
		n = num % base;
		str[len--] = (n > 9) ? (n - 10) + 'a' : n + '0';
		num /= base;
	}
}

static void		uppercase(uintmax_t num, int base, int len, char *str)
{
	uintmax_t 	n;

	n = num;
	while (num > 0)
	{
		n = num % base;
		str[len--] = (n > 9) ? (n - 10) + 'A' : n + '0';
		num /= base;
	}
}

char			*pf_itoa_base(uintmax_t num, int base, t_pf *pf)
{
	char		*str;
	int			len;
	uintmax_t 	n;

	len = 0;
	if (base < 2 || base > 16)
		return (NULL);
	n = num;
	while (n /= base)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	str[len + 1] = '\0';
	if (num == 0) 
    { 
        str[0] = '0'; 
        str[1] = '\0'; 
        return (str); 
    } 
	(*pf->fmt == 'x' || *pf->fmt == 'p') ? lowercase(num, base, len, str)
		: uppercase(num, base, len, str);
	return (str);
}
