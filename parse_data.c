/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:21:30 by mohtakra          #+#    #+#             */
/*   Updated: 2023/10/22 21:33:31 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

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
		return (exit(EXIT_FAILURE), NULL);
	}
	cub = initializing_cub_struct();
	if (!set_cub_data(cub, argv[1]))
	{
		return (clean_struct_exit(cub), NULL);
	}
	return (cub);
}
