/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:36:19 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/03/01 23:50:56 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	flood_fill(t_root *root, int i, int j)
{
	if (i < 0 || j < 0 || i > root->map.line - 1 || j > root->map.col - 1)
		return (false);
	else if (root->floodfill.map_array[i][j] == WALL)
		return (false);
	else if (root->floodfill.map_array[i][j] == COLLECTIBLE)
		root->floodfill.collectibles++;
	else if (root->floodfill.map_array[i][j] == EXIT)
		root->floodfill.exit++;
	root->floodfill.map_array[i][j] = WALL;
	flood_fill(root, i + 1, j);
	flood_fill(root, i - 1, j);
	flood_fill(root, i, j + 1);
	flood_fill(root, i, j - 1);
	return (root->map.collectibles == root->floodfill.collectibles \
	&& root->map.exit == root->floodfill.exit);
}

void	check_map(t_root *root)
{
	if (root->map.col <= 0 || (root->map.col == root->map.line))
		root->map_err.invalid_columns = 1;
	if (root->map.collectibles == 0)
		root->map_err.invalid_collectibles = 1;
	if (root->map.exit != 1)
		root->map_err.invalid_exit = 1;
	if (root->map.player != 1)
		root->map_err.invalid_player = 1;
	if (root->map_err.invalid_columns == 0)
	{
		if (not_surrounded_by_walls(root))
			root->map_err.invalid_borders = 1;
		if (!flood_fill(root, root->player.y, root->player.x))
			root->map_err.invalid_path = 1;
	}
	if (invalid_character(root->map.map_array))
		root->map_err.invalid_character = 1;
	ft_print_err(root);
}
