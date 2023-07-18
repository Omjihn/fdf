/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_algos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:27:28 by gbricot           #+#    #+#             */
/*   Updated: 2023/07/18 04:04:09 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_octant_0(float x1, float y1, float x2, float y2, t_vars *vars)
{
	float	error;
	float	slope;

	x1 = (x1 * vars->zoom) + vars->marging_x;
	x2 = (x2 * vars->zoom) + vars->marging_x;
	y1 = (y1 * vars->zoom) + vars->marging_y;
	y2 = (y2 * vars->zoom) + vars->marging_y;
	error = 0.0;
	slope = (float) (y2 - y1) / (float) (x2 - x1);
	while (x1 <= x2)
	{
		if (x1 + PADDING_L >= 0 && x1 + PADDING_L <= vars->win_l
				&& y1 + PADDING_H >= 0 && y1 +  PADDING_H <= vars->win_h)
			mlx_pixel_put(vars->mlx, vars->win, x1 + PADDING_L, y1 + PADDING_H, INT_MAX);
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

	x1 = (x1 * vars->zoom) + vars->marging_x;
	x2 = (x2 * vars->zoom) + vars->marging_x;
	y1 = (y1 * vars->zoom) + vars->marging_y;
	y2 = (y2 * vars->zoom) + vars->marging_y;
	error = 0.0;
	slope = (float) (x2 - x1) / (float) (y2 - y1);
	while (y1 <= y2)
	{
		if (x1 + PADDING_L >= 0 && x1 + PADDING_L <= vars->win_l
				&& y1 + PADDING_H >= 0 && y1 +  PADDING_H <= vars->win_h)
			mlx_pixel_put(vars->mlx, vars->win, x1 + PADDING_L, y1 + PADDING_H, INT_MAX);
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

	x1 = (x1 * vars->zoom) + vars->marging_x;
	x2 = (x2 * vars->zoom) + vars->marging_x;
	y1 = (y1 * vars->zoom) + vars->marging_y;
	y2 = (y2 * vars->zoom) + vars->marging_y;
	error = 0.0;
	slope = (float) (x2 - x1) / (float) (y1 - y2);
	while (y1 >= y2)
	{
		if (x1 + PADDING_L >= 0 && x1 + PADDING_L <= vars->win_l
				&& y1 + PADDING_H >= 0 && y1 +  PADDING_H <= vars->win_h)
			mlx_pixel_put(vars->mlx, vars->win, x1 + PADDING_L, y1 + PADDING_H, INT_MAX);
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

	x1 = (x1 * vars->zoom) + vars->marging_x;
	x2 = (x2 * vars->zoom) + vars->marging_x;
	y1 = (y1 * vars->zoom) + vars->marging_y;
	y2 = (y2 * vars->zoom) + vars->marging_y;
	error = 0.0;
	slope = (float) (y1 - y2) / (float) (x2 - x1);
	while (x1 <= x2)
	{
		if (x1 + PADDING_L >= 0 && x1 + PADDING_L <= vars->win_l
				&& y1 + PADDING_H >= 0 && y1 +  PADDING_H <= vars->win_h)
			mlx_pixel_put(vars->mlx, vars->win, x1 + PADDING_L, y1 + PADDING_H, INT_MAX);
		error += slope;
		if (error >= 0.5)
		{
			y1--;
			error -= 1.0;
		}
		x1++;
	}
}
