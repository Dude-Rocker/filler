/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:37:27 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/12 16:59:53 by vgladush         ###   ########.fr       */
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

#endif

// 1 2 3 4 O right down left up
// 5 6 7 8 X -----
// 1 2 3 4 down right left up

// 4 - 5 (8 - 1) = 2
// 3 - 6 (7 - 2) = 9
