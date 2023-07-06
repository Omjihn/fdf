/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_algos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:27:28 by gbricot           #+#    #+#             */
/*   Updated: 2023/07/06 19:07:24 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_octant_0(int x1, int y1, int x2, int y2, t_vars *vars)
{
	int		color;
        float   error;
        float   slope;

	x1 *= vars->zoom;
	x2 *= vars->zoom;
	y1 *= vars->zoom;
	y2 *= vars->zoom;

	color = vars->map_info->map[x1][y1].color;
	if (color == 0)
		color = INT_MAX;

	error = 0.0;
	slope = (float) (y2 - y1) / (float) (x2 - x1);
	while (x1 <= x2)
	{
		mlx_pixel_put(vars->mlx, vars->win, x1, y1, color);
		error += slope;
		if (error >= 0.5)
		{
			y1++;
			error -= 1.0;
		}
		x1++;
	}
}

void	ft_draw_octant_1(int x1, int y1, int x2, int y2, t_vars *vars)
{
	int		color;
	float	error;
	float	slope;

	x1 *= vars->zoom;
        x2 *= vars->zoom;
        y1 *= vars->zoom;
        y2 *= vars->zoom;

	color = vars->map_info->map[x1][y1].color;
        if (color == 0)
                color = INT_MAX;

	error = 0.0;
	slope = (float) (x2 - x1) / (float) (y2 - y1);
	while (y1 <= y2)
	{
		mlx_pixel_put(vars->mlx, vars->win, x1, y1, color);
		error += slope;
		if (error >= 0.5)
		{
			x1++;
			error -= 1.0;
		}
		y1++;
	}
}

void	ft_draw_octant_6(int x1, int y1, int x2, int y2, t_vars *vars)
{
	float	error;
	float	slope;

	x1 *= vars->zoom;
        x2 *= vars->zoom;
        y1 *= vars->zoom;
        y2 *= vars->zoom;

	error = 0.0;
	slope = (float) (x2 - x1) / (float) (y1 - y2);
	while (y1 >= y2)
	{
		mlx_pixel_put(vars->mlx, vars->win, x1, y1, INT_MAX);
		error += slope;
		if (error >= 0.5)
		{
			x1++;
			error -= 1.0;
		}
		y1--;
	}
}

void	ft_draw_octant_7(int x1, int y1, int x2, int y2, t_vars *vars)
{
	float	error;
	float	slope;

	x1 *= vars->zoom;
        x2 *= vars->zoom;
        y1 *= vars->zoom;
        y2 *= vars->zoom;

	error = 0.0;
	slope = (float) (y1 - y2) / (float) (x2 - x1);
	while (x1 <= x2)
	{
		mlx_pixel_put(vars->mlx, vars->win, x1, y1, INT_MAX);
		error += slope;
		if (error >= 0.5)
		{
			y1--;
			error -= 1.0;
		}
		x1++;
	}
}
