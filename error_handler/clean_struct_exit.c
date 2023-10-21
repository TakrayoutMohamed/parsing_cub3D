#include "./liberror.h"

void	clean_struct_exit(t_cub *cub)
{
	if (cub)
	{
		if (cub->c)
			free(cub->c);
		if (cub->f)
			free(cub->f);
		if (cub->ea)
			free(cub->ea);
		if (cub->we)
			free(cub->we);
		if (cub->so)
			free(cub->so);
		if (cub->no)
			free(cub->no);
		if (cub->map)
			ft_freematrix(cub->map);
		free(cub);
	}
	exit(EXIT_FAILURE);
}
