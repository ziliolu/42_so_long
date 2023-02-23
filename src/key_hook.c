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

void walk_player(t_root *root)
{	
	mlx_put_image_to_window(root->mlx.mlx_ptr, root->mlx.window_ptr, root->path.player, root->player.next_x * 64, root->player.next_y *64);
	mlx_put_image_to_window(root->mlx.mlx_ptr, root->mlx.window_ptr, root->path.empty, root->player.x * 64, root->player.y * 64 );
}

void print_movements(t_root *root)
{
	root->player.moves += 1;
	ft_printf("Number of movements: %d\n", root->player.moves);
}

void change_player_position(t_root *root, int direction)
{

	static int last_is_door;
	char next;
	root->player.x = root->player.next_x;
	root->player.y = root->player.next_y;

	if(direction == UP)
		root->player.next_y -= 1;
	else if(direction == DOWN)
		root->player.next_y += 1;
	else if(direction == RIGHT)
		root->player.next_x += 1;
	else if(direction == LEFT)
		root->player.next_x -= 1;
	
	next = root->map.map_array[root->player.next_y][root->player.next_x];
	if(next == COLLECTIBLE || next == EMPTY)
	{
		print_movements(root);
		if(last_is_door == 1)
		{
			mlx_put_image_to_window(root->mlx.mlx_ptr, root->mlx.window_ptr, root->path.player, root->player.next_x * SIZE, root->player.next_y * SIZE);
			mlx_put_image_to_window(root->mlx.mlx_ptr, root->mlx.window_ptr, root->path.exit, root->exit.x * SIZE, root->exit.y * SIZE);
			root->map.map_array[root->exit.y][root->exit.x] = EXIT;
			root->map.map_array[root->player.next_y][root->player.next_x] = PLAYER;
			last_is_door = 0;
		}
		else
		{
			walk_player(root);
			root->map.map_array[root->player.next_y][root->player.next_x] = PLAYER;
			root->map.map_array[root->player.y][root->player.x] = EMPTY;
		}
		if(next == COLLECTIBLE)
			root->player.n_collectibles += 1;
	}
	else if(next == EXIT)
	{
		if(root->player.n_collectibles != root->map.collectibles)
		{
			walk_player(root);
			print_movements(root);
			root->map.map_array[root->player.next_y][root->player.next_x] = PLAYER;
			root->map.map_array[root->player.y][root->player.x] = EMPTY;
			last_is_door = 1;
		}
		else
		{
			ft_putstr("Congratulations! You won this super hard game!\n");
			destroy(root); 
		}
	}
	else
	{
		root->player.next_x = root->player.x;
		root->player.next_y = root->player.y;
	}
}

int key_hook(int key, t_root *root)
{
	if(key == ESC)
		destroy(root);
	//ft_animate(root);
	change_player_position(root, key);
	return (0);
}