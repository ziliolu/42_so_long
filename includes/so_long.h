/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:53:52 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/03/02 16:55:21 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>

# define SIZE 64
# define PLAYER 'P'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define EMPTY '0'
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define RIGHT 65363 
# define LEFT 65361  

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*window_ptr;
}				t_mlx;

typedef struct s_path
{
	void	*wall;
	void	*empty;
	void	*collectible;
	void	*player;
	void	*exit;
}				t_path;

typedef struct s_sprite
{
	int	x;
	int	y;
	int	next_x;
	int	next_y;
	int	moves;
	int	n_collectibles;
}				t_sprite;

typedef struct s_counter
{
	int	i;
	int	j;
}				t_counter;

typedef struct s_map
{
	char	**map_array;
	int		line;
	int		col;
	int		player;
	int		collectibles;
	int		exit;
	int		wall;
	int		empty;
}			t_map;

typedef struct s_map_err
{
	int	invalid_columns;
	int	invalid_borders;
	int	invalid_exit;
	int	invalid_collectibles;
	int	invalid_player;
	int	invalid_character;
	int	invalid_path;
	int	empty_fd;
}				t_map_err;

typedef struct s_root
{
	t_map		map;
	t_map		floodfill;
	t_map_err	map_err;
	t_mlx		mlx;
	t_path		path;
	t_sprite	player;
	t_sprite	exit;
	t_counter	counter;

}			t_root;

// ====== ARGS VALIDATION ======
int			args_validation(int argc, char **argv);
int			ft_verify_extension(char *str, char *extension);

// ====== CHANGE PLAYER POSITION ======
void		change_player_position(t_root *root, int direction);
void		next_collect_or_empty(t_root *root, int *last_is_door, char next);
void		next_is_exit(t_root *root, int *last_is_door);

// ====== DESTROY ======
int			destroy(t_root *root);
void		destroy_images(t_root *root);
void		free_array(char **array, t_root *root);

// ====== ERRORS ======
void		err_message(char *str, int *error);
void		ft_print_err(t_root *root);

// ====== GAME INIT ======
void		game_init(t_root root);
void		ft_put_image_to_window(t_root *root, int column, int line);
void		initial_image_render(t_root *root);

// ====== INIT MAP STRUCTS ======
t_map		ft_initialize_map(void);
void		ft_initialize_map_err(t_root *root);

// ====== INIT STRUCTS ======
int			init_structs(t_root *root, char *fd);
void		ft_initialize_mlx(t_root *root);
t_sprite	ft_initialize_sprite(void);
t_path		ft_initialize_paths(t_root *root);
void		ft_initialize_counter(t_root *root);

// ====== INVALID CHARACTER ======
int			invalid_character(char **array);

// ====== KEY HOOK ======
void		input_player_position(t_root *root);
void		input_exit_position(t_root *root);
void		walk_player(t_root *root, int x, int y);
void		print_movements(t_root *root);
int			key_hook(int key, t_root *root);

// ====== MAP CREATION ======
char		**map_array_creation(int fd);
int			verify_new_line(char *array);
void		map_fulfill(t_root *root, char **array);

// ====== MAP VALIDATIONS ======
void		check_map(t_root *root);
int			count_line(char **array);
int			count_col(char **array);
int			verify_other_cols(char **array, int num_col);
int			times_it_appear(char **array, char c);
int			not_surrounded_by_walls(t_root *root);

#endif