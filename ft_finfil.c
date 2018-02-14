/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finfil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 00:19:49 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/13 17:29:59 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	crcd_left_up(t_fil *f, int x, int y)
{
	while (x - f->x[9] < f->x[0])
	{
		while (y - f->y[9] < f->y[0])
		{
			if (check_coord(f, x - f->x[9], y - f->y[9], 0))
			{
				f->x[11] = x - f->x[9];
				f->y[11] = y - f->y[9];
				return ;
			}
			y++;
		}
		x++;
		y = 1;
	}
}

void	crcd_left_dw(t_fil *f, int x, int y)
{
	while (x - f->x[9] < f->x[0])
	{
		y = f->y[0] - 1;
		while (y + f->y[9] > 0)
		{
			if (check_coord(f, x - f->x[9], y, 0))
			{
				f->y[11] = y;
				f->x[11] = x - f->x[9];
				return ;
			}
			y--;
		}
		x++;
	}
}

void	crcd_up_rg(t_fil *f, int x, int y)
{
	while (y - f->y[9] < f->y[0])
	{
		x = f->x[0] - 1;
		while (x + f->x[9] > 0)
		{
			if (check_coord(f, x, y - f->y[9], 0))
			{
				f->x[11] = x;
				f->y[11] = y - f->y[9];
				return ;
			}
			x--;
		}
		y++;
	}
}

void	crcd_down_lf(t_fil *f, int x, int y)
{
	y = f->y[0] - 1;
	while (y + f->y[9] > 0)
	{
		while (x - f->x[9] < f->x[0])
		{
			if (check_coord(f, x - f->x[9], y, 0))
			{
				f->x[11] = x - f->x[9];
				f->y[11] = y;
				return ;
			}
			x++;
		}
		y--;
		x = 1;
	}
}

void	crcd_right_up(t_fil *f, int x, int y)
{
	x = f->x[0] - 1;
	while (x + f->x[9] > 0)
	{
		while (y - f->y[9] < f->y[0])
		{
			if (check_coord(f, x, y - f->y[9], 0))
			{
				f->x[11] = x;
				f->y[11] = y - f->y[9];
				return ;
			}
			y++;
		}
		x--;
		y = 1;
	}
}
