/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:34:18 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/03/01 22:34:19 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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