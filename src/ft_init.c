/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:43:40 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/27 13:07:03 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



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
	ft_write_map(map, fd);
}

t_vars	*ft_init(int ac, char **av)
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
