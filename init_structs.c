#include "so_long.h"

int init_structs(t_root *root, char *fd)
{
    ft_newmap_err(root);
	root->map = ft_newmap();
	root->floodfill = ft_newmap();
	root->mlx.mlx_ptr = mlx_init();
	root->path = ft_initialize_paths(root);
	root->player = ft_initialize_sprite();
	root->exit = ft_initialize_sprite();
	root->map.map_array = map_array_creation(open(fd, O_RDONLY));
	root->floodfill.map_array = map_array_creation(open(fd, O_RDONLY));
	map_fulfill(root, root->map.map_array);
	root->mlx.window_ptr = mlx_new_window(root->mlx.mlx_ptr, root->map.col * SIZE, root->map.line * SIZE, "so_long");
	return(0);
}