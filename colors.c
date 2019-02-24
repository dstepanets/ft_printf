/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:32:40 by dstepane          #+#    #+#             */
/*   Updated: 2019/02/24 18:32:41 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void 	background_colors4(t_pf *pf)
{
	if (!ft_strncmp(pf->fmt, "{_light gray}", 13))
	{
		pf->print = pf_strjoin(pf, "\x1B[47m\0");
		pf->fmt += 13;
		return ;
	}
	else if (!ft_strncmp(pf->fmt, "{_dark gray}", 12))
	{
		pf->print = pf_strjoin(pf, "\x1B[100m\0");
		pf->fmt += 12;
		return ;
	}
	return ;
}

static void 	background_colors3(t_pf *pf)
{
	if (!ft_strncmp(pf->fmt, "{_cyan}", 7))
	{
		pf->print = pf_strjoin(pf, "\x1B[46m\0");
		pf->fmt += 7;
		return ;
	}
	else if (!ft_strncmp(pf->fmt, "{_black}", 8))
	{
		pf->print = pf_strjoin(pf, "\x1B[40m\0");
		pf->fmt += 8;
		return ;
	}
	else if (!ft_strncmp(pf->fmt, "{_white}", 8))
	{
		pf->print = pf_strjoin(pf, "\x1B[107m\0");
		pf->fmt += 8;
		return ;
	}
	else
		background_colors4(pf);
}

static void 	background_colors2(t_pf *pf)
{
	if (!ft_strncmp(pf->fmt, "{_green}", 8))
	{
		pf->print = pf_strjoin(pf, "\x1B[42m\0");
		pf->fmt += 8;
		return ;
	}
	else if (!ft_strncmp(pf->fmt, "{_yellow}", 9))
	{
		pf->print = pf_strjoin(pf, "\x1B[43m\0");
		pf->fmt += 9;
		return ;
	}
	else if (!ft_strncmp(pf->fmt, "{_magenta}", 10))
	{
		pf->print = pf_strjoin(pf, "\x1B[45m\0");
		pf->fmt += 10;
		return ;
	}
	else
		background_colors3(pf);
}

void 	background_colors(t_pf *pf)
{
	if (!ft_strncmp(pf->fmt, "{_def}", 6))
	{
		pf->print = pf_strjoin(pf, "\x1B[49m\0");
		pf->fmt += 6;
		return ;
	}
	else if (!ft_strncmp(pf->fmt, "{_red}", 6))
	{
		pf->print = pf_strjoin(pf, "\x1B[41m\0");
		pf->fmt += 6;
		return ;
	}
	else if (!ft_strncmp(pf->fmt, "{_blue}", 7))
	{
		pf->print = pf_strjoin(pf, "\x1B[44m\0");
		pf->fmt += 7;
		return ;
	}
	else
		background_colors2(pf);
}

static void 	text_colors4(t_pf *pf)
{
	if (!ft_strncmp(pf->fmt, "{light gray}", 12))
	{
		pf->print = pf_strjoin(pf, "\x1B[37m\0");
		pf->fmt += 12;
		return ;
	}
	else if (!ft_strncmp(pf->fmt, "{dark gray}", 11))
	{
		pf->print = pf_strjoin(pf, "\x1B[90m\0");
		pf->fmt += 11;
		return ;
	}
	else
		background_colors(pf);
}

static void 	text_colors3(t_pf *pf)
{
	if (!ft_strncmp(pf->fmt, "{cyan}", 6))
	{
		pf->print = pf_strjoin(pf, "\x1B[36m\0");
		pf->fmt += 6;
		return ;
	}
	else if (!ft_strncmp(pf->fmt, "{black}", 7))
	{
		pf->print = pf_strjoin(pf, "\x1B[30m\0");
		pf->fmt += 7;
		return ;
	}
	else if (!ft_strncmp(pf->fmt, "{white}", 7))
	{
		pf->print = pf_strjoin(pf, "\x1B[97m\0");
		pf->fmt += 7;
		return ;
	}
	else
		text_colors4(pf);
}

static void 	text_colors2(t_pf *pf)
{
	if (!ft_strncmp(pf->fmt, "{green}", 7))
	{
		pf->print = pf_strjoin(pf, "\x1B[32m\0");
		pf->fmt += 7;
		return ;
	}
	else if (!ft_strncmp(pf->fmt, "{yellow}", 8))
	{
		pf->print = pf_strjoin(pf, "\x1B[33m\0");
		pf->fmt += 8;
		return ;
	}
	else if (!ft_strncmp(pf->fmt, "{magenta}", 9))
	{
		pf->print = pf_strjoin(pf, "\x1B[35m\0");
		pf->fmt += 9;
		return ;
	}
	else
		text_colors3(pf);
}

static void 	text_colors(t_pf *pf)
{
	if (!ft_strncmp(pf->fmt, "{def}", 5))
	{
		pf->print = pf_strjoin(pf, "\x1B[39m\0");
		pf->fmt += 5;
		return ;
	}
	else if (!ft_strncmp(pf->fmt, "{red}", 5))
	{
		pf->print = pf_strjoin(pf, "\x1B[31m\0");
		pf->fmt += 5;
		return ;
	}
	else if (!ft_strncmp(pf->fmt, "{blue}", 6))
	{
		pf->print = pf_strjoin(pf, "\x1B[34m\0");
		pf->fmt += 6;
		return ;
	}
	else
		text_colors2(pf);
}

static void		style2(t_pf *pf)
{	
	if (!ft_strncmp(pf->fmt, "{u}", 3))
	{
		pf->print = pf_strjoin(pf, "\x1B[4m\0");
		pf->fmt += 3;
		return ;
	}
	else if (!ft_strncmp(pf->fmt, "{i}", 3))
	{
		pf->print = pf_strjoin(pf, "\x1B[7m\0");
		pf->fmt += 3;
		return ;
	}
	else
		text_colors(pf);
}

void			style(t_pf *pf)
{
	if (!ft_strncmp(pf->fmt, "{0}", 3))
	{
		pf->print = pf_strjoin(pf, "\x1B[0m\0");
		pf->fmt += 3;
		return ;
	}
	else if (!ft_strncmp(pf->fmt, "{b}", 3))
	{
		pf->print = pf_strjoin(pf, "\x1B[1m\0");
		pf->fmt += 3;
		return ;
	}
	else if (!ft_strncmp(pf->fmt, "{d}", 3))
	{
		pf->print = pf_strjoin(pf, "\x1B[2m\0");
		pf->fmt += 3;
		return ;
	}
	else
		style2(pf);
}






/*
**	FORMATTING:
**	{0} - Normal Text - Reset all attributes
**	{b} - Bold/Bright
**	{d} - Dim
**	{u} - Underlined
** 	{i} - Inverted
**	
**	TEXT COLORS:
**	{def}	- default
**	{red}
**	{blue}
**	{green}
**	{yellow}
**	{magenta}
**	{cyan}
**	{black}
**	{white}
**	{light gray}
**	{dark gray}
**
**	BACKGROUND COLORS:
**	{_def}	- default
**	{_*}		- where * is the same as text colors.
**
**
**
**
**
**
*/


