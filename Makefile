NAME = so_long.a
EXECUTABLE = so_long
SRCS = main.c arg_validation.c destroy.c init_structs.c ft_initialize_paths.c invalid_character.c game_init.c key_hook.c flood_fill.c
LIBFT_A = ./libft/libft.a
AR = ar rc
CFLAGS = -Wextra -Werror -Wall -g 
CC = cc
arg = 0
OBJ = $(SRCS:.c=.o)


all: $(NAME)
	@printf "\n%s\n\n" "⏳ Compilando programa...";
	$(CC) $(NAME) $(LIBFT_A) -g -L./mlx -lmlx -lXext -lX11 -lm -lbsd -o so_long 
	@printf "\n%s\n\n" "💻 Type 'make run arg=your-map.ber' to initialize the game!";
	
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

oclean: $(OBJ)
	@printf "\n%s\n\n" "🧹 Cleaning object files...";
	make clean -C libft
	rm -f $(OBJ)

clean: oclean
	@printf "\n%s\n\n" "🪠  Cleaning executable file...";
	rm -f $(EXECUTABLE)

fclean: clean
	rm -f $(NAME)

run: all oclean
	@printf "\n%s\n\n" "▶️  Initializing program...";
	./$(EXECUTABLE) $(arg)
	@printf "\n"

re: fclean all

# '@' it's used to silent the printf function
# 'arg' it's used to receive terminal inputs