#include "../includes/so_long.h"

char **map_array_creation(int fd)
{
    char *line;
    char *map_array = ft_strdup("");
    char **map;
    while((line = get_next_line(fd))!= NULL)
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

void map_fulfill(t_root *root, char **array)
{
    root->map.col = count_col(array);
    root->map.line = count_line(array);
    root->map.collectibles = times_it_appear(array, COLLECTIBLE);
    root->map.empty = times_it_appear(array, EMPTY);
    root->map.exit = times_it_appear(array, EXIT);
    root->map.player = times_it_appear(array, PLAYER);
    root->map.wall = times_it_appear(array, WALL);
    input_position(root, PLAYER);
    check_map(root);
}
