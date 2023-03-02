/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_character.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:58:36 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/03/02 17:06:45 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	invalid_character(char **array)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if ((array[i][j] != PLAYER) && (array[i][j] != EXIT) \
			&& (array[i][j] != COLLECTIBLE) && (array[i][j] != EMPTY) \
			&& (array[i][j] != WALL))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
