/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:54:49 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/27 13:35:37 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/ft_printf.h"
# include "../gnl/gwet_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFFER 500

typedef struct s_node
{
	char	nb;
	int	color;
	t_node	*next;
}			t_node;

typedef struct s_map
{
	int	height;
	int	weight;
	t_node	**map;
}			t_map;

typedef struct s_vars
{
	t_map	*map;		
}			t_vars;

#endif
