/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_player_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:13:11 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/03/01 22:45:35 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	change_player_position(t_root *root, int direction)
{
	static int	last_is_door;
	char		next;

	root->player.x = root->player.next_x;
	root->player.y = root->player.next_y;
	if (direction == UP)
		root->player.next_y -= 1;
	else if (direction == DOWN)
		root->player.next_y += 1;
	else if (direction == RIGHT)
		root->player.next_x += 1;
	else if (direction == LEFT)
		root->player.next_x -= 1;
	next = root->map.map_array[root->player.next_y][root->player.next_x];
	if (next == COLLECTIBLE || next == EMPTY)
		next_collect_or_empty(root, &last_is_door, next);
	else if (next == EXIT)
		next_is_exit(root, &last_is_door);
	else
	{
		root->player.next_x = root->player.x;
		root->player.next_y = root->player.y;
	}
}
void	next_collect_or_empty(t_root *root, int *last_is_door, char next)
{
	int	next_y;
	int	next_x;

	next_x = root->player.next_x;
	next_y = root->player.next_y;
	if (*last_is_door == 1)
	{
		mlx_put_image_to_window(root->mlx.mlx_ptr, root->mlx.window_ptr, \
		root->path.player, next_x * SIZE, next_y * SIZE);
		mlx_put_image_to_window(root->mlx.mlx_ptr, root->mlx.window_ptr, \
		root->path.exit, root->exit.x * SIZE, root->exit.y * SIZE);
		root->map.map_array[root->exit.y][root->exit.x] = EXIT;
		root->map.map_array[root->player.next_y][root->player.next_x] = PLAYER;
		*last_is_door = 0;
	}
	else
	{
		walk_player(root, root->player.x, root->player.y);
		root->map.map_array[root->player.next_y][root->player.next_x] = PLAYER;
		root->map.map_array[root->player.y][root->player.x] = EMPTY;
	}
	if (next == COLLECTIBLE)
		root->player.n_collectibles += 1;
	print_movements(root);
}

void	next_is_exit(t_root *root, int *last_is_door)
{
	if (root->player.n_collectibles != root->map.collectibles)
	{
		walk_player(root, root->player.x, root->player.y);
		root->map.map_array[root->player.next_y][root->player.next_x] = PLAYER;
		root->map.map_array[root->player.y][root->player.x] = EMPTY;
		print_movements(root);
		*last_is_door = 1;
	}
	else
	{
		ft_putstr("Congratulations! You won this super hard game!\n");
		destroy(root);
	}
}