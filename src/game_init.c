#include "../includes/so_long.h"

void game_init(t_root root)
{
	initial_image_render(root);
	input_position(&root, EXIT);
	mlx_hook(root.mlx.window_ptr, KeyPress, KeyPressMask, &key_hook, &root);
}

void initial_image_render(t_root root)
{
	int i;
	int j;
	int column;
	int line;

	i = 0;
	line = 0;
	while(root.map.map_array[i])
	{
		j = 0;
		column = 0;
		while(root.map.map_array[i][j])
		{
			if(root.map.map_array[i][j] == WALL)
				mlx_put_image_to_window(root.mlx.mlx_ptr, root.mlx.window_ptr, root.path.wall, column, line);
			else if(root.map.map_array[i][j] == EMPTY)
				mlx_put_image_to_window(root.mlx.mlx_ptr, root.mlx.window_ptr, root.path.empty, column, line);
			else if(root.map.map_array[i][j] == COLLECTIBLE)
				mlx_put_image_to_window(root.mlx.mlx_ptr, root.mlx.window_ptr, root.path.collectible, column, line);
			else if(root.map.map_array[i][j] == PLAYER)
				mlx_put_image_to_window(root.mlx.mlx_ptr, root.mlx.window_ptr, root.path.player, column, line);
			else if(root.map.map_array[i][j] == EXIT)
				mlx_put_image_to_window(root.mlx.mlx_ptr, root.mlx.window_ptr, root.path.exit, column, line);
			j++;
			column += SIZE;
		}
		line += SIZE;
		i++;
	}
}
