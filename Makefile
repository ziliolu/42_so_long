NAME = so_long.a
EXECUTABLE = so_long
LIBFT_A = ./libft/libft.a
SRCS =	./main.c					\
		./src/args_validations.c	\
		./src/destroy.c				\
		./src/errors.c				\
		./src/game_init.c			\
		./src/init_structs.c		\
		./src/invalid_character.c	\
		./src/key_hook.c			\
		./src/map_creation.c		\
		./src/init_map_structs.c	\
		./src/map_validations.c		\
		./src/map_validations2.c	\
		./src/change_player_position.c

AR = ar rc
CFLAGS = -Wextra -Werror -Wall -g -O3
CC = cc
arg = 0
OBJ = $(SRCS:.c=.o)

all: $(NAME) $(LIBFT_A)
	@printf "\n%s\n\n" "⏳ Compiling the program...";
	$(CC) $(NAME) $(LIBFT_A) -g -L./mlx -lmlx -lXext -lX11 -lm -lbsd -o so_long 
	@printf "\n%s\n\n" "💻 Type 'make run arg=your-map.ber' or './so_long your-map.ber' to initialize the game!";

$(LIBFT_A):
	make -C libft

$(NAME): $(OBJ)
	make -C mlx
	$(AR) $(NAME) $(OBJ)

oclean: $(OBJ)
	@printf "\n%s\n\n" "🧹 Cleaning object files...";
	make clean -C libft
	rm -f $(OBJ)

clean: oclean
	@printf "\n%s\n\n" "🪠  Cleaning executable file...";
	rm -f $(EXECUTABLE)

fclean: clean
	@printf "\n%s\n\n" "🛁 Cleaning .a files...";
	rm -f $(NAME)
	rm -f $(LIBFT_A)

run: all oclean
	@printf "\n%s\n\n" "▶️  Initializing program...";
	./$(EXECUTABLE) $(arg)
	# @printf "\n"

re: fclean all

# '@' it's used to silent the printf function
# 'arg' it's used to receive terminal inputs