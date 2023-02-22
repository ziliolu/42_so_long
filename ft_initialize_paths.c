#include "so_long.h"

t_path ft_initialize_paths(t_root *root)
{
    t_path path;
	int h;
	int w;
    path.wall = mlx_xpm_file_to_image(root->mlx.mlx_ptr, "./img/wall.xpm", &w, &h);
	path.empty = mlx_xpm_file_to_image(root->mlx.mlx_ptr, "./img/empty.xpm", &w, &h);
	path.collectible = mlx_xpm_file_to_image(root->mlx.mlx_ptr, "./img/collectible.xpm", &w, &h);
	path.player = mlx_xpm_file_to_image(root->mlx.mlx_ptr, "./img/player.xpm", &w, &h);
	path.exit = mlx_xpm_file_to_image(root->mlx.mlx_ptr, "./img/exit.xpm", &w, &h);
	path.winner = mlx_xpm_file_to_image(root->mlx.mlx_ptr, "./img/winner.xpm", &w, &h);
	return (path);
}

t_sprite ft_initialize_sprite()
{
	t_sprite sprite;
	sprite.x = 0;
	sprite.y = 0;
	sprite.moves = 0;
	sprite.n_collectibles = 0;
	return (sprite);
}