#include "./libcub3d.h"

//return true if the extension is *.cub 
bool	is_accepted_extension(char *map)
{
	int	len;

	len = (int)ft_strlen(map);
	if (!map || ft_strlen(map) == 4)
		return (false);
	while (*map)
		map++;
	while (*map != '.' && len > 0)
	{
		len--;
		map--;
	}
	if (ft_strcmp(map, ".cub") == 0 )
		return (true);
	return (false);
}

bool	is_accepted_data(char *map_path)
{
	//is file map_path is .cub extension
	if(!is_accepted_extension(map_path))
		return (false);
	//is all the characters are acceptable 0 , 1 " " N S E W
	return (true);
}