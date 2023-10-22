/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_accepted_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:24:06 by mohtakra          #+#    #+#             */
/*   Updated: 2023/10/22 21:28:53 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

/*return true if the extension is *.cub*/
bool	is_accepted_extension(char *map)
{
	int	len;

	len = (int)ft_strlen(map);
	if (!map || ft_strlen(map) == 4)
		return (false);
	while (*map)
		map++;
	while (*map != '.' && len > 0)
	{
		len--;
		map--;
	}
	if (ft_strcmp(map, ".cub") == 0)
		return (true);
	return (false);
}

bool	is_accepted_data(char *map_path)
{
	if (!is_accepted_extension(map_path))
		return (false);
	return (true);
}
