/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:43:40 by gbricot           #+#    #+#             */
/*   Updated: 2023/07/18 06:58:31 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_weight(char *line)
{
	int	i;
	int	in_word;
	int	words;

	i = 0;
	in_word = 0;
	words = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ' ' && in_word == 1)
			in_word = 0;
		if (line[i] != ' ')
		{
			if (in_word == 0)
			{
				in_word = 1;
				words++;
			}
		}
		i++;
	}
	return (words);
}			

t_node	*ft_create_node_list(char *line, t_map *map_info)
{
	int		i;
	int		tab;
	t_node	*res;

	res = calloc (map_info->weight, sizeof(t_node));
	i = 0;
	tab = 0;
	while (line[i])
	{
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
		{
			res[tab].nb = atoi(line + i);
			while ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
				i++;
			if (line[i] == ',')
			{
				res[tab].color = ft_atoi_base(line + i + 1);
				while (line[i] != ' ' && line[i] != '\n')
					i++;
			}
			tab++;
		}
		i++;
	}
	return (res);
}

t_node	**ft_add_data(t_node *data, t_node **tab, t_map *map_info)
{
	int		i;
	t_node	**new_tab;

	new_tab = calloc (map_info->height + 1, sizeof(t_node *));
	i = 0;
	while (i < map_info->height)
	{
		new_tab[i] = tab[i];
		i++;
	}
	new_tab[i] = data;
	free(tab);
	return (new_tab);
}

t_node	**ft_read_map(int fd, char *line, t_map *map_info)
{
	t_node	**tab;
	t_node	*data;

	data = ft_create_node_list(line, map_info);
	tab = (t_node **) calloc (2, sizeof(t_node **));
	tab[0] = data;
	map_info->height++;
	free (line);
	line = get_next_line(fd);
	while (line)
	{
		data = ft_create_node_list(line, map_info);
		tab = ft_add_data(data, tab, map_info);
		map_info->height++;
		free(line);
		line = get_next_line(fd);
	}
	return (tab);
}

t_map	*ft_init_map(char **av)
{
	int		fd;
	char	*line;
	t_map	*map_info;

	map_info = calloc (sizeof(t_map), 1);
	if (!map_info)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	map_info->weight = ft_count_weight(line);
	map_info->map = ft_read_map(fd, line, map_info);
	return (map_info);
}

static void	ft_calculate_zoom_win(t_vars *vars)
{
	if (vars->map_info->height >= 200 || vars->map_info->weight >= 200)
		vars->zoom = 5;
	else if (vars->map_info->height >= 50 || vars->map_info->weight >= 50)
		vars->zoom = 10;
	else if  (vars->map_info->height >= 30 || vars->map_info->weight >= 30)
		vars->zoom = 20;
	else
		vars->zoom = 50;
	vars->win_l = (vars->map_info->height * vars->zoom) + PADDING_L;
	vars->win_h = (vars->map_info->weight * vars->zoom) + PADDING_H;
}

t_vars	*ft_init_fdf(char **av)
{
	t_vars	*vars;

	vars = calloc(sizeof(t_vars), 1);
	if (!vars)
		return (NULL);
	vars->map_info = ft_init_map(av);
	vars->angle = 0.8;
	vars->color = INT_MAX;
	if (!vars->map_info)
	{
		free(vars);
		return (NULL);
	}
	ft_calculate_zoom_win(vars);
	return (vars);
}
