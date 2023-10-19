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
		return ; //here i should print an error message end exit
	if (!matrix[0] || !matrix[1])
		return ; //here i should print an error message end exit
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
		return ; //here i should print an error message end exit
	}
	ft_freematrix(matrix);
}

void	set_map(t_cub *cub, char *str)
{
	cub->map = ft_split(str, '\n');
	if (cub->map == NULL)
		return ; //here i should print an error message end exit
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

void	set_cub_data(t_cub *cub, char *map)
{
	char	*line;
	char	*map_in_str;
	int		map_fd;
	int		one_shot;

	one_shot = 1;
	map_in_str = NULL;
	map_fd = open(map, O_RDONLY, 0666);
	if (map_fd == -1)
	{
		ft_putstr_fd("couldn't open the file ",2);
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
				// if it enters to here it should take that if the line is not one of
				// textures  or ceilling or floore than it should write an error message
				// and exit and that should happen inside the set_textures_paths()
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
	//check if the map in str has a sequance of new line than it is not accepted;
	if (has_double_new_line(map_in_str))
	{
		printf("the map you entered not accepted becouse of double new line\n");
		/*here i need to free the struct cub and map_in_str*/
		exit(EXIT_FAILURE);
	}
	set_map(cub, map_in_str);
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
	printf("after checking is data accepted and nbr of args are good\n");
	cub = initializing_cub_struct();
	printf("after checking is data accepted and nbr of args are good\n");
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
