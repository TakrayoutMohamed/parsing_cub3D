/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:24:46 by mohtakra          #+#    #+#             */
/*   Updated: 2023/11/29 11:07:08 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

/*set the data of the map in its place */
bool	set_map(t_cub *cub, char *map_in_str)
{
	char	*str;

	if (!cub)
		return (false);
	if (map_in_str == NULL)
		return (ft_putstr_fd("Error :\nEmpty map!! set_map()", 2), false);
	str = ft_strtrim(map_in_str, "\n");
	if (!str || has_double_new_line(str))
	{
		print_error("Error :", "double new line in the map set_map()");
		return (free(str), false);
	}
	cub->map = ft_split(str, '\n');
	if (cub->map == NULL)
	{
		print_error("the map not accepted set_map()", NULL);
		return (free(str), false);
	}
	return (free(str), true);
}
