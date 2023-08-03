
#include "fdf.h"

void	ft_create_image(t_vars *vars)
{
	if (vars->img.addr)
		mlx_destroy_image(vars->mlx, vars->img.mlx_img);
	vars->img.mlx_img = mlx_new_image(vars->mlx, vars->win_l, vars->win_l);
	vars->img.addr = mlx_get_data_addr(vars->img.mlx_img, \
			&vars->img.bpp,	&vars->img.line_len, \
			&vars->img.endian);
}


