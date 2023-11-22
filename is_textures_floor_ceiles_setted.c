/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_textures_floor_ceiles_setted.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:24:25 by mohtakra          #+#    #+#             */
/*   Updated: 2023/11/22 15:27:26 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

/*return true if the info of the texutes so, no, ea, we, f, c has been setted*/
bool	is_textures_floor_ceiles_setted(t_cub *cub)
{
	if (cub->c == UINT32_MAX)
		return (false);
	if (cub->f == UINT32_MAX)
		return (false);
	if (cub->ea == NULL)
		return (false);
	if (cub->we == NULL)
		return (false);
	if (cub->so == NULL)
		return (false);
	if (cub->no == NULL)
		return (false);
	return (true);
}
