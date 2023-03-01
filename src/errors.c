/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:13:16 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/03/01 22:25:12 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	err_message(char *str, int *error)
{
	ft_putstr("Error: ");
	ft_putstr(str);
	ft_putstr("\n");
	*error = *error + 1;
}

void	ft_print_err(t_root *root)
{
	int	error;

	error = 0;
	if (root->map_err.empty_fd == 1)
		err_message("Empty file or map with empty line in middle", &error);
	if (root->map_err.invalid_columns == 1)
		err_message("The map must be rectangular", &error);
	if (root->map_err.invalid_borders == 1)
		err_message("The map must be surrounded by walls", &error);
	if (root->map_err.invalid_exit == 1)
		err_message("Invalid number of exits", &error);
	if (root->map_err.invalid_collectibles == 1)
		err_message("Invalid number of collectibles", &error);
	if (root->map_err.invalid_player == 1)
		err_message("Invalid number of players", &error);
	if (root->map_err.invalid_character == 1)
		err_message("Invalid char present in the map", &error);
	if (root->map_err.invalid_path == 1)
		err_message("Invalid path present in the map", &error);
	if (error != 0 && root->map_err.empty_fd != 1)
		destroy(root);
}
