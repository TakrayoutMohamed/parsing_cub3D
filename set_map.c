/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:24:46 by mohtakra          #+#    #+#             */
/*   Updated: 2023/12/09 17:42:11 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

static void	del(void *to_del)
{
	free(to_del);
}

/*return a double pointer created from the list pointer entered (lst)*/
static char	**convert_list_to_matrix(t_list *lst)
{
	char	**matrix;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	if (lst == NULL)
		return (NULL);
	matrix = (char **)malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	if (!matrix)
		return (NULL);
	while (tmp != NULL)
	{
		matrix[i] = ft_strdup(tmp->content);
		i++;
		tmp = tmp->next;
	}
	matrix[i] = NULL;
	return (matrix);
}

//i should remove has_double_new_line.c
/*set the data of the map in its place */
bool	set_map(t_cub *cub, char *line, int map_fd)
{
	char	*str;
	t_list	*lst;

	lst = NULL;
	if (!cub || line == NULL)
		return (ft_putstr_fd("Error :\nEmpty map!! set_map()", 2), false);
	while (line)
	{
		str = ft_strtrim(line, "\n");
		free(line);
		ft_lstadd_back(&lst, ft_lstnew(str));
		line = get_next_line(map_fd);
		if (ft_strcmp(line, "\n") == 0)
		{
			print_error("Error :", "new line in the map set_map()");
			return (free(line), ft_lstclear(&lst, del), false);
		}
	}
	cub->map = convert_list_to_matrix(lst);
	ft_lstclear(&lst, del);
	if (cub->map == NULL)
		return (print_error("the map not accepted set_map()", NULL), false);
	return (true);
}
