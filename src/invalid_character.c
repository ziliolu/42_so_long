#include "../includes/so_long.h"

int invalid_character(char **array)
{
    int i;
    int j;

    i = 0;	
	while(array[i])
	{
		j = 0;
		while(array[i][j])
		{
			if((array[i][j] != PLAYER) && (array[i][j] != EXIT) && (array[i][j] != COLLECTIBLE) && (array[i][j] != EMPTY) && (array[i][j] != WALL))
				return (1);
			j++;		
		}
		i++;
	}
	return (0);
}
