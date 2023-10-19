/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surrounded.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 01:21:17 by mohtakra          #+#    #+#             */
/*   Updated: 2023/10/19 18:03:55 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libcub3d.h"

/*return if the map is surrounded by walls (1)*/
int	is_surrounded(const char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	if (!map || !*map)
		return (0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			
			j++;
		}
		i++;
	}
	return (1);
}
