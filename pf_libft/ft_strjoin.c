/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:24:19 by dstepane          #+#    #+#             */
/*   Updated: 2018/11/07 18:24:21 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*pf_strjoin(t_pf *pf, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!pf->res_str || !s2)
		return (NULL);
	if (!(res = (char *)malloc(ft_strlen(pf->res_str) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	pf->ret += ft_strlen(s2);
	while (pf->res_str[j])
		res[i++] = pf->res_str[j++];
	while (*s2)
		res[i++] = *s2++;
	res[i] = '\0';
	if(pf->res_str)
		free((void *)pf->res_str);
//	ft_memdel((void*)s1);
	return (res);
}
