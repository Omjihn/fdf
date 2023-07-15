
#include "fdf.h"

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
	while (i < vars->win_h || j > 0 || l > 0 || k < vars->win_l)
	{
		if (i < vars->win_h)
		{
			mlx_pixel_put(vars->mlx, vars->win, x, i, color);
			i++;
		}
		if (j > 0)
		{
			mlx_pixel_put(vars->mlx, vars->win, x, j, color);
			j--;
		}
		if (k < vars->win_l)
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

// a reintegrer
void	ft_isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(ANGLE);
	*y = (*x + *y) * sin(ANGLE) - z;
}

void	ft_draw_vector(float x1, float y1, float x2, float y2, t_vars *vars)
{
	float	temp;
	int	z1 = vars->map_info->map[(int) y1][(int) x1].nb;
	int	z2 = vars->map_info->map[(int) y2][(int) x2].nb;


	ft_isometric(&x1, &y1, z1);
	ft_isometric(&x2, &y2, z2);
/*	x1 = (x1 - y1) * cos(ANGLE);
	y1 = (x1 + y1) * sin(ANGLE) - z1;
	x2 = (x2 - y2) * cos(ANGLE);
        y2 = (x2 + y2) * sin(ANGLE) - z2;*/
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
