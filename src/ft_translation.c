/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:08:26 by gbricot           #+#    #+#             */
/*   Updated: 2023/07/18 04:19:03 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* keycodes:  119 = w | 97 = a | 115 = s | 100 = d 
*/

void	ft_translation(int keycode, t_vars *vars)
{
	if (keycode == 115 || keycode == 65364)
		vars->marging_y -= 20;
	else if (keycode == 100 || keycode == 65363)
		vars->marging_x -= 20;
	else if (keycode == 119 || keycode == 65362)
		vars->marging_y += 20;
	else
		vars->marging_x += 20;
	ft_draw(vars);
}
