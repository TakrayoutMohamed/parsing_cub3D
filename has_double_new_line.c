/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_double_new_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:23:53 by mohtakra          #+#    #+#             */
/*   Updated: 2023/10/22 21:23:54 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

/*return true if the str has newline folowed by new line*/
bool	has_double_new_line(char *str)
{
	if (!str)
		return (true);
	while (*str)
	{
		if (*str == '\n' && *(str + 1) == '\n')
			return (true);
		str++;
	}
	return (false);
}
