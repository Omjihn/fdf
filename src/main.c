/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:43:22 by gbricot           #+#    #+#             */
/*   Updated: 2023/07/07 16:31:59 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac != 2)
		return (0);
	vars = ft_init_fdf(av);
	if (!vars)
		return (0);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_L, WIN_H, "Aife Des Heifent\n");
	vars->img = mlx_new_image(vars->mlx, WIN_L, WIN_H);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_hook(vars->win, 17, 0L, ft_close_button, vars);
	mlx_key_hook(vars->win, ft_wich_key, vars);
	mlx_mouse_hook(vars->win, ft_mouse, vars);
	ft_draw(vars);
/*	int	i = 0;
	int	j = 0;
	while (j < vars->map_info->height)
	{
		while (i < vars->map_info->weight)
		{
			printf("%d ", vars->map_info->map[j][i].nb);

			if (vars->map_info->map[j][i].color != 0)
				printf(", %d ", vars->map_info->map[j][i].color);
			i++;
		}
		i = 0;
		j++;
		printf ("\n");
	}*/
	mlx_loop(vars->mlx);
	return (0);
}
