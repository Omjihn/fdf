/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:43:22 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/28 15:41:37 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_close_button(t_vars *vars)
{
	ft_free_all(vars);
	return (42);
}

static int	ft_wich_key(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_free_all(vars);
	printf("%d\n", keycode);
	return (0);
}

static int	ft_mouse(int keycode, t_vars *vars)
{
	int	x = 100;
	int	y = 100;
	//(void) vars;
	if (keycode == 1)
	{
        	mlx_mouse_get_pos(vars->mlx, vars->win, &x, &y);
        	//mlx_pixel_put(vars->mlx, vars->win, x, y, 100);
		printf("X :%d - Y :%d\n", x, y);
	}
        return (0);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac != 2)
		return (0);
	vars = ft_init_fdf(av);
	if (!vars)
		return (0);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 500, 500, "bite.lolmdr");
	vars->img = mlx_new_image(vars->mlx, 500, 500);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_hook(vars->win, 17, 0L, ft_close_button, vars);
	mlx_key_hook(vars->win, ft_wich_key, vars);
	mlx_mouse_hook(vars->win, ft_mouse, vars);
/*	int	i = 0;
	int	j = 0;
	while (j < vars->map_info->height)
	{
		while (i < vars->map_info->weight)
		{
			printf("%d ", vars->map_info->map[j][i].nb);
			i++;
		}
		i = 0;
		j++;
		printf ("\n");
	}*/
	mlx_loop(vars->mlx);
	ft_free_all(vars);
}
