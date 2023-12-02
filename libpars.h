/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpars.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:21:21 by mohtakra          #+#    #+#             */
/*   Updated: 2023/12/02 20:09:37 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPARS_H
# define LIBPARS_H
# include "./error_handler/liberror.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <string.h>

typedef struct s_cub
{
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	__uint32_t	f;
	__uint32_t	c;
}	t_cub;

void	clean_struct(t_cub *cub);
t_cub	*parse_data(int argc, char **argv);
bool	is_accepted_extension(char *argv);
char	**ft_matrixcpy(const char **map);
char	*ft_strjoin_free(char *s1, char *s2);
t_cub	*initializing_cub_struct(void);
bool	is_textures_floor_ceiles_setted(t_cub *cub);
bool	set_cub_data(t_cub *cub, char *map);
bool	set_textures_paths(t_cub *cub, char *line);
bool	set_map(t_cub *cub, char *str);
bool	has_double_new_line(char *str);
bool	check_map(char **map);
bool	has_accepted_chars(char **map);
bool	has_player(char **map);
bool	has_only_one_player(char **map);
bool	is_top_wall(char **copymap);
bool	is_bottom_wall(char **copymap);
bool	is_right_left_wall(char **copymap);
bool	is_open_long_line(char **copymap);
bool	is_up_bottom_wall(char *up, char *bottom, int index);
bool	is_open_inside(char **copymap);
bool	is_int(char *str, int converted_to_int);
int		count_verguls(char *str);

#endif
