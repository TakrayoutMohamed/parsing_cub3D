#include "./libpars.h"

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
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ')
			{
				if (map[i][j] != 'N' && map[i][j] != 'W' && map[i][j] != 'E' && map[i][j] != 'S')
				{
					
					ft_putstr_fd("Error\nthier is non accepted character in line : ", 2);
					ft_putnbr_fd(i + 1, 2);
					ft_putstr_fd("\n has_accepted_chars()", 2);
					return (false);
				}
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
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'S')
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
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'S')
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
			if (copymap[i][j] != ' ')
				copymap[i][j] = 'x';
			else
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
			print_error("the map is not sorounded by wals\n", NULL);
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

	i = 0;
	while (copymap[i])
	{
		if (copymap[i][0] != '1' && copymap[i][0] != 'y')
		{
			print_error("the map is not sorounded by wals right and left\n", NULL);
			return (false);
		}
		if (copymap[i][ft_strlen(copymap[i]) - 1] != '1' && \
		copymap[i][ft_strlen(copymap[i]) - 1] != 'y')
		{
			print_error("the map is not sorounded by wals right and left\n", NULL);
			return (false);
		}
		i++;
	}
	return (true);
}

/*check if thier is a ziro in aline while one of above or under line are shorter*/
bool	is_open_long_lien(char **copymap)
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
				if ((i > 0 && (ft_strlen(copymap[i - 1]) - 1) < j) || \
				(copymap[i + 1] != NULL && ft_strlen(copymap[i + 1]) - 1 < j))
				{
					ft_putstr_fd("map not closed in the line :", 2);
					return (ft_putnbr_fd(i + 1, 2), true);
				}
			}
		}
	}
	return (false);
}

/* this file is a fully dirty one it countiens almost 
*  all the functions that checks if the map is accepted
*/
void	check_map(char **map)
{
	char	**copymap;
	int		i;
	int		j;


	if (!has_accepted_chars(map))
		return ;
	if (!has_player(map))
		return ;
	if (!has_only_one_player(map))
		return ;
	copymap = ft_matrixcpy((const char **) map);
	new_map(copymap);
	
	if (!is_top_wall(copymap) || !is_bottom_wall(copymap))
	{
		ft_freematrix(copymap);
		return ;
	}
	if (!is_right_left_wall(copymap))
	{
		ft_freematrix(copymap);
		return ;
	}
	

	// printf("**********************start map********\n");
	// print_matrix(copymap);
	// printf("\n**********************end map********\n");
	// exit(44);
	
	

	
	
	//check if thier is a space ' ' inside the map 
	//get how many line in the map 
	int nbrlines;

	nbrlines = 0;
	while (map[nbrlines])
		nbrlines++;
	nbrlines--;
	i = 0;
	while (copymap[i])
	{
		j = 0;
		while (copymap[i][j])
		{
			if (copymap[i][j] == 'y' && i > 0 && i < nbrlines)
			{
				if (ft_strlen(copymap[i - 1]) >= j && copymap[i - 1][j] == 'x')
					(printf("thier is a leak on the map not closed"), exit(1), 0);// here the map not accepted
				if (ft_strlen(copymap[i + 1]) >= j && copymap[i + 1][j] == 'x')
					(printf("thier is a leak on the map not closed"), exit(1), 0);// here the map not accepted
				if (copymap[i][j + 1] == 'x')
					(printf("thier is a leak on the map not closed"), exit(1), 0);// here the map not accepted
				if (j != 0 && copymap[i][j - 1] == 'x')
					(printf("thier is a leak on the map not closed"), exit(1), 0);// here the map not accepted
			}
			else if (copymap[i][j] == 'y' && i == 0 && i < nbrlines)
			{
				if (ft_strlen(copymap[i + 1]) >= j && copymap[i + 1][j] == 'x')
					(printf("thier is a leak on the map not closed"), exit(1), 0);// here the map not accepted
				if (copymap[i][j + 1] == 'x')
					(printf("thier is a leak on the map not closed"), exit(1), 0);// here the map not accepted
				if (j != 0 && copymap[i][j - 1] == 'x')
					(printf("thier is a leak on the map not closed"), exit(1), 0);// here the map not accepted
			}
			else if (copymap[i][j] == 'y' && i > 0 && i == nbrlines)
			{
				if (ft_strlen(copymap[i - 1]) >= j && copymap[i - 1][j] == 'x')
					(printf("thier is a leak on the map not closed"), exit(1), 0);// here the map not accepted
				if (copymap[i][j + 1] == 'x')
					(printf("thier is a leak on the map not closed"), exit(1), 0);// here the map not accepted
				if (j != 0 && copymap[i][j - 1] == 'x')
					(printf("thier is a leak on the map not closed"), exit(1), 0);// here the map not accepted
			}
			// if (copymap[i][j] == 'y')
			// {
			// }
			j++;
		}
		i++;
	}


	if (is_open_long_lien(copymap))
	{
		ft_freematrix(copymap);
		return ;
	}

}
