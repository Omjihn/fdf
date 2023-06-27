/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:43:22 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/27 16:14:58 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_vars	*vars;

	vars = ft_init_fdf(ac, av);
	if (!vars)
		return (0);
	int	i = 0;
	int	j = 0;
	while (vars->map->map[j])
	{
		while (vars->map->map[j][i].nb)
		{
			printf ("%d ",vars->map->map[j][i].nb);
			i++;
		}
		printf ("\n");
	}
}
