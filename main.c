/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:24:37 by mohtakra          #+#    #+#             */
/*   Updated: 2023/11/29 00:19:06 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	printf("F texture is |%u|\n",cub->f);
	printf("C texture is |%u|\n",cub->c);
	printf("**********************start map********\n");
	print_matrix(cub->map);
	printf("\n**********************end map********\n");
}

// void foo(void)
// {
// 	system("leaks cub3D");
// }

int	main(int argc, char **argv)
{
	t_cub	*map_data;

	// atexit(foo);
	map_data = parse_data(argc, argv);
	print_data(map_data);
	clean_struct_exit(map_data);
	return (0);
}
