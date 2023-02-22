NAME = libft.a
SRCS = $(shell find . -name '*.c')
CFLAGS = -Wextra -Werror -Wall
OBJ = $(SRCS:.c=.o)
AR = ar rcs 

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean: $(OBJ)
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)

re: fclean all

# $(NAME):
# 	make -C libft	
# 	make -C get_next_line
# 	make -C printf

# clean:
# 	make clean -C libft	
# 	make clean -C get_next_line
# 	make clean -C printf	

# fclean: 
# 	make fclean -C libft	
# 	make fclean -C get_next_line
# 	make fclean -C printf	

# re: fclean all