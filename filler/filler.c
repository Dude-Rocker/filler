/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:46:06 by vgladush          #+#    #+#             */
/*   Updated: 2018/02/07 18:51:04 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(int ac, char **av)
{
	int		i;
	char	*ln;
	char	*res;
	char	c;

	i = 0;
	if (ac > 1 || read(0, 0, 0) < 0)
		printf("%s\n", "error");
	else
	{
		get_next_line(0, &ln);
		if ((int)ft_strlen(ln) < 10 || ft_atoi(ln + 10) < 1 || ft_atoi(ln + 10) > 2)
			exit(ft_printf("Bad player info\n"));
		if (ft_atoi(ln + 10) == 2)
			printf("5 10\n");
		else
			printf("1 1\n");
	}
	return (0);
}
