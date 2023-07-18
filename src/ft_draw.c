
#include "fdf.h"

// a reintegrer
void	ft_isometric(float *x, float *y, int z, t_vars *vars)
{
	*x = (*x - *y) * cos(vars->angle);
	*y = (*x + *y) * sin(vars->angle) - z;
}

void	ft_draw_vector(float x1, float y1, float x2, float y2, t_vars *vars)
{
	float	temp;
	int	z1 = vars->map_info->map[(int) y1][(int) x1].nb;
	int	z2 = vars->map_info->map[(int) y2][(int) x2].nb;


	ft_isometric(&x1, &y1, z1, vars);
	ft_isometric(&x2, &y2, z2, vars);
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
		ft_draw_octant_0(x1, y1, x2, y2, vars);
	else if (x1 <= x2 && y1 <= y2 && (x1 - x2) > (y1 - y2))
		ft_draw_octant_1(x1, y1, x2, y2, vars);
	else if (x1 < x2 && y1 >= y2 && (x1 - x2) > (y2 - y1))
		ft_draw_octant_6(x1, y1, x2, y2, vars);
	else if (x1 < x2 && y1 >= y2 && (x1 - x2) < (y2 - y1))
		ft_draw_octant_7(x1, y1, x2, y2, vars);
}

void	ft_draw(t_vars *vars)
{
	float	x;
	float	y;

	y = 0.0;
	while (y < vars->map_info->height)
	{
		x = 0.0;
		while (x < vars->map_info->weight)
		{
			if (x + 1.0 != vars->map_info->weight)
				ft_draw_vector(x, y, x + 1.0, y, vars);
			if (y + 1.0 != vars->map_info->height)
				ft_draw_vector(x, y, x, y + 1.0, vars);
			x += 1.0;
		}
		y++;
	}
}
