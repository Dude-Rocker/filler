/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targcoord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 15:22:11 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/15 22:55:45 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	crcd_up_lf(t_fil *f, int x, int y)
{
	while (y - f->y[9] < f->y[0])
	{
		while (x - f->x[9] < f->x[0])
		{
			if (check_coord(f, x - f->x[9], y - f->y[9], 0))
			{
				f->x[11] = x - f->x[9];
				f->y[11] = y - f->y[9];
				return ;
			}
			x++;
		}
		y++;
		x = 1;
	}
}

static	void	crcd_down_rg(t_fil *f, int x, int y)
{
	y = f->y[0] - 1;
	while (y + f->y[9] > 0)
	{
		x = f->x[0] - 1;
		while (x + f->x[9] > 0)
		{
			if (check_coord(f, x, y, 0))
			{
				f->x[11] = x;
				f->y[11] = y;
				return ;
			}
			x--;
		}
		y--;
	}
}

static	void	crcd_right_dw(t_fil *f, int x, int y)
{
	x = f->x[0] - 1;
	while (x + f->x[9] > 0)
	{
		y = f->y[0] - 1;
		while (y + f->y[9] > 0)
		{
			if (check_coord(f, x, y, 0))
			{
				f->y[11] = y;
				f->x[11] = x;
				return ;
			}
			y--;
		}
		x--;
	}
}

static	void	choicestrat(t_fil *f, int i)
{
	if (i == 1)
		crcd_down_rg(f, 1, 1);
	else if (i == 2)
		crcd_right_dw(f, 1, 1);
	else if (i == 3)
		crcd_left_up(f, 1, 1);
	else if (i == 4)
		crcd_up_lf(f, 1, 1);
	else if (i == 5)
		crcd_down_lf(f, 1, 1);
	else if (i == 6)
		crcd_right_up(f, 1, 1);
	else if (i == 7)
		crcd_left_dw(f, 1, 1);
	else
		crcd_up_rg(f, 1, 1);
}

void			ft_targcoord(t_fil *f, int i)
{
	if (f->x[13])
		i = (f->x[12] || (f->y[8] - f->y[1] > f->x[7] - f->x[2]) ? 1 : 2);
	else
		i = (!f->y[10] && !f->y[12] && f->x[4] - f->x[5] > f->y[3] - f->y[6]
		&& f->x[3] - f->x[6] > -2 && f->y[4] - f->y[8] < 8 ? 3 : 4);
	if (i == 1 && !f->x[12] && (f->y[10] || (f->y[12] && f->y[7] - f->y[2]
		< 3 && f->x[7] - f->x[2] < 3)))
		i = 2;
	if (i == 1 && f->x[7] - f->x[2] < 3 && !f->y[10] && !f->y[12])
		i = ((f->y[7] - f->y[2] < 3 && f->x[7] - f->x[2] < 1) ? 7 : 5);
	if (i == 2 && f->x[8] - f->x[1] < 3)
		i = ((f->x[8] - f->x[1] < 1 && f->y[8] - f->y[1] < 3) ? 8 : 6);
	if (i == 3 && f->y[3] - f->y[6] < 3)
		i = (f->y[3] - f->y[6] < 1 && f->x[3] - f->x[6] < 3 ? 5 : 7);
	if (i == 4 && f->x[4] - f->x[5] < 3 && !f->x[12])
		i = (f->x[4] - f->x[5] < 1 && f->y[4] - f->y[5] < 3 ? 6 : 8);
	choicestrat(f, i);
}
