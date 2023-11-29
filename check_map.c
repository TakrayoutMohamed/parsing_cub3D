/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:08:41 by mohtakra          #+#    #+#             */
/*   Updated: 2023/11/29 10:54:54 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

/* copy the map and replace the player and empty spaces(0) with x 
* and spaces(' ') with y
*/
static void	new_map(char **copymap)
{
	int	i;
	int	j;

	i = 0;
	if (copymap == NULL)
		return ;
	while (copymap[i])
	{
		j = 0;
		while (copymap[i][j])
		{
			if (copymap[i][j] != ' ' && copymap[i][j] != '1')
				copymap[i][j] = 'x';
			else if (copymap[i][j] == ' ')
				copymap[i][j] = 'y';
			j++;
		}
		i++;
	}
}

/*
*  all the functions that checks if the map is accepted
*/
bool	check_map(char **map)
{
	char	**copymap;

	if (map == NULL)
		return (ft_putstr_fd("Error :\nEmpty map!!", 2), false);
	if (!has_accepted_chars(map))
		return (false);
	if (!has_player(map))
		return (false);
	if (!has_only_one_player(map))
		return (false);
	copymap = ft_matrixcpy((const char **) map);
	if (copymap == NULL)
		return (false);
	new_map(copymap);
	if (!is_top_wall(copymap) || !is_bottom_wall(copymap))
		return (ft_freematrix(copymap), false);
	if (!is_right_left_wall(copymap))
		return (ft_freematrix(copymap), false);
	if (is_open_inside(copymap))
		return (ft_freematrix(copymap), false);
	if (is_open_long_line(copymap))
		return (ft_freematrix(copymap), false);
	return (ft_freematrix(copymap), true);
}
