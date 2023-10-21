#include "./libpars.h"

static bool	set_floor_ceil(t_cub *cub, char **matrix)
{
	if (!cub->f && ft_strcmp(matrix[0], "F") == 0)
		cub->f = ft_strdup(matrix[1]);
	else if (!cub->c && ft_strcmp(matrix[0], "C") == 0)
		cub->c = ft_strdup(matrix[1]);
	else
		return (false);
	return (true);
}

static bool	set_textures(t_cub *cub, char **matrix)
{
	if (!cub->no && ft_strcmp(matrix[0], "NO") == 0)
		cub->no = ft_strdup(matrix[1]);
	else if (!cub->so && ft_strcmp(matrix[0], "SO") == 0)
		cub->so = ft_strdup(matrix[1]);
	else if (!cub->we && ft_strcmp(matrix[0], "WE") == 0)
		cub->we = ft_strdup(matrix[1]);
	else if (!cub->ea && ft_strcmp(matrix[0], "EA") == 0)
		cub->ea = ft_strdup(matrix[1]);
	else
	{
		return (false);
	}
	return (true);
}

/*set the values of the textures data, also  f anc c colors */
bool	set_textures_paths(t_cub *cub, char *line)
{
	char	**matrix;
	char	*str;

	str = ft_strtrim(line, "\n");
	if (!str)
		return (false);
	matrix = ft_split(str, ' ');
	if (!matrix)
		return (free(str), false);
	if (!matrix[0] || !matrix[1] || matrix[2] != NULL)
	{
		ft_putstr_fd("eeeeerrrror from set_textures_paths part 1\n", 2);
		return (free(str), ft_freematrix(matrix), false);
	}
	if (!set_textures(cub, matrix) && !set_floor_ceil(cub, matrix))
	{
		ft_putstr_fd("eeeeerrrror from set_textures_paths\n", 2);
		return (free(str), ft_freematrix(matrix), false);
	}
	return (free(str), ft_freematrix(matrix), true);
}
