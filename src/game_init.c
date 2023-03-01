/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:15:58 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/03/01 22:59:55 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_init(t_root root)
{
	initial_image_render(&root);
	input_exit_position(&root);
	mlx_hook(root.mlx.window_ptr, KeyPress, KeyPressMask, &key_hook, &root);
	mlx_hook(root.mlx.window_ptr, 17, (1L << 17), &destroy, &root);
}

void	ft_put_image_to_window(t_root *root, int column, int line)
{
	int	i;
	int	j;

	i = root->counter.i;
	j = root->counter.j;
	if (root->map.map_array[i][j] == WALL)
		mlx_put_image_to_window(root->mlx.mlx_ptr, root->mlx.window_ptr, \
		root->path.wall, column, line);
	else if (root->map.map_array[i][j] == EMPTY)
		mlx_put_image_to_window(root->mlx.mlx_ptr, root->mlx.window_ptr, \
		root->path.empty, column, line);
	else if (root->map.map_array[i][j] == COLLECTIBLE)
		mlx_put_image_to_window(root->mlx.mlx_ptr, root->mlx.window_ptr, \
		root->path.collectible, column, line);
	else if (root->map.map_array[i][j] == PLAYER)
		mlx_put_image_to_window(root->mlx.mlx_ptr, root->mlx.window_ptr, \
		root->path.player, column, line);
	else if (root->map.map_array[i][j] == EXIT)
		mlx_put_image_to_window(root->mlx.mlx_ptr, root->mlx.window_ptr, \
		root->path.exit, column, line);
}

void	initial_image_render(t_root *root)
{
	int	column;
	int	line;

	line = 0;
	root->counter.i = 0;
	while (root->map.map_array[root->counter.i])
	{
		root->counter.j = 0;
		column = 0;
		while (root->map.map_array[root->counter.i][root->counter.j])
		{
			ft_put_image_to_window(root, column, line);
			root->counter.j++;
			column += SIZE;
		}
		line += SIZE;
		root->counter.i++;
	}
}
