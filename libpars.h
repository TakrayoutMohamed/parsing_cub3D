#ifndef LIBPARS_H
# define LIBPARS_H
# include "./libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <string.h>
# include <mlx.h>

typedef struct	s_cub
{
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
} t_cub;
# include "./error_handler/liberror.h"

//here the functions that is going to be used in the parsing

t_cub	*parse_data(int argc, char **argv);
bool	is_accepted_data(char *argv);
char	**ft_matrixcpy(const char **map);

char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strtrim_free(char *s1, char *to_trim);
t_cub	*initializing_cub_struct(void);
bool	is_textures_floor_ceiles_setted(t_cub *cub);
bool	set_cub_data(t_cub *cub, char *map);
bool	set_textures_paths(t_cub *cub, char *line);
bool	set_map(t_cub *cub, char *str);
bool	has_double_new_line(char *str);
bool	check_map(char **map);

#endif
