/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_only_one_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:08:03 by mohtakra          #+#    #+#             */
/*   Updated: 2023/10/22 21:08:04 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

/*check if the map has only one player*/
bool	has_only_one_player(char **map)
{
	int	i;
	int	j;
	int	players_num;

	players_num = 0;
	i = 0;
	while (players_num < 2 && map[i])
	{
		j = 0;
		while (players_num < 2 && map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W')
				players_num++;
			if (map[i][j] == 'E' || map[i][j] == 'S')
				players_num++;
			j++;
		}
		i++;
	}
	if (players_num == 1)
		return (true);
	print_error("Error\n", "thier is a second player in the map at line : ");
	ft_putnbr_fd(i, 2);
	return (false);
}
