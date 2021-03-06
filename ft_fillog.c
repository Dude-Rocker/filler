/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:22:06 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/15 22:15:54 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				check_coord(t_fil *f, int x, int y, int t)
{
	int			i;
	int			j;

	i = 0;
	while (f->pc[i])
	{
		j = 0;
		while (f->pc[i][j])
		{
			if (f->pc[i][j] != '.' && (t > 1 || y > f->y[0] - 1 || x < 0
				|| y < 0 || x > f->x[0] - 1 || (f->map[y][x] != '.' &&
				f->map[y][x] != f->me && f->map[y][x] != f->me + 32)))
				return (0);
			else if (f->pc[i][j] != '.' && (f->map[y][x] == f->me ||
				f->map[y][x] == f->me + 32))
				t++;
			j++;
			x++;
		}
		x -= j;
		i++;
		y++;
	}
	return ((t == 1 ? 1 : 0));
}

static	void	srcclosed(char **s, char c, t_fil *flr)
{
	int			j;
	int			k;

	j = -1;
	k = -1;
	while (s[0][++j])
		if (s[0][j] == c)
			flr->x[10] = 1;
	j--;
	while (s[++k])
		if (s[k][j] == c)
			flr->x[12] = 1;
	j = -1;
	k--;
	while (s[k][++j])
		if (s[k][j] == c)
			flr->y[10] = 1;
	k = -1;
	while (s[++k])
		if (s[k][0] == c)
			flr->y[12] = 1;
}

static	void	scrdsec(t_fil *flr, int i, int j, char c)
{
	if (c == '.')
		return ;
	if (flr->x[5] <= j)
	{
		flr->x[5] = j;
		flr->y[5] = i;
	}
	if (flr->y[6] <= i)
	{
		flr->y[6] = i;
		flr->x[6] = j;
	}
	if (flr->x[7] > j)
	{
		flr->x[7] = j;
		flr->y[7] = i;
	}
	if (flr->y[8] > i)
	{
		flr->x[8] = j;
		flr->y[8] = i;
	}
}

static	void	srccrd(t_fil *flr, int i, int j, char c)
{
	if (c == flr->me || c == flr->me + 32)
	{
		if (flr->x[1] <= j)
		{
			flr->x[1] = j;
			flr->y[1] = i;
		}
		if (flr->y[2] <= i)
		{
			flr->y[2] = i;
			flr->x[2] = j;
		}
		if (flr->x[3] > j)
		{
			flr->x[3] = j;
			flr->y[3] = i;
		}
		if (flr->y[4] > i)
		{
			flr->x[4] = j;
			flr->y[4] = i;
		}
	}
	else
		scrdsec(flr, i, j, c);
}

void			ft_fillog(t_fil *flr, int i, int j)
{
	flr->x[7] = 1000;
	flr->y[8] = 1000;
	flr->x[3] = 1000;
	flr->y[4] = 1000;
	while (flr->map[i])
	{
		j = 0;
		while (flr->map[i][j])
		{
			srccrd(flr, i, j, flr->map[i][j]);
			j++;
		}
		i++;
	}
	srcclosed(flr->map, flr->me, flr);
	ft_targcoord(flr, 0);
}
