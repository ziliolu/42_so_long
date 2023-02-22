#include "so_long.h"

// void print_tab(char **zone)
// {
// 	int i; 
// 	int j;
// 	i = 0;
// 	while(zone[i])
// 	{
// 		j = 0;
// 		while(zone[i][j])
// 		{
// 			printf("%c", zone[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}	
// }

typedef struct s_point
{
	int x;
	int y;
}				t_point;


void flood_fill(t_root *root, int i, int j)
{

	if (i < 0 || j < 0)
        return ;

	if(root->floodfill.map_array[i][j] == COLLECTIBLE )
		root->floodfill.collectibles++;
	if(root->floodfill.map_array[i][j] == EXIT )
		root->floodfill.exit++;
	if(root->floodfill.map_array[i][j] != EMPTY && root->floodfill.map_array[i][j] != COLLECTIBLE && root->floodfill.map_array[i][j] != EXIT)
		return ;
	
	root->floodfill.map_array[i][j] = 'F';
	flood_fill(root, i - 1, j);
	flood_fill(root, i + 1, j);
	flood_fill(root, i, j - 1);
	flood_fill(root, i, j + 1);
}

int flood_fill_problem(t_root *root)
{
	flood_fill(root, 1+ 1, 1);

	if(root->floodfill.collectibles == root->map.collectibles && \
	root->floodfill.exit == root->map.exit)
		return (-1);
	return (1);
}

