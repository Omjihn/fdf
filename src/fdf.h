/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:54:49 by gbricot           #+#    #+#             */
/*   Updated: 2023/07/07 16:03:43 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/ft_printf.h"
# include "../gnl/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <stddef.h>
# include <limits.h>

# define WIN_L 600
# define WIN_H 600

# define PADDING_L 100
# define PADDING_H 100
# define ANGLE 0.80

# define BUFFER 500

typedef struct s_node
{
	int	nb;
	int	color;
}			t_node;

typedef struct s_map
{
	int	height;
	int	weight;
	t_node	**map;
}			t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	int	click;
	int	mouse_x;
	int	mouse_y;
	int	zoom;
	int	marging_x;
	int	marging_y;
	int     win_l;
	int     win_h;
	t_map	*map_info;
}			t_vars;

int		ft_count_weight(char *line);
int		ft_atoi_base(char *nb);

/*		HOOKS		*/

int		ft_close_button(t_vars *vars);
int		ft_wich_key(int keycode, t_vars *vars);
int		ft_mouse(int keycode, int x, int y, t_vars *vars);

void	ft_draw_octant_0(float x1, float y1, float x2, float y2, t_vars *vars);
void    ft_draw_octant_1(float x1, float y1, float x2, float y2, t_vars *vars);
void	ft_draw_octant_6(float x1, float y1, float x2, float y2, t_vars *vars);
void	ft_draw_octant_7(float x1, float y1, float x2, float y2, t_vars *vars);
void	ft_draw(t_vars *vars);
void	ft_draw_lines(t_vars *vars, int x, int y, int color);
void	ft_isometric(float *x, float *y, int z);
void	ft_translation(int keycode, t_vars *vars);
void	ft_free_all(t_vars *vars);

t_node	*ft_create_node_list(char *line, t_map *map_info);
t_node	**ft_add_data(t_node *data, t_node **tab, t_map *map_info);
t_node	**ft_read_map(int fd, char *line, t_map *map_info);

t_map	*ft_init_map(char **av);

t_vars	*ft_init_fdf(char **av);

#endif
