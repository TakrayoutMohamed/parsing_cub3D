#include "./libpars.h"

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
		return(exit(EXIT_FAILURE), NULL);
	}
	cub = initializing_cub_struct();
	if (!set_cub_data(cub, argv[1]))
	{
		return(clean_struct_exit(cub), NULL);
	}
	return (cub);
}
