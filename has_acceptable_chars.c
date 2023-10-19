/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_acceptable_chars.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 01:20:38 by mohtakra          #+#    #+#             */
/*   Updated: 2023/10/19 17:33:31 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libcub3d.h"

/*return true if the map has only chars 0,1,C,E,P*/
int	has_acceptable_chars(const char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1')
				if (map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}
