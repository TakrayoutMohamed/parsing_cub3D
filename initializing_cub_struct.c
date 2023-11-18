/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing_cub_struct.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:24:00 by mohtakra          #+#    #+#             */
/*   Updated: 2023/11/18 00:16:48 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	cub->f = 0x0;
	cub->c = 0x0;
	cub->map = NULL;
	return (cub);
}
