/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:37:27 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/13 19:11:51 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft.h"

typedef	struct	s_fil
{
	char		me;
	int			x[13];
	int			y[13];
	char		**map;
	char		**pc;
}				t_fil;

void			ft_fillog(t_fil *flr, int i, int j);
void			ft_targcoord(t_fil *f, int i, int r);
int				check_coord(t_fil *f, int x, int y, int t);
void			crcd_left_dw(t_fil *f, int x, int y);
void			crcd_up_rg(t_fil *f, int x, int y);
void			crcd_down_lf(t_fil *f, int x, int y);
void			crcd_right_up(t_fil *f, int x, int y);
void			crcd_left_up(t_fil *f, int x, int y);

#endif

// 1 2 3 4 O right down left up
// 5 6 7 8 X -----
// 1 2 3 4 down right left up
