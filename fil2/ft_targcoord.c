/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targcoord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 15:22:11 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/13 19:06:17 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	crcd_up_lf(t_fil *f, int x, int y)
{
	while (y - f->y[9] < f->y[0])
	{
		while (x - f->x[9] < f->x[0])
		{
			if (check_coord(f, x - f->x[9], y - f->y[9], 0) == 1)
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
	while (y + f->y[9] >= 0)
	{
		x = f->x[0] - 1;
		while (x + f->x[9] >= 0)
		{
			if (check_coord(f, x + f->x[9], y + f->y[9], 0))
			{
				f->x[11] = x + f->x[9];
				f->y[11] = y + f->y[9];
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
	while (x + f->x[9] >= 0)
	{
		y = f->y[0] - 1;
		while (y + f->y[9] >= 0)
		{
			if (check_coord(f, x + f->x[9], y + f->y[9], 0))
			{
				f->y[11] = y + f->y[9];
				f->x[11] = x + f->x[9];
				return ;
			}
			y--;
		}
		x--;
	}
}

static	void	choicestrat(t_fil *f, int i, int r)
{
	r = (f->me == 'O' ? f->y[4] - f->y[5] : f->y[8] - f->y[1]);
	if (i == 4 && r < 4)
		i = (r < 0 ? 6 : 8);
	ft_printf("i p %d\n", i);
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

void			ft_targcoord(t_fil *f, int i, int r)
{
	r = ((f->x[12] && f->me == 'O') || (f->y[12] && f->me == 'X') ? 1 : 0);
	if (r && ((f->x[10] && !f->y[10]) || (f->me == 'X' && f->y[4] - f->y[5]
		> f->x[3] - f->x[6]) || (f->me == 'O' && f->y[8] - f->y[1] >
		f->x[7] - f->x[2])))
		i = 1;
	else if (r)
		i = 2;
	else if (!r && ((f->x[10] && !f->y[10]) || (f->me == 'O' && f->y[4] -
		f->y[5] > f->x[3] - f->x[6]) || (f->me == 'X' && f->y[8] - f->y[1] >
		f->x[7] - f->x[2])))
		i = 3;
	else if (!r)
		i = 4;
	ft_printf("i = %d", i);
	r = (f->me == 'X' ? f->x[3] - f->x[6] : f->x[7] - f->x[2]);
	if (i == 1 && r < 4)
		i = (r < 0 ? 7 : 5);
	r = (f->me == 'O' ? f->x[3] - f->x[6] : f->x[7] - f->x[2]);
	if (i == 3 && r < 4)
		i = (r < 0 ? 5 : 7);
	r = (f->me == 'O' ? f->y[8] - f->y[1] : f->y[4] - f->y[5]);
	if (i == 2 && r < 4)
		i = (r < 0 ? 8 : 6);
	choicestrat(f, i, 1);
}
