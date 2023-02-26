#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft/libft.h"
#include "../libft/printf/ft_printf.h"
#include "../libft/get_next_line/get_next_line.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../mlx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdbool.h>

# define SIZE 64
# define PLAYER 'P'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define EMPTY '0'
# define ESC 65307
# define UP 65362   // key "arrow up"
# define DOWN 65364 // key "arrow down"
# define RIGHT 65363 //key "right arrow"
# define LEFT 65361  //key "left arrow"

typedef struct s_point
{
	int x;
	int y;
}				t_point;

typedef struct s_mlx {
	
	void *mlx_ptr;
	void *window_ptr;
}				t_mlx;


typedef struct s_path
{
	void *wall;
	void *empty;
	void *collectible;
	void *player;
	void *exit;

}				t_path;

typedef struct s_sprite
{
	int x; 
	int y;
	int next_x;
	int next_y;
	int moves; 
	int n_collectibles;
}				t_sprite;



typedef struct s_map
{
	char **map_array;
	int line;
	int col;
	int player;
    int collectibles;
    int exit;
    int wall;
    int empty;
}			t_map;


typedef struct s_map_err
{
	int invalid_columns;
	int invalid_borders;
	int invalid_exit;
	int invalid_collectibles;
	int invalid_player;
	int invalid_character;
	int invalid_path;
	int empty_fd;
}				t_map_err;

typedef struct s_root
{
	t_map map;
	t_map floodfill;
	t_map_err map_err;
	t_mlx mlx;
	t_path path;
	t_sprite player;
	t_sprite exit;

}			t_root;

void err_message(char *str, int *error);
void ft_animate(t_root *root);
int args_validation(int argc, char **argv);
char **map_array_creation(int fd);
void map_fulfill(t_root *root, char **array);
int count_line(char **array);
void check_map (t_root *root);
t_map ft_initialize_map(void);
void ft_initialize_map_err(t_root *root);
int ft_verify_extension(char *str, char *extension);
int verify_other_cols(char **array, int i);
int count_col(char **array);
int times_it_appear(char **array, char c);
void ft_print_err(t_root *root);
int not_surrounded_by_walls(t_root *root);
int invalid_character(char **array);
t_path ft_initialize_paths(t_root *root);
void ft_initialize_mlx(t_root *root);
void game_init(t_root root);
void initial_image_render(t_root root);
void change_player_position(t_root *root, int direction);
int key_hook(int key, t_root *root);
t_sprite ft_initialize_sprite();
void input_player_position(t_root *root);
void print_tab(char **zone);
char **copy_tab(char **array);
int init_structs(t_root *root, char *fd);
int destroy(t_root *root);
void free_array(char **array, t_root *root);
void input_position(t_root *root, char c);
void print_movements(t_root *root);
void print_tab(char **zone);
#endif