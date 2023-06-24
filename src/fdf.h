
#ifndef FDF_H
# define FDF_H

#include "fdf.h"
# include "../lib/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

typedef struct s_node
{
	char	nb;
	int	color;
}			t_node;

typedef struct s_vars
{
	t_node	**map;

}			t_vars;

#endif
