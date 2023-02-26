#include "../includes/so_long.h"

int destroy(t_root *root)
{
	int i;

	i = 0;
	if(!root)
		return (-1);
	if (root->path.wall)
		mlx_destroy_image(root->mlx.mlx_ptr, root->path.wall);
	if (root->path.collectible)
		mlx_destroy_image(root->mlx.mlx_ptr, root->path.collectible);
	if (root->path.empty)
		mlx_destroy_image(root->mlx.mlx_ptr, root->path.empty);
	if (root->path.exit)
		mlx_destroy_image(root->mlx.mlx_ptr, root->path.exit);
	if (root->path.player)
		mlx_destroy_image(root->mlx.mlx_ptr, root->path.player);
	if(root->map.map_array)
		free_array(root->map.map_array, root);
	if(root->floodfill.map_array)
		free_array(root->floodfill.map_array, root);
	if(root->mlx.window_ptr)
		mlx_destroy_window(root->mlx.mlx_ptr, root->mlx.window_ptr);
	if(root->mlx.mlx_ptr)
	{
		mlx_destroy_display(root->mlx.mlx_ptr);
		free(root->mlx.mlx_ptr);
	}
	exit(1);
}

void free_array(char **array, t_root *root)
{
	int i;

	i = 0;
	while(i < (root->map.line))
	{
		free(array[i]);
		i++;
	}
	free(array);
}