/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:43:40 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/27 17:49:47 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_get_weight(char *line)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			j++;
		i++;
	}
	return (j);
}

t_node	*ft_export_data(char *line, t_map *map)
{
	int		i;
	int		j;
	t_node		*data;

	data = calloc(sizeof(t_node), map->weight + 1);
	i = 0;
	j = 0;
	while (line[i])
	{
		data[j].nb = atoi(line + i);
		while (line[i] < '9' && line[i] > '0')
			i++;
		if (line[i] == ',')
		{
			//data[j].color = ft_atoi_base(line + i); // a faire
			i += 9;
		}
		i++;
		j++;
        }
	return (data);
}

t_node	**ft_add_map(t_map *map, t_node **old_map, char *line)
{
	int	i;
	t_node	**res;
	t_node	*data;

	printf ("%p\n%d\n", (void *) map, map->height);
	if (map->weight == 0)
		map->weight = ft_get_weight(line);
	printf ("%p\n%d\n", (void *) map, map->height);
	data = ft_export_data(line, map);
	res =  calloc(map->height + 2, sizeof(t_node *));
	i = 0;
	if (!old_map)
	{
		while (old_map[i])
		{
			res[i] = old_map[i];
			i++;
		}
	}
	res[i] = data;
	res[i + 1] = NULL;
	map->height++;
	free(old_map);
	return (res);
}

t_node	**ft_write_map(t_map *map, int fd)
{
	char	*line;
	t_node	**res_map;

	res_map = NULL;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line)
	{
		ft_add_map(map, res_map, line);
		free (line);
		line = get_next_line(fd);
	}
	return (res_map);
}

t_map	*ft_init_map(char *name)
{
	int		fd;
	t_map	*map;

	map = calloc(sizeof(t_map), 1);
	if (!map)
		return (NULL);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map->map = ft_write_map(map, fd);
	return (map);
}

t_vars	*ft_init_fdf(int ac, char **av)
{
	t_vars	*vars;

	vars = calloc(sizeof(t_vars), 1);
	if (!vars)
		return (NULL);
	if (ac != 2)
		return (NULL);
	vars->map = ft_init_map(av[1]);
	if (!vars->map)
		return (NULL);
	return (vars);
}
