/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 01:19:48 by mohtakra          #+#    #+#             */
/*   Updated: 2023/10/19 17:58:18 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libcub3d.h"

/*return true if the given char is near the marked char 'x'*/
static int	check_near(char **matrix, char c)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j] && matrix[i][j] != c)
			j++;
		if (matrix[i][j] == c)
			break ;
		i++;
	}
	if (matrix[i - 1][j] == 'x')
		return (1);
	if (matrix[i + 1][j] == 'x')
		return (1);
	if (matrix[i][j + 1] == 'x')
		return (1);
	if (matrix[i][j - 1] == 'x')
		return (1);
	return (0);
}

/*try to get the path to the player or the end of map*/
static int	has_path_player_collect(int i, int j, char **map)
{
	if (map[i] == '\0')
		return (1);
	if (map[i][j] == '1' || map[i][j] == ' ')
	{
		map[i][j] = 'x';
		if (has_path_player_collect(i, j + 1, map) == 1)
			return (1);
		if (has_path_player_collect(i + 1, j, map) == 1)
			return (1);
		if (has_path_player_collect(i, j - 1, map) == 1)
			return (1);
		if (has_path_player_collect(i - 1, j, map) == 1)
			return (1);
	}
	return (0);
}

/*return true if the player had a valid path to all the C , E*/
int	has_valid_path(const char **map)
{
	int		i;
	int		j;
	char	**matrix;

	matrix = ft_matrixcpy(map);
	if (!matrix)
		return (0);
	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j] && matrix[i][j] != 'C')
			j++;
		if (matrix[i][j] == 'C')
			break ;
		i++;
	}
	has_path_player_collect(i, j, matrix);
	if (has_player((const char **)matrix))
		return (free_matrix(matrix), 0);
	if (has_collectible((const char **)matrix) || !check_near(matrix, 'E'))
		return (free_matrix(matrix), 0);
	return (free_matrix(matrix), 1);
}
