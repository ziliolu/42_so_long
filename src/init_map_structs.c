/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_structs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:57:36 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/03/01 22:41:52 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	ft_initialize_map(void)
{
	t_map	map;

	map.col = 0;
	map.line = 0;
	map.player = 0;
	map.collectibles = 0;
	map.exit = 0;
	map.wall = 0;
	map.empty = 0;
	return (map);
}

void	ft_initialize_map_err(t_root *root)
{
	root->map_err.invalid_borders = 0;
	root->map_err.invalid_collectibles = 0;
	root->map_err.invalid_columns = 0;
	root->map_err.invalid_exit = 0;
	root->map_err.invalid_player = 0;
	root->map_err.invalid_character = 0;
	root->map_err.invalid_path = 0;
	root->map_err.empty_fd = 0;
}
