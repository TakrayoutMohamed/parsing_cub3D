#include "./libcub3d.h"


/*join s1 with s2 and free the pointer to s1*/
char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = s1;
	s1 = ft_strjoin(s1, s2);
	free(tmp);
	return (s1);
}

char	*ft_strtrim_free(char *s1, char *to_trim)
{
	char	*tmp;

	tmp = s1;
	s1 = ft_strtrim(s1, to_trim);
	// free(tmp); /*this may create a leak here*/
	return (s1);
}

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

void	set_map(t_cub *cub, char *str)
{
	cub->map = ft_split(str, '\n');
	if (cub->map == NULL)
		return ; /*here i should print an error message end exit*/
}

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



void	check_map(char **map)
{
	char	**copymap;
	int		i;
	int		j;

	copymap = ft_matrixcpy(map);
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
	//check the bottom of the map
	j = 0;
	while (copymap[i - 1][j])
	{
		if (copymap[i - 1][j] != '1' && copymap[i - 1][j] != 'y')
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
					if (copymap[i - 1][j] == '0')
						return (0);// here the map not accepted
					if (copymap[i + 1][j] == '0')
						return (0);// here the map not accepted
					if (copymap[i][j + 1] == '0')
						return (0);// here the map not accepted
					if (j != 0 && copymap[i][j - 1] == '0')
						return (0);// here the map not accepted
				}
				else if (i == 0 && i < nbrlines)
				{
					if (copymap[i + 1][j] == '0')
						return (0);// here the map not accepted
					if (copymap[i][j + 1] == '0')
						return (0);// here the map not accepted
					if (j != 0 && copymap[i][j - 1] == '0')
						return (0);// here the map not accepted
				}
				else if (i > 0 && i == nbrlines)
				{
					if (copymap[i - 1][j] == '0')
						return (0);// here the map not accepted
					if (copymap[i][j + 1] == '0')
						return (0);// here the map not accepted
					if (j != 0 && copymap[i][j - 1] == '0')
						return (0);// here the map not accepted
				}
			}
		}
	}
	/*check if the map sorrounded by walls or spaces*/
			/*check if the first str in the map is all ones and spaces*/
		/*to verify if the map is sourrounded by wals even if its with spaces simply 
		* you are gonna use the backtracking algo and make every empty place (0) 
		* and every space (' ') replaced with a simple 'x' ,
		* than check if the sides are all wals and spaces (' ')
		* repeat the next two moves untill thier are no empty spaces(0) in the map
			* if thier is a place where thier is an empty place (0) than
			* take it as the start of back tracking and run it egain
		*/
	/*check if the map has only the accepted characters*/


}

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
	// convert_map_into_string(argv[1]);
	// split the file by newline
	// free the convert_map_into_string(argv[1])'s return
	// get the value of textures by spliting the first 6 lines by space
		//free the return of the splite by space
	// get the map value using the last non_null pointer in the matrix
	// free the matrix which is the return of the split by newline
	return (cub);
}
