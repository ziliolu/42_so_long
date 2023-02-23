#include "../includes/so_long.h"

static bool flood_fill(t_root *root, int i, int j)
{
    if(i < 0 || j < 0 || i > root->map.line - 1 || j > root->map.col - 1)
        return (false);
	else if (root->floodfill.map_array[i][j] == WALL)
		return (false);
	else if (root->floodfill.map_array[i][j] == COLLECTIBLE )
		root->floodfill.collectibles++;
	else if (root->floodfill.map_array[i][j] == EXIT )
		root->floodfill.exit++;

	root->floodfill.map_array[i][j] = WALL;
	flood_fill(root, i + 1, j);
	flood_fill(root, i - 1, j);
	flood_fill(root, i, j + 1);
	flood_fill(root, i, j - 1);
	return(root->map.collectibles == root->floodfill.collectibles && root->map.exit == root->floodfill.exit);
}



void check_map (t_root *root)
{
    if(root->map.col <= 0 || (root->map.col == root->map.line))
        root->map_err.invalid_columns = 1;
    if (root->map.collectibles == 0)
        root->map_err.invalid_collectibles = 1;
    if (root->map.exit != 1)
        root->map_err.invalid_exit = 1;
    if (root->map.player != 1)
        root->map_err.invalid_player = 1;
    if(root->map_err.invalid_columns == 0)
    {
        if(not_surrounded_by_walls(root))
            root->map_err.invalid_borders = 1;
        if (!flood_fill(root, root->player.y, root->player.x))
            root->map_err.invalid_path = 1;
    }
    if(invalid_character(root->map.map_array))
        root->map_err.invalid_character = 1;
    ft_print_err(root);
}


int count_line(char **array)
{
    int i;

    i = 0;
    while(array[i] != NULL)
        i++;
    return (i);
}

int count_col(char **array)
{
    int i;

    i = 0;
    while(array[0][i] != '\0')
        i++;
    
    if(verify_other_cols(array, i) == 1)
        return (i);
    return (0);
}

int verify_other_cols(char **array, int num_col)
{
    int i;
    int j;
 
    i = 0;
    while(array[i]!= NULL)
    {   
        j = 0;
        while(array[i][j] != '\0')
            j++;
        if (num_col != j)
            return (-1);
        i++;
    }
    return (1);
}

int times_it_appear(char **array, char c)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while(array[i] != NULL)
    {
        j = 0;
        while(array[i][j] != '\0')
        {
            if(array[i][j] == c)
                count++;
            j++;
        }
        i++;
    }
    return(count);
}

int not_surrounded_by_walls(t_root *root)
{
    char *first_line;
    char *last_line;

    int last_column;
    char **array;
    char wall;
    int i;
    int j;

    i = 0;
    j = 1;
    wall = '1';

    first_line = root->map.map_array[0];
    last_line = root->map.map_array[root->map.line - 1];
    last_column = root->map.col - 1;
    array = root->map.map_array;

    while(first_line[i] && last_line[i])
    {
        if(first_line[i] != wall || last_line[i] != wall)
            return(1);
        i++;
    }
    while(array[j])
    {
        if(array[j][0] != wall || array[j][last_column] != wall)
            return(1);
        j++;
    }
    return(0);
}





