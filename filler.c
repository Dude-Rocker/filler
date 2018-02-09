/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 21:48:14 by anonymous         #+#    #+#             */
/*   Updated: 2018/02/09 13:17:58 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	crtpiece(t_fil *flr, char *ln)
{
	int			i;

	i =	6;
	flr->y[5] = ft_atoi(ln + i);
	while (ln[i] && ln[i] != ' ')
		i++;
	flr->x[5] = ft_atoi(ln + i);
	if (!(flr->piece = (char **)malloc(sizeof(char *) * flr->y[5] + 1)))
		return ;
	i = 0;
	while (i < flr->y[5])
	{
		get_next_line(0, &ln);
		flr->piece[i++] = ft_strdup(ln);
		free(ln);
	}
	flr->piece[i] = 0;
}

static	void	crtmap(t_fil *flr, char *ln)
{
	int			i;

	i =	8;
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
		while (i < 6 && !(flr->x[i] = 0))
			flr->y[i++] = 0;
		flr->x[3] = 1000;
		flr->y[4] = 1000;
		crtmap(flr, ln);
		free(ln);
		get_next_line(0, &ln);
		crtpiece(flr, ln);
		ft_fillog(flr, 0, 0);
		free(flr->map);
		free(flr->piece);
		free(ln);
		ft_printf("%d %d\n", flr->y[5], flr->x[5]);
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
	{
		flr.me = 'X';
		flr.en = 'O';
	}
	else
	{
		flr.me = 'O';
		flr.en = 'X';
	}
	free(ln);
	start_game(&flr, 0);
	return (0);
}
