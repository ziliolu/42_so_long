/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:43:59 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/03/01 22:44:27 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_root	root;

	if (args_validation(argc, argv) != 1)
		return (-1);
	if (init_structs(&root, argv[1]) == 1)
	{
		game_init(root);
		mlx_loop(root.mlx.mlx_ptr);
	}
}
