/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:40:48 by dstepane          #+#    #+#             */
/*   Updated: 2018/11/02 18:40:50 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *str;

	str = s1;
	while (*s1)
		s1++;
	while (*s2 && n--)
		*s1++ = *s2++;
	*s1 = '\0';
	return (str);
}
