/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:25:22 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/03/01 22:46:05 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void input_position(t_root *root, char c)
{
	int i;
	int j;
	i = 0;
	while(root->map.map_array[i])
	{
		j = 0;
		while(root->map.map_array[i][j])
		{	
			if(root->map.map_array[i][j] == c)
			{
				if(c == EXIT)
				{
					root->exit.x = j;
					root->exit.y = i;
					root->exit.next_x = j;
					root->exit.next_y = i;
				}
				else
				{
					root->player.x = j;
					root->player.y = i;
					root->player.next_x = j;
					root->player.next_y = i;
				}
			}	
			j++;
		}	
		i++;
	}
}

void	walk_player(t_root *root, int x, int y)
{
	int	next_y;
	int	next_x;

	next_x = root->player.next_x;
	next_y = root->player.next_y;
	mlx_put_image_to_window(root->mlx.mlx_ptr, root->mlx.window_ptr, \
	root->path.player, next_x * 64, next_y * 64);
	mlx_put_image_to_window(root->mlx.mlx_ptr, root->mlx.window_ptr, \
	root->path.empty, x * 64, y * 64);
}

void	print_movements(t_root *root)
{
	char	*moves;

	moves = ft_itoa(root->player.moves);
	root->player.moves += 1;
	mlx_string_put(root->mlx.mlx_ptr, root->mlx.window_ptr, root->player.next_x \
	* SIZE + 28, root->player.next_y * SIZE + 15, 16777215, moves);
	free(moves);
}

int	key_hook(int key, t_root *root)
{
	if (key == ESC)
		destroy(root);
	change_player_position(root, key);
	return (0);
}