/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:43:22 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/28 17:14:18 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>

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

void	ft_draw_lines(t_vars *vars, int x, int y, int color)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = x;
	j = x;
	k = y;
	l = y;
	while (i > 500 && j < 0 && l < 0 && k > 500)
	{
		if (i > 500)
		{
			mlx_pixel_put(vars->mlx, vars->win, x, i, color);
			i++;
		}
		if (j < 0)
		{
			mlx_pixel_put(vars->mlx, vars->win, x, j, color);
			j--;
		}
		if (k > 500)
                {
                        mlx_pixel_put(vars->mlx, vars->win, k, y, color);
                        k++;
                }
		if (l < 0)
                {
                        mlx_pixel_put(vars->mlx, vars->win, l, y, color);
                        l--;
                }
	}
}


static int	ft_mouse(int keycode, int x, int y, t_vars *vars)
{
	printf("mouse_x %d, mouse_y %d keycode %d\n", vars->mouse_x, vars->mouse_y, keycode);
	//mlx_pixel_put(vars->mlx, vars->win, x, y, rand());
	ft_draw_lines(vars, x, y, rand());
	//printf("X :%d - Y :%d\n", x, y);
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
	vars->mouse_x = 250;
	vars->mouse_y = 250;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 500, 500, "bite.lolmdr");
	vars->img = mlx_new_image(vars->mlx, 500, 500);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_hook(vars->win, 17, 0L, ft_close_button, vars);
	mlx_key_hook(vars->win, ft_wich_key, vars);
	mlx_pixel_put(vars->mlx, vars->win, vars->mouse_x, vars->mouse_y, 255);
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
	return (0);
}
