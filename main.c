#include "./libpars.h"

void	print_matrix(char **matrix)
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

void	print_data(t_cub *cub)
{
	printf("NO texture is |%s|\n",cub->no);
	printf("SO texture is |%s|\n",cub->so);
	printf("WE texture is |%s|\n",cub->we);
	printf("EA texture is |%s|\n",cub->ea);
	printf("F texture is |%s|\n",cub->f);
	printf("C texture is |%s|\n",cub->c);
	printf("**********************start map********\n");
	print_matrix(cub->map);
	printf("\n**********************end map********\n");
}

int	main(int argc, char **argv)
{
	t_cub	*map_data;

	map_data = parse_data(argc, argv);
	print_data(map_data);
	return (0);
}
