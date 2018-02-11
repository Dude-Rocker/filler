/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:37:27 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/12 00:18:48 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_FILLER
# define FT_FILLER

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
void			ft_targcoord(t_fil *flr, int h, int i);

#endif

// 1 2 3 4 O right down left up
// 5 6 7 8 X -----