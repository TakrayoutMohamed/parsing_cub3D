# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 21:21:25 by mohtakra          #+#    #+#              #
#    Updated: 2023/11/29 11:13:27 by mohtakra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS=  -Wall -Wextra -Werror
LIBPARS = libpars.a
LIBFT = ./libft/libft.a

SRC_MAIN = main.c
OBJ = $(SRC:.c=.o)
OBJ_MAIN = $(SRC_MAIN:.c=.o)
RM = rm -rf
ERRPATH=./error_handler/
HEADERS = ./libpars.h $(ERRPATH)liberror.h

SRC= parse_data.c is_accepted_extension.c ft_matrixcpy.c \
	 check_map.c ft_strjoin_free.c has_double_new_line.c \
	 set_map.c set_textures_paths.c set_cub_data.c is_textures_floor_ceiles_setted.c \
	 initializing_cub_struct.c \
	 has_accepted_chars.c has_player.c has_only_one_player.c is_top_wall.c is_bottom_wall.c\
	 is_right_left_wall.c is_open_long_line.c is_open_inside.c is_int.c\
	 clean_struct.c \
	 $(ERRPATH)print_error.c
all : $(NAME)

$(NAME): $(LIBPARS) $(OBJ_MAIN)
		$(CC) $(OBJ_MAIN) $(LIBPARS) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "the file $@ has been created from $<"

$(LIBPARS) : $(LIBFT)  $(OBJ)
		ar rc $@  $(OBJ) $(LIBFT)

$(LIBFT) : ./libft/libft.h
		@make -C ./libft all

clean:
		@$(RM) $(OBJ) $(OBJ_MAIN) $(LIBPARS)
		@make -C ./libft clean
		@echo "all the .o has been deleted successfully"

fclean: clean
		@$(RM) $(NAME)
		@make -C ./libft fclean
		@echo "the executable $(NAME) has been deleted"
	
re: fclean all

.PHONY : clean $(NAME) $(LIBPARS) $(LIBFT) all fclean bonus re