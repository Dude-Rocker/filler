/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:22:06 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/11 23:58:44 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
			flr->x[10] = 1;
	j = -1;
	k--;
	while (s[k][++j])
		if (s[k][j] == c)
			flr->y[10] = 1;
	k = -1;
	while (s[++k])
		if (s[k][0] == c)
			flr->y[10] = 1;
}

static	void	whtfigur(char **s, int i, int j, t_fil *flr)
{
	while (s[i])
	{
		while (s[i][j])
		{
			if (s[i][j] == '*' && (flr->x[9] += 1))
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
			if (s[i][j] == '*' && (flr->y[9] += 1))
				break ;
			i++;
		}
		i = 0;
		j++;
	}
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
	if (c == 'o' || c == 'O')
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
	int			h;

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
	whtfigur(flr->pc, 0, 0, flr);
	if (flr->x[9] > 1 && flr->y[9] > 1)
		h = 0;
	else if (flr->x[9] > 1)
		h = 1;
	else
		h = 2;
	srcclosed(flr->map, flr->me, flr);
	ft_targcoord(flr, h, 0);
}
