/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targcoord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 15:22:11 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/12 00:17:25 by vgladush         ###   ########.fr       */
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

void			ft_targcoord(t_fil *flr, int h, int i)
{
	if (flr->x[10] && !flr->y[10])
		i = 1;
	else if (!flr->x[10] && flr->y[10])
		i = 2;
	else if (flr->x[10] && flr->y[10])
		i = 3;
	else if ((flr->x[12] && flr->me == 'O') || (flr->y[12] && flr->me == 'X'))
	{
		if ((flr->me == 'X' && (flr->y[4] - flr->y[5]) > 3 && (flr->x[3] -
			flr->x[6]) > 3) || (flr->me == 'O' && (flr->y[8] - flr->y[1]) > 3
			&& (flr->x[7] - flr->x[2]) > 3))
			i = 3;
	}
	else if ((flr->me == 'O' && (flr->y[4] - flr->y[5]) > 3 && (flr->x[3] -
		flr->x[6]) > 3) || (flr->me == 'X' && (flr->y[8] - flr->y[1]) > 3
		&& (flr->x[7] - flr->x[2]) > 3))
		i = 4;
}
