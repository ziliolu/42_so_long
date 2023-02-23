#include "../includes/so_long.h"

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