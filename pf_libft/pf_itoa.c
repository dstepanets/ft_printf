/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:02:15 by dstepane          #+#    #+#             */
/*   Updated: 2018/11/09 14:02:17 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_positive(char *res, t_pf *pf)
{
	if (pf->flags[2] == ' ' && !pf->flags[1])
		res[0] = ' ';
	else if (pf->flags[1] == '+')
		res[0] = '+';
}

static void	ft_negative(intmax_t *n, int *sign, t_pf *pf)
{
	if (*n < 0)
	{
		*sign = -1;
		*n = -*n;
	}
	else if (pf->flags[2] == ' ' || pf->flags[1] == '+')
		*sign = 1;
}

char		*pf_itoa(intmax_t n, t_pf *pf)
{
	intmax_t		nbr;
	int				len;
	int				sign;
	char			*res;

	if (n == -9223372036854775807)
		return (ft_strdup("−9223372036854775807"));
	nbr = n;
	len = 1;
	while (nbr /= 10)
		len++;
	sign = 0;
	ft_negative(&n, &sign, pf);
	len += (sign * sign);
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	while (len--)
	{
		res[len] = (n % 10) + '0';
		n /= 10;
	}
	sign < 0 ? (res[0] = '-') : ft_positive(res, pf);
	return (res);
}
