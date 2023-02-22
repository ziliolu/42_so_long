#include "so_long.h"

int ft_verify_extension(char *str, char *extension)
{
    int ext_len;
    int str_len;
    int i;

    ext_len = ft_strlen(extension);
    str_len = ft_strlen(str);
    i = 0;

    while(i < str_len - ext_len)
    {
        str++;
        i++;
    }
    if(ft_strncmp(str, extension, ext_len) == 0)
        return (0);
    return (-1);
}

t_map ft_newmap(void)
{
    t_map map;
    map.col = 0;
    map.line = 0;
    map.player = 0;
    map.collectibles = 0;
    map.exit = 0;
    map.wall = 0;
    map.empty = 0;
    return(map);
}

void ft_newmap_err(t_root *root)
{
    root->map_err.invalid_borders = 0;
    root->map_err.invalid_collectibles = 0;
    root->map_err.invalid_columns = 0;
    root->map_err.invalid_exit = 0;
    root->map_err.invalid_player = 0;
    root->map_err.invalid_character = 0;
    root->map_err.invalid_path = 0;
}

char **map_array_creation(int fd)
{
    char *line;
    char *map_array = ft_strdup("");
    char **map;
    while((line = get_next_line(fd)) != NULL)
    {
        char *temp = map_array;
        map_array = ft_strjoin(map_array, line);
        free(temp);
        free(line);
    }
    map = ft_split(map_array, '\n');
    free(map_array);

    if(!map)
        return (NULL);
    return (map);
}

int count_line(char **array)
{
    int i;

    i = 0;
    while(array[i] != NULL)
        i++;
    return (i);
}

/* verify the number of char of the first line and call function to verify others */
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

/* verify if all lines have the same number of chars */
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


int check_map (t_root *root)
{
    int problem;

    problem = 0;
    if(root->map.col <= 0 || (root->map.col == root->map.line))
    {
        root->map_err.invalid_columns = 1;
        problem++;
    }
    if (root->map.collectibles == 0)
    {
        root->map_err.invalid_collectibles = 1;
        problem++;
    }
    if (root->map.exit != 1)
    {
        root->map_err.invalid_exit = 1;
        problem++;
    }
    if (root->map.player != 1)
    {
        root->map_err.invalid_player = 1;
        problem++;
    }
    if(not_surrounded_by_walls(root))
    {
        root->map_err.invalid_borders = 1;
        problem++;
    }
    if(invalid_character(root->map.map_array))
    {
        root->map_err.invalid_character = 1;
        problem++;
    }
    if (flood_fill_problem(root) == 1)
    {
        root->map_err.invalid_path = 1;
        problem++;
    }

    ft_print_err(root);
    return (problem);
}

void err_message(char *str, t_root *root)
{
    ft_putstr("Error\n");
    ft_putstr(str);
    ft_putstr("\n");

   // printf("ignora %d\n", root->map_err.invalid_borders);
    destroy(root);
}

void ft_print_err(t_root *root)
{
    if(root->map_err.invalid_columns == 1)
        err_message("The map must be rectangular", root);
    if(root->map_err.invalid_borders == 1)
        err_message("The map must be surrounded by walls", root);
    if(root->map_err.invalid_exit == 1)
        err_message("Invalid number of exits!", root);
    if(root->map_err.invalid_collectibles == 1)
        err_message("Invalid number of collectibles", root);
    if(root->map_err.invalid_player == 1)
        err_message("Invalid number of players", root);
    if(root->map_err.invalid_character == 1)
        err_message("Invalid char present in the map", root);
    if(root->map_err.invalid_path == 1)
        err_message("Invalid path present in the map", root);
}

int map_fulfill(t_root *root, char **array)
{
    root->map.col = count_col(array);
    root->map.line = count_line(array);
    root->map.collectibles = times_it_appear(array, COLLECTIBLE);
    root->map.empty = times_it_appear(array, EMPTY);
    root->map.exit = times_it_appear(array, EXIT);
    root->map.player = times_it_appear(array, PLAYER);
    root->map.wall = times_it_appear(array, WALL);

    if(check_map(root) != 0)
        return (-1);
    return (1);
}


int args_validation(int argc, char **argv)
{
    int fd;

    fd  = open(argv[1], O_RDONLY);
    if (argc != 2)
        return (ft_putstr ("Error! Invalid number of arguments\n"));
    else if (ft_verify_extension(argv[1], ".ber") == -1)
        return (ft_putstr("Error! Invalid file extension, try <name-file>.ber\n"));
    else if (fd < 0)
        return (ft_putstr("Error! Invalid file .ber\n"));
    return (1);
}