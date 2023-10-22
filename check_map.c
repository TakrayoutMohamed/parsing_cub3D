#include "./libpars.h"

static void	print_matrix(char **matrix)
{
	int	i = 0;
	int j;

	// ft_putchar_fd('{', 1);
	while (matrix[i])
	{
		j = 0;
		// ft_putchar_fd('[', 1);
		while (matrix[i][j])
		{
			ft_putchar_fd(matrix[i][j], 1);
			j++;
		}
		// ft_putchar_fd(']', 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	// ft_putchar_fd('}', 1);
}

bool	is_valid_char(char c)
{
	if (c == '0')
		return (true);
	if (c == '1')
		return (true);
	if (c == ' ')
		return (true);
	if (c == 'N')
		return (true);
	if (c == 'W')
		return (true);
	if (c == 'E')
		return (true);
	if (c == 'S')
		return (true);
	return (false);
}

/*check if the map has only accepted characters 0, 1, ' ', N, E, W and S*/
bool	has_accepted_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid_char(map[i][j]))
			{
				ft_putstr_fd("Error\n", 2);
				ft_putstr_fd("thier is non accepted character in line : ", 2);
				ft_putnbr_fd(i + 1, 2);
				return (ft_putstr_fd("\n has_accepted_chars()", 2), false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

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

/* copy the map and replace the player and empty spaces(0) with x 
* and spaces(' ') with y
*/
void	new_map(char **copymap)
{
	int	i;
	int	j;

	i = 0;
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

/*check the top line of the map*/
bool	is_top_wall(char **copymap)
{
	int	j;

	j = 0;
	while (copymap[0][j])
	{
		if (copymap[0][j] != '1' && copymap[0][j] != 'y')
		{
			print_error("the map is not sorounded by walls top\n", NULL);
			return (false);
		}
		j++;
	}
	return (true);
}

/*check the bottom of the map*/
bool	is_bottom_wall(char **copymap)
{
	int	j;
	int nbrlines1;

	j = 0;
	nbrlines1 = 0;
	while (copymap[nbrlines1])
		nbrlines1++;
	nbrlines1--;
	while (copymap[nbrlines1][j])
	{
		if (copymap[nbrlines1][j] != '1' && copymap[nbrlines1][j] != 'y')
		{
			print_error("the map is not sorounded by wals bottom\n", NULL);
			return (false);
		}
		j++;
	}
	return (true);
}

/*check the right and left border*/
bool	is_right_left_wall(char **copymap)
{
	int	i;
	int	len;

	i = -1;
	while (copymap[++i])
	{
		len = (int)ft_strlen(copymap[i]) - 1;
		if (copymap[i][0] != '1' && copymap[i][0] != 'y')
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("map not sorounded by wals right and left", 2);
			return (false);
		}
		if (copymap[i][len] != '1' && copymap[i][len] != 'y')
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("map not sorounded by wals right and left", 2);
			return (false);
		}
	}
	return (true);
}

/* check if thier is a ziro in a line 
*  while one of above or under line are shorter
*/
bool	is_open_long_line(char **copymap)
{
	int	i;
	int	j;

	i = -1;
	while (copymap[++i])
	{
		j = -1;
		while (copymap[i][++j])
		{
			if (copymap[i][j] == 'x')
			{
				if (i > 0 && (ft_strlen(copymap[i - 1]) - 1) < j)
				{
					ft_putstr_fd("map not closed in the line :", 2);
					return (ft_putnbr_fd(i + 1, 2), true);
				}
				if (copymap[i + 1] != NULL && ft_strlen(copymap[i + 1]) - 1 < j)
				{
					ft_putstr_fd("map not closed in the line :", 2);
					return (ft_putnbr_fd(i + 1, 2), true);
				}
			}
		}
	}
	return (false);
}

/* return true if the up and down chars of the index are walls 
*  else return false
*/
static bool	is_up_bottom_wall(char *up, char *bottom, int index)
{
	if (up && strlen(up) >= index)
	{
		if (up[index] == 'x')
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("thier is a ' ' next to 0 or player \n", 2);
			return (false);
		}
	}
	if (bottom && strlen(bottom) >= index)
	{
		if (bottom[index] == 'x')
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("thier is a ' ' next to 0 or player \n", 2);
			return (false);
		}
	}
	return (true);
}

/* return true if the right and left chars of the index are walls
*  else return false
*/
static bool	right_left_char(char left, char right, int line)
{
	if (left == 'x' || right == 'x')
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("there is a ' ' next to 0 or player in line : ", 2);
		ft_putnbr_fd(line, 2);
		return (false);
	}
	return (true);
}

static bool	is_first_wall(char **copymap)
{
	int	j;

	j = 0;
	while (copymap[0][j])
	{
		if (copymap[0][j] == 'y')
		{
			if (!is_up_bottom_wall(NULL, copymap[1], j))
			{
				return (ft_putnbr_fd(1, 2), false);
			}
		}
		j++;
	}
	return (true);
}

static bool	is_last_wall(char **copymap)
{
	int	j;
	int	i;

	i = 0;
	while (copymap[i + 1])
		i++;
	j = 0;
	while (copymap[i][j])
	{
		if (copymap[i][j] == 'y')
		{
			if (!is_up_bottom_wall(copymap[i - 1], NULL, j))
			{
				return (ft_putnbr_fd(i + 1, 2), false);
			}
		}
		j++;
	}
	return (true);
}

bool	is_open_inside(char **copymap)
{
	int	i;
	int	j;

	i = 0;
	if (!is_first_wall(copymap) || !is_last_wall(copymap))
		return (true);
	while (++i && copymap[i] && copymap[i + 1])
	{
		j = -1;
		while (++j > -2 && copymap[i][j])
		{
			if (copymap[i][j] != 'y')
				continue ;
			if (!is_up_bottom_wall(copymap[i - 1], copymap[i + 1], j) || \
			!right_left_char(copymap[i][j - 1], copymap[i][j + 1], i + 1))
			{
				return (ft_putnbr_fd(i + 1, 2), true);
			}
			
		}
	}
	return (false);
}

/*
*  all the functions that checks if the map is accepted
*/
bool	check_map(char **map)
{
	char	**copymap;

	if (!has_accepted_chars(map))
		return (false);
	if (!has_player(map))
		return (false);
	if (!has_only_one_player(map))
		return (false);
	copymap = ft_matrixcpy((const char **) map);
	new_map(copymap);
	printf("**********************start map********\n");
	print_matrix(copymap);
	printf("\n**********************end map********\n");
	// exit(44);
	if (!is_top_wall(copymap) || !is_bottom_wall(copymap))
		return (ft_freematrix(copymap), false);
	if (!is_right_left_wall(copymap))
		return (ft_freematrix(copymap), false);
	if (is_open_inside(copymap))
		return (ft_freematrix(copymap), false);

	if (is_open_long_line(copymap))
		return (ft_freematrix(copymap), false);
	return (true);
}
