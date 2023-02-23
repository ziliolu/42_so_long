#include "../includes/so_long.h"
#include <stdbool.h>

void print_tab(char **zone)
{
	int i; 
	int j;
	i = 0;
	while(zone[i])
	{
		j = 0;
		while(zone[i][j])
		{
			printf("%c", zone[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}	
}

// static bool flood_fill(t_root *root, int i, int j)
// {

// 	if(root->floodfill.map_array[i][j] == WALL)
// 		return (false);

// 	else if(root->floodfill.map_array[i][j] == COLLECTIBLE )
// 		root->floodfill.collectibles++;
// 	else if(root->floodfill.map_array[i][j] == EXIT )
// 		root->floodfill.exit++;

// 	root->floodfill.map_array[i][j] = WALL;
// 	flood_fill(root, i - 1, j);
// 	flood_fill(root, i + 1, j);
// 	flood_fill(root, i, j - 1);
// 	flood_fill(root, i, j + 1);
// 	return(root->map.collectibles == root->floodfill.collectibles && root->map.exit == root->floodfill.exit);
// }



