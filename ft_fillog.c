/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:22:06 by anonymous         #+#    #+#             */
/*   Updated: 2018/02/09 18:36:16 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	targcoord(t_fil *flr, int i, int xy)
{
	int			j;

	j = 0;
	if (xy[0] && xy[1])
		j = 3;
	else if (xy[0])
		j = 1;
	else if (xy[1])
		j = 2;
}

static	void	srcclosed(char **s, char c, int *i)
{
	int			j;
	int			k;

	i[0] = 0;
	i[1] = 0;
	j = -1;
	k = -1;
	while (s[0][++j])
		if (s[0][j] == c)
			i[0] = 1;
	j--;
	while (s[++k])
		if (s[k][j] == c)
			i[0] = 1;
	j = -1;
	k--;
	while (s[k][++j])
		if (s[k][j] == c)
			i[1] = 1;
	k = -1;
	while (s[++k])
		if (s[k][0] == c)
			i[1] = 1;
}

static	void	whtfigur(char **s, int i, int j, int *xy)
{
	while (s[i])
	{
		while (s[i][j])
		{
			if (s[i][j] == '*' && (xy[0] += 1))
				break ;
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	while (s[i][j])
	{
		while (s[i])
		{
			if (s[i][j] == '*' && (xy[1] += 1))
				break ;
			i++;
		}
		i = 0;
		j++;
	}
}

static	void	srccrd(t_fil *flr, int i, int j, char c)
{
	if (c == '.')
		return ;
	if ((c == 'o' || c == 'O') && flr->x[1] <= j)
	{
		flr->x[1] = j;
		flr->y[1] = i;
	}
	if ((c == 'o' || c == 'O') && flr->y[2] <= i)
	{
		flr->y[2] = i;
		flr->x[2] = j;
	}
	if ((c == 'x' || c == 'X') && flr->x[3] > j)
	{
		flr->x[3] = j;
		flr->y[3] = i;
	}
	if ((c == 'x' || c == 'X') && flr->y[4] > i)
	{
		flr->x[4] = j;
		flr->y[4] = i;
	}
}

void			ft_fillog(t_fil *flr, int i, int j)
{
	int			xy[2];
	int			h;

	xy[0] = 0;
	xy[1] = 0;
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
	whtfigur(flr->piece, 0, 0, xy);
	if (xy[0] > xy[1])
		h = 1;
	else if (xy[0] < xy[1])
		h = 2;
	else
		h = 0;
	srcclosed(flr->map, flr->me, xy);
	targcoord(flr, h, xy);
}
