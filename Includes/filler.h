/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:37:27 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/08 23:10:03 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_FILLER
# define FT_FILLER

# include "libft.h"

typedef	struct	s_fil
{
	char		en;
	char		me;
	int			x[6];
	int			y[6];
	char		**map;
	char		**piece;
}				t_fil;

void			ft_fillog(t_fil *flr, int i, int j);

#endif
