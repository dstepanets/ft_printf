/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:16:25 by dstepane          #+#    #+#             */
/*   Updated: 2019/02/18 15:16:27 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*get_right(t_pf *pf, t_fl *fl, long double num)
{
	intmax_t	left;
	int			pr;

	num = num < 0 ? -num : num;
	left = num;
	pr = pf->prec;
//	printf("left: %ld\n", left);
	num = num - (long double)left;
//	printf("num: %Lf\n", num);
	if (!(fl->right = (char *)malloc(sizeof(char) * pr + 1)))
		return (NULL);
	fl->right[pr] = '\0';
	if (num == 0)
	{
		ft_memset(fl->right, '0', pr);
		return (fl->right);
	}
	while (pr--)
		num *= 10;
	left = num;
	pr = pf->prec;
	while (left)
	{
		fl->right[--pr] = (left % 10) + '0';
		left /= 10;
	}
//	printf("left: %ld\n", left);
//	printf("num: %Lf\n", num);
//	printf("right: %s\n", right);
	return (fl->right);
}

static char			*get_left(t_fl *fl, intmax_t num)
{
	intmax_t	n;
	int			nlen;
	
	num = num < 0 ? -num : num;
	n = num;
	nlen = 1;
	while (n /= 10)
		nlen++;
//	printf("nlen: %d\n", nlen);	
	if (!(fl->left = (char *)malloc(sizeof(char) * nlen + 1)))
		return (NULL);
	fl->left[nlen] = '\0';
	if (num == 0)
	{
		fl->left[0] = '0';
		return (fl->left);
	}
	while (num)
	{
		fl->left[--nlen] = (num % 10) + '0';
		num /= 10;
	}
//	printf("left: %s\n", left);	
	return (fl->left);
}

static void			res_len(t_pf *pf, t_fl *fl)
{

	fl->nlen = ft_strlen(fl->left) + pf->prec;
	(pf->prec != 0 || pf->flags[4] == '#') ? fl->nlen++ : 0;							// dot
	fl->rlen = fl->nlen;
	(fl->num < 0 || pf->flags[2] == ' ' || pf->flags[1] == '+') ? fl->rlen++ : 0;		// sign
	(pf->width > fl->rlen) ? fl->rlen = pf->width : 0; 									// width
//	printf("nlen: %d\n", fl->nlen);									
//	printf("rlen: %d\n", fl->rlen);

}

static long double	round_num(int i, long double num)
{
	long double	roun;
	int			pr;
	
	num = num < 0 ? -num : num;
	pr = 1;
	while (i--)
		pr *= 10;
	roun = (int) (num * pr + 0.5);
	roun /= pr;
//	printf("roun: %Lf\n", roun);
	return (roun);
}

static void			put_sign(t_pf *pf, t_fl *fl)
{
	int		i;
	
	if (pf->flags[0] == '-' || pf->flags[3] == '0')
		i = 0;
	else
		i = fl->rlen - fl->nlen - 1;
	if (fl->num < 0)
		fl->res[i] = '-';
	else if (pf->flags[1] == '+')
		fl->res[i] = '+';
	else
		fl->res[i] = ' ';
}

static void			apply_specs(t_pf *pf, t_fl *fl)
{
	int		i;
	int		s;

	(pf->flags[3] == '0' && !pf->flags[0]) ?
		ft_memset(fl->res, '0', fl->rlen) : ft_memset(fl->res, ' ', fl->rlen);
	i = 0;
	s = 0;
	if (fl->num < 0 || pf->flags[2] == ' ' || pf->flags[1] == '+')
	{
		put_sign(pf, fl);
		s = 1;
	}
	(pf->flags[0] == '-') ? (i += s) : (i = (fl->rlen - fl->nlen));
//	printf("i: %d\n", i);
	while (*fl->left)
		fl->res[i++] = *fl->left++;
//	printf("i: %d\n", i);
	(pf->prec != 0 || pf->flags[4] == '#') ? fl->res[i++] = '.' : 0;
	while (*fl->right)
		fl->res[i++] = *fl->right++;
}

void				convert_f(t_pf *pf)
{
	t_fl		*fl;
	char		*leak1;
	char		*leak2;

	fl = (t_fl *)malloc(sizeof(t_fl));
	(pf->len == L) ? (fl->num = (long double)(va_arg(pf->args, long double))) : 
		(fl->num = (double)(va_arg(pf->args, double)));
	pf->prec == -1 ? pf->prec = 6 : 0;
	fl->roun = round_num(pf->prec, fl->num);
	leak1 = get_left(fl, fl->roun);
	leak2 = get_right(pf, fl, fl->roun);
	res_len(pf, fl);
	if (!(fl->res = (char *)malloc(sizeof(char) * fl->rlen + 1)))
		return ;
	fl->res[fl->rlen] = '\0';
	apply_specs(pf, fl);
	pf->print = pf_strjoin(pf, fl->res);
	ft_memdel((void **)fl->left);
	free(leak1);
	free(leak2);
	free(fl->res);
	free(fl);
}


/*
     fF      The double argument is rounded and converted to decimal notation
             in the style [-]ddd.ddd, where the number of digits after the
             decimal-point character is equal to the precision specification.
             If the precision is missing, it is taken as 6; if the precision
             is explicitly zero, no decimal-point character appears.  If a
             decimal point appears, at least one digit appears before it.

         `#'          For a, A, e, E, f, F, g,
                      and G conversions, the result will always contain a
                      decimal point, even if no digits follow it (normally, a
                      decimal point appears in the results of those conver-
                      sions only if a digit follows).
         `0' (zero)   Zero padding.  For all conversions except n, the con-
                      verted value is padded on the left with zeros rather
                      than blanks.  If a precision is given with a numeric
                      conversion (d, i, o, u, i, x, and X), the 0 flag is
                      ignored.
         `-'          A negative field width flag; the converted value is to
                      be left adjusted on the field boundary.  Except for n
                      conversions, the converted value is padded on the right
                      with blanks, rather than on the left with blanks or
                      zeros.  A - overrides a 0 if both are given.
         ` ' (space)  A blank should be left before a positive number pro-
                      duced by a signed conversion (a, A, d, e, E, f, F, g,
                      G, or i).
         `+'          A sign must always be placed before a number produced
                      by a signed conversion.  A + overrides a space if both
                      are used.
     o   An optional decimal digit string specifying a minimum field width.
         If the converted value has fewer characters than the field width, it
         will be padded with spaces on the left (or right, if the left-
         adjustment flag has been given) to fill out the field width.
     o   An optional precision, in the form of a period . followed by an
         optional digit string.  If the digit string is omitted, the preci-
         sion is taken as zero.  This gives the number of digits to
         appear after the decimal-point for a, A, e, E, f, and F conversions...
        
The following length modifier is valid for the a, A, e, E, f, F, g,
         or G conversion:
         Modifier    a, A, e, E, f, F, g, G
         l (ell)     double (ignored, same behavior as without it)
         L           long double



*/