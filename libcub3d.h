#ifndef LIBCUB3D_H
# define LIBCUB3D_H
# include "./libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <string.h>
# include <mlx.h>
# define PI 3.14
#define RIGHT_ARROW  124
#define LEFT_ARROW  123
#define TOP_ARROW  126
#define BOTTOM_ARROW  125
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define PLAYER_X WIN_WIDTH/2
# define PLAYER_Y WIN_HEIGHT/2

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

typedef struct s_coorfinates
{
	double	x;
	double	y;
	double	z;
} t_coord;

typedef struct s_data {
	int		x_player;
	int		y_player;
	void	*mlx;
	void	*win;
	void	*img;
} t_data;



//here the functions that is going to be used in the parsing

t_cub	*parse_data(int argc, char **argv);
bool	is_accepted_data(char *argv);
char	**ft_matrixcpy(const char **map);

#endif
