/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_open_inside.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:09:28 by mohtakra          #+#    #+#             */
/*   Updated: 2023/11/29 00:37:55 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

/* return true if the up and down chars of the index are walls 
*  else return false
*/
static bool	is_up_bottom_wall(char *up, char *bottom, int index)
{
	if (up && (int)strlen(up) >= index)
	{
		if (up[index] == 'x')
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("thier is a ' ' next to 0 or player \n", 2);
			return (false);
		}
	}
	if (bottom && (int)strlen(bottom) >= index)
	{
		if (bottom[index] == 'x')
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("thier is a ' ' next to 0 or player \n", 2);
			return (false);
		}
	}
	return (true);
}

/* return true if the right chars of the index are walls
*  else return false
*/
static bool	is_right_char(char right, int line)
{
	if (right == 'x')
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("there is a ' ' next to 0 or player in line : ", 2);
		ft_putnbr_fd(line, 2);
		return (false);
	}
	return (true);
}

/* return true if the left chars of the index are walls
*  else return false
*/
static bool	is_left_char(char left, int line)
{
	if (left == 'x')
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("there is a ' ' next to 0 or player in line : ", 2);
		ft_putnbr_fd(line, 2);
		return (false);
	}
	return (true);
}

static bool	is_first_wall(char **copymap)
{
	int	j;

	j = 0;
	while (copymap[0][j])
	{
		if (copymap[0][j] == 'y')
		{
			if (!is_up_bottom_wall(NULL, copymap[1], j))
			{
				return (ft_putnbr_fd(1, 2), false);
			}
		}
		j++;
	}
	return (true);
}

static bool	is_last_wall(char **copymap)
{
	int	j;
	int	i;

	i = 0;
	while (copymap[i + 1])
		i++;
	j = 0;
	while (copymap[i][j])
	{
		if (copymap[i][j] == 'y')
		{
			if (!is_up_bottom_wall(copymap[i - 1], NULL, j))
			{
				return (ft_putnbr_fd(i + 1, 2), false);
			}
		}
		j++;
	}
	return (true);
}

bool	is_open_inside(char **copymap)
{
	int	i;
	int	j;

	i = 0;
	if (!is_first_wall(copymap) || !is_last_wall(copymap))
		return (true);
	while (++i && copymap[i] && copymap[i + 1])
	{
		j = 0;
		while (copymap[i][j])
		{
			if (copymap[i][j] == 'y')
			{
				if (!is_up_bottom_wall(copymap[i - 1], copymap[i + 1], j))
					return (ft_putnbr_fd(i + 1, 2), true);
				if (j != 0 && !is_left_char(copymap[i][j - 1], j))
					return (ft_putnbr_fd(i + 1, 2), true);
				if (j != (int)ft_strlen(copymap[i]) && !is_right_char(copymap[i][j + 1], j))
					return (ft_putnbr_fd(i + 1, 2), true);
			}
			j++;
		}
	}
	return (false);
}
