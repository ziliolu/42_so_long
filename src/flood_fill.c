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

