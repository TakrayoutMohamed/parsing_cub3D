/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:07:48 by mohtakra          #+#    #+#             */
/*   Updated: 2023/10/22 21:07:50 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

/*check if the map has a player*/
bool	has_player(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W')
				return (true);
			if (map[i][j] == 'E' || map[i][j] == 'S')
				return (true);
			j++;
		}
		i++;
	}
	print_error("Error\nthier is no player in the map ", "has_player()");
	return (false);
}
