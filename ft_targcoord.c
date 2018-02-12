/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targcoord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 15:22:11 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/12 17:01:05 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	int		check_coord(t_fil *f, int x, int y, int t)
{
	int			i;
	int			j;

	i = 0;
	while (f->pc[i])
	{
		j = 0;
		while (f->pc[i][j])
		{
			if (f->pc[i][j] != '.' && (t > 1 || y > f->y[0] || x < 0 || y < 0 ||
				x > f->x[0] || (f->map[y][x] != '.' && f->map[y][x] != f->me)))
				return (0);
			else if (f->pc[i][j] != '.' && f->map[y][x] == f->me)
				t++;
			j++;
			x++;
		}
		x -= j;
		i++;
		y++;
	}
	if (t == 1)
		return (1);
	else
		return (0);
}

static	int		crtcoordsec(t_fil *f, int i)
{

}

static	void	crtcoord(t_fil *f, int i, int x, int y)
{
	if (i == 1 && f-me == 'O')
	{
		y = f->y[2] - 1;
		while (y + f->y[9] >= f->y[2])
		{
			x = f->x[2] - 1;
			while (x + f->x[9] >= f->x[2])
			{
				if (check_coord(f, x - f->x[9], y - f->y[9], 0))
				{
					f->x[11] = x - f->x[9];
					f->y[11] = y - f->y[9];
					return ;
				}
				x--;
			}
			y--;
		}
	}
	if (i == 4)
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
	crtcoord(f, i, 1, 1);
}
