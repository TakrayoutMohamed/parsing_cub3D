NAME = cub3D
CC = cc
CFLAGS=  -Imlx 
LIBCUB = libcub.a
LIBFT = ./libft/libft.a
SRC= parse_data.c is_accepted_data.c ft_matrixcpy.c
SRC_MAIN = main.c
OBJ = $(SRC:.c=.o)
OBJ_MAIN = $(SRC_MAIN:.c=.o)
RM = rm -rf
HEADERS = ./libcub3d.h

all : $(NAME)

$(NAME): $(LIBCUB) $(OBJ_MAIN)
		$(CC) $(OBJ_MAIN) $(LIBCUB) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "the file $@ has been created from $<"

$(LIBCUB) : $(LIBFT)  $(OBJ)
		ar rc $@  $(OBJ) $(LIBFT)

$(LIBFT) : ./libft/Makefile
		@make -C ./libft all

clean:
		@$(RM) $(OBJ) $(OBJ_MAIN) $(LIBCUB)
		@make -C ./libft clean
		@echo "all the .o has been deleted successfully"

fclean: clean
		@$(RM) $(NAME)
		@make -C ./libft fclean
		@echo "the executable $(NAME) has been deleted"
	
re: fclean all

.PHONY : clean $(NAME) $(LIBCUB) $(LIBFT) all fclean bonus re