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

char		*pf_itoa_base(intmax_t num, int base, t_pf *pf)
{
	char		*str;
	int			i;
	int			len;
	intmax_t 	n;

	i = 0;
	len = 0;
	
	if (base < 2 || base > 16)
		return (NULL);
	num = (num < 0) ? -num : num;
	n = num;
	while (n /= base)
		len++;
	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
	str[len] = '\0';

	return (str);
}
