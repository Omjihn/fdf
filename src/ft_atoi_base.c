/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:01:29 by gbricot           #+#    #+#             */
/*   Updated: 2023/07/07 14:31:37 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi_base(char *nb)
{
	int	res;
	int	j;
	int	i;

	res = 0;
	if (nb[0] != '0' || nb[1] != 'x')
		return (0);
	i = 2;
	while ((nb[i] >= '0' && nb[i] <= '9') || (nb[i] >= 'a' && nb[i] <= 'f'))
		i++;
	j = i - 3;
	i = 2;
	while ((nb[i] >= '0' && nb[i] <= '9') || (nb[i] >= 'a' && nb[i] <= 'f'))
	{
		if (nb[i] >= '0' && nb[i] <= '9')
			res += (nb[i] - 48) << j * 4;
		else if (nb[i] >= 'a' && nb[i] <= 'f')
			res += ((nb[i] - 'a') + 10) << j * 4;
		j--;
		i++;
	}
	printf ("color %d\n", res);
	return (res);
}
