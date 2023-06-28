/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:02:02 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/28 15:16:37 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_all(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->map_info)
	{
		while (i < vars->map_info->height)
		{
			free(vars->map_info->map[i]);
			i++;
		}
		free(vars->map_info->map);
		free(vars->map_info);
	}
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free (vars->mlx);
	free (vars);
	exit(1);
}
