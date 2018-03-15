/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 22:52:05 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/15 02:48:49 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static	char	*fil_players(char *ln, int i, char *pl1, int j)
{
	char		*pl2;

	while (ln[i] && ln[i] != '.')
		i++;
	pl1 = ft_strnew(i - 21);
	i = 23;
	while (ln[i] && ln[i] != '.')
		pl1[j++] = ln[i++];
	pl1[j] = '\n';
	pl1 = ft_joinfree("\x1B[32mplayer1: 🌲 ", pl1, 2);
	free(ln);
	get_next_line(0, &ln);
	free(ln);
	get_next_line(0, &ln);
	i = 23;
	while (ln[i] && ln[i] != '.')
		i++;
	pl2 = ft_strnew(i - 22);
	i = 23;
	j = 0;
	while (ln[i] && ln[i] != '.')
		pl2[j++] = ln[i++];
	pl2 = ft_joinfree("\x1B[31mplayer2: 🔥 ", pl2, 2);
	free(ln);
	return (ft_joinfree(pl1, pl2, 2));
}

static	void	ft_vis_map(char *ln, char **hd, char *pl, int i)
{
	if (ln[0] != 'P' || ln[3] != 't')
		return ;
	system("clear");
	ft_printf("\x1B[36m");
	while (hd[i])
		ft_printf("%s\n", hd[i++]);
	ft_printf("%s\n\n", pl);
	get_next_line(0, &ln);
	while (*ln != 'P')
	{
		i = -1;
		while (ln[++i])
		{
			if (ln[i] == 'o' || ln[i] == 'O')
				ft_printf("\x1B[32m🌲");
			else if (ln[i] == 'x' || ln[i] == 'X')
				ft_printf("\x1B[31m🔥");
			else
				ft_printf("\x1B[33m%c", ln[i]);
		}
		ft_printf("\n");
		free(ln);
		get_next_line(0, &ln);
	}
}
static	void	put_res(char *pl, int i, int j, int z)
{
	int			o;
	int			p;

	while (pl[o++] != ' ')
		;
	while (pl[p] != '\n')
		p++;
	if (i > j)
		ft_printf("\n%s%.*s %swon with %d points (%s%s %s%d)\n", "\x1B[32m",
			p - o, pl + o, "\x1B[33m", i, "\x1B[31m", pl + z, "\x1B[33m", j);
	else
		ft_printf("\n%s%s %swon with %d points (%s%.*s %s%d)\n", "\x1B[31m",
			pl + z, "\x1B[33m", j, "\x1B[32m", p - o, pl + o, "\x1B[33m", i);

}

static	void	ft_vis_end(char *ln, char *pl, int z, int o)
{
	int			i;
	int			j;
	int			r;

	if (ln[0] != '=')
		return ;
	i = ft_atoi(ln + 10);
	get_next_line(0, &ln);
	j = ft_atoi(ln + 10);
	free(ln);
	while (pl[o++] != ' ')
		;
	while (pl[z] != '\n')
		z++;
	r = z;
	while (pl[z++] != ' ')
		;
	if (i == j)
		ft_printf("\n%sdead heat %s%.*s %s& %s%s %sscored %d points each\n",
			"\x1B[33m", "\x1B[32m", r - o, pl + o, "\x1B[33m", "\x1B[31m",
			pl + z, "\x1B[33m", i);
	else
		put_res(pl, i, j, z);
}

int				main(void)
{
	char		*ln;
	char		**hd;
	char		*pl;
	int			i;

	i = 0;
	if (!(hd = (char **)malloc(sizeof(char *))))
		return (0);
	while (get_next_line(0, &ln))
	{
		if (*ln != '#')
			break ;
		hd[i++] = ft_strdup(ln);
	}
	hd[i] = 0;
	free(ln);
	get_next_line(0, &ln);
	pl = fil_players(ln, 23, 0, 0);
	while (get_next_line(0, &ln) > 0)
	{
		ft_vis_map(ln, hd, pl, 0);
		ft_vis_end(ln, pl, 0, 0);
		free(ln);
	}
	return (0);
}
