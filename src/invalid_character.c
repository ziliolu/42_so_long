/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_character.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:58:36 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/03/01 22:42:45 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	invalid_character(char **array)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = array[i][j];
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if ((c != PLAYER) && (c != EXIT) && \
			(c != COLLECTIBLE) && (c != EMPTY) && (c != WALL))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
