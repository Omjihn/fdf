
#include "fdf.h"

void	ft_draw_octant_0(int x2, int y2, t_vars *vars)
{
        float   error;
        float   slope;
        float   y1;
        int     x1;

	error = 0.0;
	slope = (float) (y2- vars->mouse_y) / (float) (x2 - vars->mouse_x);
	x1 = vars->mouse_y;
	y1 = vars->mouse_x;
	while (x1 <= x2)
	{
		mlx_pixel_put(vars->mlx, vars->win, x1, y1, INT_MAX);
		error += slope;
		if (error >= 0.5)
		{
			y1++;
			error -= 1.0;
		}
		x1++;
	}
	vars->click = 0;
}

void	ft_draw_octant_1(int x2, int y2, t_vars *vars)
{
	float	error;
	float	slope;
	float	y1;
	int	x1;

	error = 0.0;
	slope = (float) (y2- vars->mouse_y) / (float) (x2 - vars->mouse_x);
	y1 = vars->mouse_y;
	x1 = vars->mouse_x;
	while (y1 <= y2)
	{
		mlx_pixel_put(vars->mlx, vars->win, x1, y1, INT_MAX);
		error += slope;
		if (error >= 0.5)
		{
			x1++;
			error -= 1.0;
		}
		y1++;
	}
	vars->click = 0;
}
