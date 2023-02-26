#include "../includes/so_long.h"

int init_structs(t_root *root, char *fd)
{
	root->map = ft_initialize_map();
	root->floodfill = ft_initialize_map();
	ft_initialize_mlx(root);
	root->mlx.mlx_ptr = mlx_init();
	root->path = ft_initialize_paths(root);
	root->player = ft_initialize_sprite();
	root->exit = ft_initialize_sprite();
    ft_initialize_map_err(root);
	if((root->map.map_array = map_array_creation(open(fd, O_RDONLY))) == NULL)
	{
		root->map_err.empty_fd = 1;
		ft_print_err(root);
		return(-1);
	}
	root->floodfill.map_array = map_array_creation(open(fd, O_RDONLY));
	map_fulfill(root, root->map.map_array);
	root->mlx.window_ptr = mlx_new_window(root->mlx.mlx_ptr, root->map.col * SIZE, root->map.line * SIZE, "so_long");
	return(1);
}

void ft_initialize_mlx(t_root *root)
{
	root->mlx.mlx_ptr = 0;
	root->mlx.window_ptr = 0;
}

t_map ft_initialize_map(void)
{
    t_map map;
    map.col = 0;
    map.line = 0;
    map.player = 0;
    map.collectibles = 0;
    map.exit = 0;
    map.wall = 0;
    map.empty = 0;
    return(map);
}

void ft_initialize_map_err(t_root *root)
{
    root->map_err.invalid_borders = 0;
    root->map_err.invalid_collectibles = 0;
    root->map_err.invalid_columns = 0;
    root->map_err.invalid_exit = 0;
    root->map_err.invalid_player = 0;
    root->map_err.invalid_character = 0;
    root->map_err.invalid_path = 0;
	root->map_err.empty_fd = 0;
}

t_sprite ft_initialize_sprite()
{
	t_sprite sprite;
	sprite.x = 0;
	sprite.y = 0;
	sprite.moves = 1;
	sprite.n_collectibles = 0;
	return (sprite);
}

t_path ft_initialize_paths(t_root *root)
{
    t_path path;
	int h;
	int w;
    path.wall = mlx_xpm_file_to_image(root->mlx.mlx_ptr, "./textures/wall.xpm", &w, &h);
	path.empty = mlx_xpm_file_to_image(root->mlx.mlx_ptr, "./textures/empty.xpm", &w, &h);
	path.collectible = mlx_xpm_file_to_image(root->mlx.mlx_ptr, "./textures/collectible.xpm", &w, &h);
	path.exit = mlx_xpm_file_to_image(root->mlx.mlx_ptr, "./textures/exit.xpm", &w, &h);
	path.player = mlx_xpm_file_to_image(root->mlx.mlx_ptr, "./textures/player0.xpm", &w, &h);
	return (path);
}
