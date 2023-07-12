
#include "fdf.h"

int	ft_close_button(t_vars *vars)
{
	ft_free_all(vars);
	return (0);
}

int	ft_wich_key(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_free_all(vars);
	if (keycode == 119 || keycode == 97 || keycode == 115 
			|| keycode == 100 || keycode == 65362
			|| keycode == 65361 || keycode == 65364
			|| keycode == 65363)
	{
		mlx_clear_window(vars->mlx, vars->win);
		ft_translation(keycode, vars);
	}
	printf("%d\n", keycode);
	return (0);
}

int	ft_mouse(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == 4 || keycode == 5)
		ft_draw_lines(vars, x, y, rand());
        return (0);
}
