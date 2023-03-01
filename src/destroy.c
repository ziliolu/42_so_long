/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:08:38 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/03/01 22:25:51 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	destroy(t_root *root)
{
	int	i;

	i = 0;
	if (!root)
		return (-1);
	destroy_images(root);
	if (root->map.map_array)
		free_array(root->map.map_array, root);
	if (root->floodfill.map_array)
		free_array(root->floodfill.map_array, root);
	if (root->mlx.window_ptr)
		mlx_destroy_window(root->mlx.mlx_ptr, root->mlx.window_ptr);
	if (root->mlx.mlx_ptr)
	{
		mlx_destroy_display(root->mlx.mlx_ptr);
		free(root->mlx.mlx_ptr);
	}
	exit(1);
}

void	destroy_images(t_root *root)
{
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
}

void	free_array(char **array, t_root *root)
{
	int	i;

	i = 0;
	while (i < (root->map.line))
	{
		free(array[i]);
		i++;
	}
	free(array);
}
