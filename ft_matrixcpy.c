/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 01:20:18 by mohtakra          #+#    #+#             */
/*   Updated: 2023/11/17 03:08:10 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

/*copy a matrix and return a pointer to its copy*/
char	**ft_matrixcpy(const char **map)
{
	char	**matrix;
	int		i;

	i = 0;
	while (map[i])
		i++;
	matrix = (char **)malloc(sizeof(char *) * (i + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	while (map[i])
	{
		matrix[i] = ft_strdup((const char *)map[i]);
		if (!matrix[i])
			return (ft_freematrix(matrix), NULL);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}
