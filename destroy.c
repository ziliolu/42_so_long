#include "so_long.h"

int destroy(t_root *root)
{
	free_array(root->map.map_array, root);
	free_array(root->floodfill.map_array, root);
	mlx_destroy_window(root->mlx.mlx_ptr, root->mlx.window_ptr);
	return(0);
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