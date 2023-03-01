/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 23:16:55 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/03/01 23:27:55 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**map_array_creation(int fd)
{
	char	*line;
	char	*map_array;
	char	**map;
	char	*temp;

	map_array = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp = map_array;
		map_array = ft_strjoin(map_array, line);
		free(temp);
		free(line);
	}
	if (map_array[0] == '\0' || map_array[0] == '\n')
		return (NULL);
	map = ft_split(map_array, '\n');
	free(map_array);
	if (!map)
		return (NULL);
	return (map);
}

void	map_fulfill(t_root *root, char **array)
{
	root->map.col = count_col(array);
	root->map.line = count_line(array);
	root->map.collectibles = times_it_appear(array, COLLECTIBLE);
	root->map.empty = times_it_appear(array, EMPTY);
	root->map.exit = times_it_appear(array, EXIT);
	root->map.player = times_it_appear(array, PLAYER);
	root->map.wall = times_it_appear(array, WALL);
	input_player_position(root);
	check_map(root);
}
