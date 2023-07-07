/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_algos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:27:28 by gbricot           #+#    #+#             */
/*   Updated: 2023/07/07 12:59:45 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_octant_0(float x1, float y1, float x2, float y2, t_vars *vars)
{
        float   error;
        float   slope;

	x1 *= vars->zoom;
	x2 *= vars->zoom;
	y1 *= vars->zoom;
	y2 *= vars->zoom;
	printf (" x1:%f - y1:%f | x2:%f - y2:%f\n", x1, y1, x2, y2);
	error = 0.0;
	slope = (float) (y2 - y1) / (float) (x2 - x1);
	while (x1 <= x2)
	{
		mlx_pixel_put(vars->mlx, vars->win, x1 + PADDING, y1 + PADDING, INT_MAX);
		error += slope;
		if (error >= 0.5)
		{
			y1++;
			error -= 1.0;
		}
		x1++;
	}
}

void	ft_draw_octant_1(float x1, float y1, float x2, float y2, t_vars *vars)
{
	float	error;
	float	slope;

	x1 *= vars->zoom;
        x2 *= vars->zoom;
        y1 *= vars->zoom;
        y2 *= vars->zoom;
	printf (" x1:%f - y1:%f | x2:%f - y2:%f\n", x1, y1, x2, y2);
	error = 0.0;
	slope = (float) (x2 - x1) / (float) (y2 - y1);
	while (y1 <= y2)
	{
		mlx_pixel_put(vars->mlx, vars->win, x1 + PADDING, y1 + PADDING, INT_MAX);
		error += slope;
		if (error >= 0.5)
		{
			x1++;
			error -= 1.0;
		}
		y1++;
	}
}

void	ft_draw_octant_6(float x1, float y1, float x2, float y2, t_vars *vars)
{
	float	error;
	float	slope;

	x1 *= vars->zoom;
        x2 *= vars->zoom;
        y1 *= vars->zoom;
        y2 *= vars->zoom;
	printf (" x1:%f - y1:%f | x2:%f - y2:%f\n", x1, y1, x2, y2);
	error = 0.0;
	slope = (float) (x2 - x1) / (float) (y1 - y2);
	while (y1 >= y2)
	{
		mlx_pixel_put(vars->mlx, vars->win, x1 + PADDING, y1 + PADDING, INT_MAX);
		error += slope;
		if (error >= 0.5)
		{
			x1++;
			error -= 1.0;
		}
		y1--;
	}
}

void	ft_draw_octant_7(float x1, float y1, float x2, float y2, t_vars *vars)
{
	float	error;
	float	slope;

	x1 *= vars->zoom;
        x2 *= vars->zoom;
        y1 *= vars->zoom;
        y2 *= vars->zoom;
	printf (" x1:%f - y1:%f | x2:%f - y2:%f\n", x1, y1, x2, y2);
	error = 0.0;
	slope = (float) (y1 - y2) / (float) (x2 - x1);
	while (x1 <= x2)
	{
		mlx_pixel_put(vars->mlx, vars->win, x1 + PADDING, y1 + PADDING, INT_MAX);
		error += slope;
		if (error >= 0.5)
		{
			y1--;
			error -= 1.0;
		}
		x1++;
	}
}
