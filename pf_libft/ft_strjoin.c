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

char	*ft_strjoin(char const *s1, char const *s2, t_pf *pf)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if (!(res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	pf->ret += ft_strlen(s2);
	while (s1[j])
		res[i++] = s1[j++];
	while (*s2)
		res[i++] = *s2++;
	res[i] = '\0';
	free((void *)s1);
//	ft_memdel((void*)s1);
	return (res);
}
