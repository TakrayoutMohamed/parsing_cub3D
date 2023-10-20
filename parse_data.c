#include "./libcub3d.h"

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

/*join s1 with s2 and free the pointer to s1*/
char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = s1;
	s1 = ft_strjoin(s1, s2);
	free(tmp);
	return (s1);
}

/*romove the string to_trinm  from the start and end of s1*/
char	*ft_strtrim_free(char *s1, char *to_trim)
{
	char	*tmp;

	tmp = s1;
	s1 = ft_strtrim(s1, to_trim);
	// free(tmp); /*this may create a leak here*/
	return (s1);
}

/*
*  allocating to the elemonts of the structor t_cub 
*  and initialisating it to null
*/
t_cub	*initializing_cub_struct(void)
{
	t_cub	*cub;

	cub = (t_cub *) malloc(sizeof(t_cub));
	if (!cub)
		return (ft_putstr_fd("we could not allocat for the cub struct \n", 2), exit(EXIT_FAILURE), NULL);
	cub->no = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->so = NULL;
	cub->f = NULL;
	cub->c = NULL;
	cub->map = NULL;
	return (cub);
}

/*return true if the info of the texutes so, no, ea, we, f, c has been setted*/
bool	is_textures_floor_ceiles_setted(t_cub *cub)
{
	if (cub->c == NULL)
		return (false);
	if (cub->f == NULL)
		return (false);
	if (cub->ea == NULL)
		return (false);
	if (cub->we == NULL)
		return (false);
	if (cub->so == NULL)
		return (false);
	if (cub->no == NULL)
		return (false);
	return (true);
}

/*set the values of the textures data, also  f anc c colors */
void	set_textures_paths(t_cub *cub, char *line)
{
	char	**matrix;

	line = ft_strtrim_free(line, "\n");
	matrix = ft_split(line, ' ');
	if (!matrix)
		return ; /*here i should print an error message end exit*/
	if (!matrix[0] || !matrix[1] || matrix[2] != 0)
	{
		ft_freematrix(matrix);
		printf("eeeeerrrror from set_textures_paths part 1\n");
		exit(EXIT_FAILURE);
		return ; /*here i should print an error message end exit*/
	}
	if (!cub->no && ft_strcmp(matrix[0], "NO") == 0)
		cub->no = ft_strdup(matrix[1]);
	else if (!cub->so && ft_strcmp(matrix[0], "SO") == 0)
		cub->so = ft_strdup(matrix[1]);
	else if (!cub->we && ft_strcmp(matrix[0], "WE") == 0)
		cub->we = ft_strdup(matrix[1]);
	else if (!cub->ea && ft_strcmp(matrix[0], "EA") == 0)
		cub->ea = ft_strdup(matrix[1]);
	else if (!cub->f && ft_strcmp(matrix[0], "F") == 0)
		cub->f = ft_strdup(matrix[1]);
	else if (!cub->c && ft_strcmp(matrix[0], "C") == 0)
		cub->c = ft_strdup(matrix[1]);
	else
	{
		ft_freematrix(matrix);
		printf("eeeeerrrror from set_textures_paths\n");
		exit(EXIT_FAILURE);
		return ; /* here i should print an error message end exit */
	}
	ft_freematrix(matrix);
}

/*set the data of the map in its place */
void	set_map(t_cub *cub, char *str)
{
	cub->map = ft_split(str, '\n');
	if (cub->map == NULL)
		return ; /*here i should print an error message end exit*/
}

/*return true if the str has newline folowed by new line*/
bool	has_double_new_line(char *str)
{
	if (!str)
		return (true);
	while (*str)
	{
		if (*str == '\n' && *(str + 1) == '\n')
			return (true);
		str++;
	}
	return (false);
}


/* this file is a fully dirty one it countiens almost 
*  all the functions that checks if the map is accepted */
void	check_map(char **map)
{
	char	**copymap;
	int		i;
	int		j;


	//check if the map has only accepted characters 0, 1, ' ', N, E, W and S
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
					(printf("thier is non accepted character in line : %d\n", i + 1), exit(1), 0);// here the map not accepted
				}
			}
			j++;
		}
		i++;
	}

	//check if the map has a player
	int	player_exits;

	player_exits = 0;
	i = 0;
	while (player_exits == 0 && map[i])
	{
		j = 0;
		while (player_exits == 0 && map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'S')
			{
				player_exits = 1;
			}
			j++;
		}
		i++;
	}
	if (player_exits == 0)
		(printf("thier is no player in the map\n"), exit(1), 0);// here the map not accepted
	
	//check if the map has only one player

	int	players_num;

	players_num = 0;
	i = 0;
	while (players_num < 2 && map[i])
	{
		j = 0;
		while (players_num < 2 && map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'S')
			{
				players_num++;
			}
			j++;
		}
		i++;
	}
	if (players_num > 1)
		(printf("thier is a second player in the map at line : %d\n", i), exit(1), 0);// here the map not accepted
	
	// copy the map and replace the player and empty spaces(0) with x and spaces(' ') with y
	copymap = ft_matrixcpy((const char **) map);
	i = 0;
	while (copymap[i])
	{
		j = 0;
		while (copymap[i][j])
		{
			if (copymap[i][j] == '0' || copymap[i][j] == 'N' || copymap[i][j] == 'W' || copymap[i][j] == 'E' || copymap[i][j] == 'S')
				copymap[i][j] = 'x';
			else if (copymap[i][j] == ' ')
				copymap[i][j] = 'y';
			j++;
		}
		i++;
	}
	//check the top line of the map
	j = 0;
	while (copymap[0][j])
	{
		if (copymap[0][j] != '1' && copymap[0][j] != 'y')
		{
			printf("the map is not sorounded by wals\n");
			ft_freematrix(copymap);
			ft_freematrix(map);
			exit(EXIT_FAILURE);
		}
		j++;
	}

	// printf("**********************start map********\n");
	// print_matrix(copymap);
	// printf("\n**********************end map********\n");
	// exit(44);
	
	//check the bottom of the map
	
	int nbrlines1;

	nbrlines1 = 0;
	while (map[nbrlines1])
		nbrlines1++;
	j = 0;
	while (copymap[nbrlines1 - 1][j])
	{
		if (copymap[nbrlines1 - 1][j] != '1' && copymap[nbrlines1 - 1][j] != 'y')
		{
			printf("the map is not sorounded by wals bottom\n");
			ft_freematrix(copymap);
			ft_freematrix(map);
			exit(EXIT_FAILURE);
		}
		j++;
	}

	//check the right and left border
	i = 0;
	while (copymap[i])
	{
		if ((copymap[i][0] != '1' && copymap[i][0] != 'y') || \
		(copymap[i][ft_strlen(copymap[i]) - 1] != '1' && copymap[i][ft_strlen(copymap[i]) - 1] != 'y'))
		{
			printf("the map is not sorounded by wals right and left\n");
			ft_freematrix(copymap);
			ft_freematrix(map);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	
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
			if (copymap[i][j] == 'y')
			{
				if (i > 0 && i < nbrlines)
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
				else if (i == 0 && i < nbrlines)
				{
					if (ft_strlen(copymap[i + 1]) >= j && copymap[i + 1][j] == 'x')
						(printf("thier is a leak on the map not closed"), exit(1), 0);// here the map not accepted
					if (copymap[i][j + 1] == 'x')
						(printf("thier is a leak on the map not closed"), exit(1), 0);// here the map not accepted
					if (j != 0 && copymap[i][j - 1] == 'x')
						(printf("thier is a leak on the map not closed"), exit(1), 0);// here the map not accepted
				}
				else if (i > 0 && i == nbrlines)
				{
					if (ft_strlen(copymap[i - 1]) >= j && copymap[i - 1][j] == 'x')
						(printf("thier is a leak on the map not closed"), exit(1), 0);// here the map not accepted
					if (copymap[i][j + 1] == 'x')
						(printf("thier is a leak on the map not closed"), exit(1), 0);// here the map not accepted
					if (j != 0 && copymap[i][j - 1] == 'x')
						(printf("thier is a leak on the map not closed"), exit(1), 0);// here the map not accepted
				}
			}
			j++;
		}
		i++;
	}


	//check if thier is a ziro in aline while one of above or under line are shorter
	i = 0;
	while (copymap[i])
	{
		j = 0;
		while (copymap[i][j])
		{
			if (copymap[i][j] == 'x')
			{
				if (i > 0 && (ft_strlen(copymap[i - 1]) - 1) < j)
				{
					(printf("thier is a leak on the copymap not closed in the line %d\n", i + 1), exit(1), 0);// here the map not accepted
				}
				if (copymap[i + 1] != NULL && (ft_strlen(copymap[i + 1]) - 1) < j)
				{
					(printf("thier is a leak on the map not closed in the line %d\n", i + 1), exit(1), 0);// here the map not accepted
				}
			}
			j++;
		}
		i++;
	}

}

/*here all the data of the t_cub struct is gonna be setting*/
void	set_cub_data(t_cub *cub, char *map)
{
	char	*line;
	char	*map_in_str;
	int		map_fd;
	int		one_shot;

	one_shot = 1;
	line = NULL;
	map_in_str = NULL;
	map_fd = open(map, O_RDONLY, 0666);
	if (map_fd == -1)
	{
		ft_putstr_fd("couldn't open the file ", 2);
		ft_putstr_fd(map,2);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		if (one_shot == 1 && !is_textures_floor_ceiles_setted(cub))
		{
			if (ft_strcmp(line, "\n") != 0)
			{
				/* 
				*  if it enters to here it should take that if the line is not one of
				*  textures  or ceilling or floore than it should write an error message
				*  and exit and that should handdled inside the set_textures_paths()
				*/
				set_textures_paths(cub, line);
			}
		}
		else
		{
			one_shot = 0;
			map_in_str = ft_strjoin_free(map_in_str, line);
		}
		free(line);
	}
	close(map_fd);
	map_in_str = ft_strtrim_free(map_in_str, "\n");
	/*check if the map in str has an empty line;*/
	if (has_double_new_line(map_in_str))
	{
		printf("the map you entered not accepted becouse of double new line\n");
		/*here i need to free the struct cub and map_in_str*/
		exit(EXIT_FAILURE);
	}
	set_map(cub, map_in_str);
	/*check if the map is acceptable*/
	check_map(cub->map);
}

/*here is the main function of the parsing*/
t_cub	*parse_data(int argc, char **argv)
{
	t_cub	*cub;

	if (argc == 1 || argc > 2)
	{
		ft_putstr_fd("Error :\n", 2);
		ft_putstr_fd("exemple : \"./cub3D map.cub\"", 2);
		exit(EXIT_FAILURE);
	}
	if (!is_accepted_data(argv[1]))
	{
		exit(EXIT_FAILURE);
	}
	cub = initializing_cub_struct();
	set_cub_data(cub, argv[1]);
	return (cub);
}
