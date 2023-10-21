#include "./libpars.h"

/*
*  allocating to the elemonts of the structor t_cub 
*  and initialisating it to null
*/
t_cub	*initializing_cub_struct(void)
{
	t_cub	*cub;

	cub = (t_cub *) malloc(sizeof(t_cub));
	if (!cub)
	{
		print_error("we could not allocat for the cub struct \n", \
		"initializing_cub_struct()");
		return (exit(EXIT_FAILURE), NULL);
	}
	cub->no = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->so = NULL;
	cub->f = NULL;
	cub->c = NULL;
	cub->map = NULL;
	return (cub);
}
