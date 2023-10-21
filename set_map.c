#include "./libpars.h"

/*set the data of the map in its place */
bool	set_map(t_cub *cub, char *map_in_str)
{
	char	*str;

	if (!cub || !map_in_str)
		return (false);
	str = ft_strtrim(map_in_str, "\n");
	if (!str || has_double_new_line(str))
	{
		print_error("Error :", "double new line in the map set_map()");
		return (free(str), false);
	}
	cub->map = ft_split(str, '\n');
	if (cub->map == NULL)
	{
		print_error("the map not accepted set_map()", NULL);
		return (free(str), false);
	}
	return (free(str), true);
}
