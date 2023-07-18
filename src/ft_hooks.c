/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 04:32:31 by gbricot           #+#    #+#             */
/*   Updated: 2023/07/18 04:32:34 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else if (keycode == 119 || keycode == 97 || keycode == 115 
			|| keycode == 100 || keycode == 65362
			|| keycode == 65361 || keycode == 65364
			|| keycode == 65363)
	{
		mlx_clear_window(vars->mlx, vars->win);
		ft_translation(keycode, vars);
	}
	else if (keycode == 113 || keycode == 101)
	{
		if (keycode == 113)
			vars->angle -= 0.05;
		else
			vars->angle += 0.05;
		mlx_clear_window(vars->mlx, vars->win);
		ft_draw(vars);
	}
	printf("%d\n", keycode);
	return (0);
}

int	ft_mouse(int keycode, int x, int y, t_vars *vars)
{
	(void) x;
	(void) y;
	if (keycode == 4 || (keycode == 5 && vars->zoom >= 5))
	{
		if (keycode == 4)
			vars->zoom += 2;
		else if (keycode == 5)
			vars->zoom -= 2;
		mlx_clear_window(vars->mlx, vars->win);
		ft_draw(vars);
	}
        return (0);
}
