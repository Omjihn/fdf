/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:43:22 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/29 13:07:32 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>

static int	ft_close_button(t_vars *vars)
{
	ft_free_all(vars);
	return (0);
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
	while (i < WIN_H || j > 0 || l > 0 || k < WIN_L)
	{
		if (i < WIN_H)
		{
			mlx_pixel_put(vars->mlx, vars->win, x, i, color);
			i++;
		}
		if (j > 0)
		{
			mlx_pixel_put(vars->mlx, vars->win, x, j, color);
			j--;
		}
		if (k < WIN_L)
                {
                        mlx_pixel_put(vars->mlx, vars->win, k, y, color);
                        k++;
                }
		if (l > 0)
                {
                        mlx_pixel_put(vars->mlx, vars->win, l, y, color);
                        l--;
                }
	}
}

void	ft_draw_vector(int x2, int y2, t_vars *vars)
{
	if (vars->click == 0)
	{
		vars->mouse_x = x2;
		vars->mouse_y = y2;
		vars->click = 1;
	}
	else if (vars->mouse_x < x2 && vars->mouse_y <= y2
			 && (vars->mouse_x - x2) < (vars->mouse_y - y2))
	{
		printf("Octant 0\n");
		ft_draw_octant_0(x2, y2, vars);
	}
	else if (vars->mouse_x < x2 && vars->mouse_y <= y2
			&& (vars->mouse_x - x2) > (vars->mouse_y - y2))
	{
		printf("Octant 1\n");
		ft_draw_octant_1(x2, y2, vars);
	}
	else if (vars->mouse_x < x2 && vars->mouse_y >= y2
                        && (x2 - vars->mouse_x) > (y2 - vars->mouse_y))
	{
		printf("Octant 6\n");
		ft_draw_octant_6(x2, y2, vars);
	}
	else if (vars->mouse_x < x2 && vars->mouse_y >= y2
			&& (x2 - vars->mouse_x) < (y2 - vars->mouse_y))
	{
		printf("Octant 7\n");
		ft_draw_octant_7(x2, y2, vars);
	}
	else
		vars->click = 0;
}

static int	ft_mouse(int keycode, int x, int y, t_vars *vars)
{
	//printf("mouse_x %d, mouse_y %d keycode %d\n", vars->mouse_x, vars->mouse_y, keycode);
	if (keycode == 4 || keycode == 5)
		ft_draw_lines(vars, x, y, rand());
	if (keycode == 1)
		ft_draw_vector(x, y, vars);
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
	vars->win = mlx_new_window(vars->mlx, WIN_L, WIN_H, "Aife Des Heifent\n");
	vars->img = mlx_new_image(vars->mlx, WIN_L, WIN_H);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_hook(vars->win, 17, 0L, ft_close_button, vars);
	mlx_key_hook(vars->win, ft_wich_key, vars);
	mlx_mouse_hook(vars->win, ft_mouse, vars);
	int	i = 0;
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
	}
	mlx_loop(vars->mlx);
	return (0);
}
