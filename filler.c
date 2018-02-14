/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 21:48:14 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/13 00:07:46 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	srcplace(t_fil *flr, int i, int j)
{
	while (flr->map[i])
	{
		while (flr->map[i][j])
		{
			if (flr->map[i][j] == 'X' || flr->map[i][j] == 'x')
			{
				flr->y[12] = 1;
				return ;
			}
			else if (flr->map[i][j] == 'O' || flr->map[i][j] == 'o')
			{
				flr->x[12] = 1;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static	void	crtpiece(t_fil *flr, char *ln)
{
	int			i;

	i = 6;
	flr->y[9] = ft_atoi(ln + i);
	while (ln[i] && ln[i] != ' ')
		i++;
	flr->x[9] = ft_atoi(ln + i);
	if (!(flr->pc = (char **)malloc(sizeof(char *) * flr->y[9] + 1)))
		return ;
	i = 0;
	while (i < flr->y[9])
	{
		get_next_line(0, &ln);
		flr->pc[i++] = ft_strdup(ln);
		free(ln);
	}
	flr->pc[i] = 0;
}

static	void	crtmap(t_fil *flr, char *ln)
{
	int			i;

	i = 8;
	flr->y[0] = ft_atoi(ln + i);
	while (ln[i] && ln[i] != ' ')
		i++;
	flr->x[0] = ft_atoi(ln + i);
	if (!(flr->map = (char **)malloc(sizeof(char *) * flr->y[0] + 1)))
		return ;
	i = 0;
	get_next_line(0, &ln);
	free(ln);
	while (i < flr->y[0])
	{
		get_next_line(0, &ln);
		flr->map[i++] = ft_strdup(ln + 4);
		free(ln);
	}
	flr->map[i] = 0;
	if (!flr->y[12] && !flr->x[12])
		srcplace(flr, 0, 0);
}

static	void	start_game(t_fil *flr, int i)
{
	char		*ln;

	ln = 0;
	while (get_next_line(0, &ln) > 0)
	{
		if (!*ln)
		{
			free(ln);
			return ;
		}
		i = 0;
		while (i < 12 && !(flr->x[i] = 0))
			flr->y[i++] = 0;
		crtmap(flr, ln);
		free(ln);
		get_next_line(0, &ln);
		crtpiece(flr, ln);
		ft_fillog(flr, 0, 0);
		free(flr->map);
		free(flr->pc);
		free(ln);
		ft_printf("%d %d\n", flr->y[11], flr->x[11]);
	}
}

int				main(void)
{
	t_fil		flr;
	char		*ln;

	get_next_line(0, &ln);
	if ((int)ft_strlen(ln) < 10 || ft_atoi(ln + 10) < 1 || ft_atoi(ln + 10) > 2)
		exit(ft_printf("Bad player info\n"));
	if (ft_atoi(ln + 10) == 1)
		flr.me = 'O';
	else
		flr.me = 'X';
	free(ln);
	flr.y[12] = 0;
	flr.x[12] = 0;
	start_game(&flr, 0);
	return (0);
}
