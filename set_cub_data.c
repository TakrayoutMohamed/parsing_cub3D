#include "./libpars.h"

int	open_map_file(char *map)
{
	int	map_fd;

	map_fd = open(map, O_RDONLY, 0666);
	if (map_fd == -1)
		print_error("Error :\ncouldn't open the file ", map);
	return (map_fd);
}

/*here all the data of the t_cub struct is gonna be setting*/
bool	set_cub_data(t_cub *cub, char *map)
{
	char	*line;
	char	*map_in_str;
	int		map_fd;

	map_in_str = NULL;
	map_fd = open_map_file(map);
	if (map_fd == -1)
		return (false);
	line = get_next_line(map_fd);
	while (line)
	{
		if (cub->map == NULL && !is_textures_floor_ceiles_setted(cub))
		{
			if (ft_strcmp(line, "\n") != 0 && !set_textures_paths(cub, line))
				/* 
				*  if it enters to here it should take that if the line is not one of
				*  textures  or ceilling or floore than it should write an error message
				*  and exit and that should handdled inside the set_textures_paths()
				*/
				return (print_error("error in textures c or f", "set_cub_data()"), \
				free(line), close(map_fd), false);
		}
		else
			map_in_str = ft_strjoin_free(map_in_str, line);
		free(line);
		line = get_next_line(map_fd);
	}
	close(map_fd);
	if (!set_map(cub, map_in_str) || !check_map(cub->map))
		return (free(map_in_str), free(line), false);
	return (free(map_in_str), free(line), true);
}
