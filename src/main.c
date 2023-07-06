/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:43:22 by gbricot           #+#    #+#             */
/*   Updated: 2023/07/06 19:03:29 by gbricot          ###   ########.fr       */
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

void	ft_draw_vector(int x1, int y1, int x2, int y2, t_vars *vars)
{
	int	temp;

	if (x1 > x2)
	{
		temp = x2;
		x2 = x1;
		x1 = temp;
		temp = y2;
		y2 = y1;
		y1 = temp;
	}
	if (x1 < x2 && y1 <= y2 && (x1 - x2) <= (y1 - y2))
	{
		printf("Octant 0\n");
		ft_draw_octant_0(x1, y1, x2, y2, vars);
	}
	else if (x1 <= x2 && y1 <= y2 && (x1 - x2) > (y1 - y2))
	{
		printf("Octant 1\n");
		ft_draw_octant_1(x1, y1, x2, y2, vars);
	}
	else if (x1 < x2 && y1 >= y2 && (x1 - x2) > (y2 - y1))
	{
		printf("Octant 6\n");
		ft_draw_octant_6(x1, y1, x2, y2, vars);
	}
	else if (x1 < x2 && y1 >= y2 && (x1 - x2) < (y2 - y1))
	{
		printf("Octant 7\n");
		ft_draw_octant_7(x1, y1, x2, y2, vars);
	}
}

static int	ft_mouse(int keycode, int x, int y, t_vars *vars)
{
	//printf("mouse_x %d, mouse_y %d keycode %d\n", vars->mouse_x, vars->mouse_y, keycode);
	if (keycode == 4 || keycode == 5)
		ft_draw_lines(vars, x, y, rand());
        return (0);
}

void	ft_draw(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->map_info->height)
	{
		x = 0;
		while (x < vars->map_info->weight)
		{
			ft_draw_vector(x, y, x + 1, y, vars);
			ft_draw_vector(x, y, x, y + 1, vars);
			x++;
		}
		y++;
	}
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
	ft_draw(vars);
/*	int	i = 0;
	int	j = 0;
	while (j < vars->map_info->height)
	{
		while (i < vars->map_info->weight)
		{
			printf("%d ", vars->map_info->map[j][i].nb);

//			if (vars->map_info->map[j][i].color != 0)
				//printf(", %d ", vars->map_info->map[j][i].color);
			i++;
		}
		i = 0;
		j++;
		printf ("\n");
	}*/
	mlx_loop(vars->mlx);
	return (0);
}
