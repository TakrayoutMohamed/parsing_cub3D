/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_struct_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:21:12 by mohtakra          #+#    #+#             */
/*   Updated: 2023/11/22 16:15:37 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

void	clean_struct_exit(t_cub *cub)
{
	if (cub)
	{
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
	exit(0);
}
